#include "List.h"

List::List(int list_size) {
    if (list_size < 0) throw length_error("\nList size is negative.\n\n");

    Student* list = new Student[list_size];

    for (int i = 0; i < list_size; i++) {
        list[i].full_name->set_name(to_string(i));
    }

    this->size = list_size;
    this->list = list;
}

List::List(List& unit) {
    this->size = unit.length();
    this->list = new Student[unit.length()];
    for (int i = 0; i < unit.length(); i++) {
        this->list[i] = unit.list[i];
    }
}

List::~List() {
    this->clear();
}

int List::length() {
    return this->size;
}

int List::append() {
    (*this)++;

    cout << "\nPlease input student data:\n";

    if (this->list[this->length() - 1].input_data() == 0) {
        cout << "\nStudent added to list.\n";
        return 0;
    }
    else {
        cout << "\nSomething went wrong.\n";
        return -1;
    }
}

int List::remove(int index) {
    Student* new_list = new Student[this->length() - 1];
    int counter = 0;

    if (this->length() < 1) throw length_error("\nList is empty.\n\n");

    if (index < 0) return -1;
    if (index > this->length() - 1) return -1;

    for (int i = 0; i < this->length(); i++) {
        if (i != index) {
            new_list[counter] = this->list[i];
            counter++;
        }
    }

    delete[] this->list;

    this->list = new_list;
    this->size--;

    return 0;
}

int List::clear() {
    if (this->size > 0 && this->list != NULL) {
        delete[] this->list;
        this->size = 0;
        return 0;
    }
    else {
        return -1;
    }
}

void List::print() {
    if (this->length() > 0) {
        cout << "\nList of students:\n\n";
        for (int i = 0; i < this->length(); i++) {
            cout << "#" << i + 1;
            this->list[i].print();
            cout << endl;
        }
        cout << "\nEnd of list.\n\n";
    }
    else
        throw length_error("\nList is empty.\n\n");
}

void List::NonVirtualPrint() {
    this->print();
}

List& List::operator++ () {
    Student* new_list = new Student[this->length() + 1];

    for (int i = 0; i < this->length(); i++) {
        new_list[i] = this->list[i];
    }

    this->list = new_list;
    this->size++;

    return *this;
}

List& List::operator++ (int) {
    List temp(*this);
    ++*this;
    return temp;
}


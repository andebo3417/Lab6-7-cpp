#include "Contacts.h"
#define EASY_INPUT


Contacts::Contacts(string student_number, string parent_number) {
    set_student_number(student_number);
    set_parent_number(parent_number);
}

Contacts::Contacts(Contacts& unit) {
    this->student.set_number(unit.get_student_number());
    this->parent.set_number(unit.get_parent_number());
}

Contacts::~Contacts() {
#ifdef DEBUG
    cout << "\n_contacts Destructor is called.\n";
#endif
}

int Contacts::set_student_number(string number) {
    if (this->student.set_number(number) == 0) return 0;
    return -1;
}

int Contacts::set_parent_number(string number) {
    if (this->parent.set_number(number) == 0) return 0;
    return -1;
}

string Contacts::get_student_number() {
    return this->student.get_number();
}

string Contacts::get_parent_number() {
    return this->parent.get_number();
}

int Contacts::input_contacts() {
    bool flag = false;
    string temp;

    cout << "\nInput contacts of a student.\n\n";

    do {
        flag = true;
        cout << "Input student's phone number: \n>>";
        cin >> temp;

#ifdef EASY_INPUT
        if (temp == "12") {
            temp = "+79090809999";
        }
#endif // EASY_INPUT


        if (this->set_student_number(temp) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);

    do {
        flag = true;
        cout << "Input student's parent phone number: \n>>";
        cin >> temp;

#ifdef EASY_INPUT
        if (temp == "12") {
            temp = "+79090807777";
        }
#endif // EASY_INPUT


        if (this->set_parent_number(temp) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);


    return 0;
}
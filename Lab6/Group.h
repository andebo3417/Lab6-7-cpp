#pragma once

#include "List.h"
#include "Teacher.h"
#include "GroupName.h"

template <typename T>
class Group : public List
{
public:
	GroupName<T>* name;

	Teacher teacher;

	Group(T name, Teacher teacher) : List(0) {
		this->name = new GroupName<T>(name);
		this->teacher = teacher;
	}

	Group(List* list, T name, Teacher teacher) : List(0) {
		this->name = new GroupName<T>(name);
		this->teacher = teacher;
		*this = *list;
	};

	using List::append;
	int append(Student unit) {
		(*this)++;

		this->list[this->length() - 1] = unit;

		return 0;
	};

	int set_name(T name) {
		if (name.length() > 0) {
			this->name->setName(name);
			return 0;
		}
		else return -1;
	};

	T get_name() {
		return this->name->getName();
	};

	void print() override {
		if (this->length() > 0) {
			cout << "\nGroup " << this->get_name() << ":\n\n";
			cout << "Teacher:\n";
			this->teacher.print();
			cout << "\nList of students:\n\n";
			for (int i = 0; i < this->size; i++) {
				cout << "#" << i + 1;
				this->list[i].print();
				cout << endl;
			}
			cout << "\nEnd of list.\n\n";
		}
		else
			throw length_error("\nList is empty.\n\n");
	};

	Group operator=(List unit) {
		this->size = unit.length();
		this->list = new Student[this->size];
		for (int i = 0; i < this->size; i++) {
			this->list[i] = unit.list[i];
		}
		return *this;
	};
};


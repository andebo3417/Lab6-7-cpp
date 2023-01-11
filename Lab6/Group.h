#pragma once

#include "List.h"
#include "Teacher.h"
#include "GroupName.h"

template <typename T>
class Group : public List 
{
public:
	T name;

	Teacher teacher;

	Group(T name, Teacher teacher) : List(0) {
		this->name = name;
		this->teacher = teacher;
	}

	Group(List* list, T name, Teacher teacher) : List(0) {
		this->name = name;
		this->teacher = teacher;
		*this = *list;
	}

	using List::append;
	void append(Student unit) {
		(*this)++;

		this->list[this->length() - 1] = unit;
	}

	int set_name(T name) {
		if (name.length() > 0) {
			this->name = name;
			return 0;
		}
		else return -1;
	}

	T get_name() {
		return this->name;
	}

	void print() {
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
	}

	Group operator=(List unit) {
		this->size = unit.length();
		this->list = new Student[this->size];
		for (int i = 0; i < this->size; i++) {
			this->list[i] = unit.list[i];
		}
		return *this;
	}
};


//#include "Group.h"
//
//
//template <typename T>
//Group<typename T>::Group(List* list, T name, Teacher teacher) {
//	this->name = new GroupName<T>(name);
//	this->teacher = teacher;
//	*this = *list;
//}
//
//template <typename T>
//int Group<typename T>::set_name(T name) {
//	if (name.length() > 0) {
//		this->name = name;
//		return 0;
//	}
//	else return -1;
//}
//
//template <typename T>
//string Group<typename T>::get_name() {
//	return this->name->getName();
//}
//
//template <typename T>
//void Group<typename T>::print() {
//	if (this->length() > 0) {
//		cout << "\nGroup " << this->get_name() << ":\n\n";
//		cout << "Teacher:\n";
//		this->teacher.print();
//		cout << "\nList of students:\n\n";
//		for (int i = 0; i < this->length(); i++) {
//			cout << "#" << i + 1;
//			this->list[i].print();
//			cout << endl;
//		}
//		cout << "\nEnd of list.\n\n";
//	}
//	else
//		throw length_error("\nList is empty.\n\n");
//}
//
//template <typename T>
//int Group<typename T>::append(Student unit) {
//	(*this)++;
//
//	this->list[this->length() - 1] = unit;
//
//	return 0;
//}
//
//template <typename T>
//Group<typename T> Group<typename T>::operator=(List unit) {
//	this->size = unit.length();
//	this->list = new Student[this->size];
//	for (int i = 0; i < this->size; i++) {
//		this->list[i] = unit.list[i];
//	}
//	return *this;
//}
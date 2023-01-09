#include "Phone_number.h"

bool Phone_number::is_number(int c) {
	if (c >= '0' && c <= '9') return true;
	else return false;
}

Phone_number::Phone_number() {
	number = "N/A";
}

Phone_number::Phone_number(string number) {
	set_number(number);
}

int Phone_number::set_number(string number) {
	if (number == "N/A") this->number = number;
	if (check_number(number) == true) {
		this->number = number;
		return 0;
	}
	else return -1;
}

string Phone_number::get_number() {
	return this->number;
}

bool Phone_number::check_number(string number) {
	if (number.length() != 12) return false;
	if (number[0] != '+') return false;
	for (int i = 1; i < 11; i++)
		if (number[i] < '0' || number[i] > '9') return false;
	return true;
}
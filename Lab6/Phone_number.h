#pragma once

#include <iostream>
#include <string>

using namespace std;

class Phone_number
{
private:
	string number;

	bool is_number(int c);

public:
	Phone_number();

	Phone_number(string number);

	int set_number(string number);

	string get_number();

	static bool check_number(string number);
};


#pragma once

#include "Full_name.h"

#include <iostream>
#include <string>

using namespace std;

class Person_data
{
private:
	string gender;
public:
	Full_name* full_name;

	virtual int input_data() = 0;

	virtual int print() = 0;

	int input_gender();

	int set_gender(string gender);

	int set_gender(bool);

	string get_gender();

	~Person_data();
};


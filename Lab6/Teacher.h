#pragma once

#include "Person_data.h"

#include <iostream>
#include <string>

using namespace std;

class Teacher : public Person_data
{
private:
	string mail;
public:
    Teacher(Full_name name, string gender, string mail);

    Teacher(Full_name name);

    Teacher();

    Teacher(Teacher& unit);

    int input_mail();

    int input_data() override;

    int print() override;

    int set_mail(string mail);

    string get_mail();

    Teacher& operator= (Teacher& unit);

};
#pragma once

#include <iostream>
#include <string>
#include "Phone_number.h"

using namespace std;

class Contacts
{
private:
    Phone_number student;
    Phone_number parent;

public:

    Contacts(string student_number = "N/A", string parent_number = "N/A");

    Contacts(Contacts& unit);

    ~Contacts();

    int set_student_number(string number);

    int set_parent_number(string number);

    string get_student_number();

    string get_parent_number();

    int input_contacts();
};


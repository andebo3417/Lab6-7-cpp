#pragma once

#include <iostream>
#include <string>

using namespace std;

class Full_name
{
private:
    string name;
    string surname;
    string fathername;
public:

    Full_name(string name = "N/A", string surname = "N/A", string fathername = "N/A");

    Full_name(Full_name& unit);

    ~Full_name();

    int set_name(string name);

    int set_surname(string surname);

    int set_fathername(string fathername);

    string get_name();

    string get_surname();

    string get_fathername();

    string get_full_name();

    int input_full_name();
};


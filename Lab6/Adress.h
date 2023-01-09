#pragma once

#include <iostream>
#include <string>

using namespace std;

class Adress
{
private:
    string city;
    string street;
    int house_number;
    int flat_number;

public:

    Adress(string city = "N/A", string street = "N/A", int house_humber = 1, int flat_number = 1);

    Adress(Adress& unit);

    ~Adress();

    int set_city(string city);

    int set_street(string street);

    int set_house_number(int house_number);

    int set_flat_number(int flat_number);

    string get_city();

    string get_street();

    int get_house_number();

    int get_flat_number();

    string get_full_adress();

    int input_adress();
};


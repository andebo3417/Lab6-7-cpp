#include "Adress.h"
#define DEBUG1

Adress::Adress(string city, string street, int house_humber, int flat_number) {
    set_city(city);
    set_street(street);
    set_house_number(house_humber);
    set_flat_number(flat_number);
}

Adress::Adress(Adress& unit) {
    this->set_city(unit.get_city());
    this->set_street(unit.get_street());
    this->set_house_number(unit.get_house_number());
    this->set_flat_number(unit.get_house_number());
}

Adress::~Adress() {
#ifdef DEBUG
    cout << "\n_adress Destructor is called\n";
#endif // SHOW_DESTR
}

int Adress::set_city(string city) {
    if (city.length() != 0) this->city = city;
    else {
        return -1;
    }
    return 0;
}

int Adress::set_street(string street) {
    if (street.length() != 0) this->street = street;
    else {
        return -1;
    }
    return 0;
}

int Adress::set_house_number(int house_number) {
    if (house_number > 0) this->house_number = house_number;
    else {
        return -1;
    }
    return 0;
}

int Adress::set_flat_number(int flat_number) {
    if (flat_number > 0) this->flat_number = flat_number;
    else {
        return -1;
    }
    return 0;
}

string Adress::get_city() {
    return this->city;
}

string Adress::get_street() {
    return this->street;
}

int Adress::get_house_number() {
    return this->house_number;
}

int Adress::get_flat_number() {
    return this->flat_number;
}

string Adress::get_full_adress() {
    return this->city + ", " + this->street + " " + to_string(this->house_number) + ", " + to_string(this->flat_number);
}

int Adress::input_adress() {
    bool flag = true;
    string input;

    cout << "\nInput adress of a student.\n\n";
    do {
        flag = true;
        cout << "Input city: \n>>";
        cin >> input;
        if (this->set_city(input) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);


    do {
        flag = true;
        cout << "\nInput street: \n>>";
        cin >> input;
        if (this->set_street(input) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);


    do {
        flag = true;
        cout << "\nInput house number: \n>>";
        cin >> input;
        try {
            this->set_house_number(stoi(input));
        }
        catch (invalid_argument ex) {
            cout << "\nIncorrect input.\n\n";
            flag = false;
        }
        catch (out_of_range ex) {
            cout << "\nNumber is too big or too small.\n\n";
            flag = false;
        }
    } while (flag == false);


    do {
        flag = true;
        cout << "\nInput flat number: \n>>";
        cin >> input;
        try {
            this->set_flat_number(stoi(input));
        }
        catch (invalid_argument ex) {
            cout << "\nIncorrect input.\n\n";
            flag = false;
        }
        catch (out_of_range ex) {
            cout << "\nNumber is too big or too small.\n\n";
            flag = false;
        }
    } while (flag == false);
    return 0;
}

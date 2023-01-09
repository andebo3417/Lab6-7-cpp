#include "Full_name.h"
#define DEBUG1

Full_name::Full_name(string name, string surname, string fathername) {
    set_name(name);
    set_surname(surname);
    set_fathername(fathername);
}

Full_name::Full_name(Full_name& unit) {
    this->set_name(unit.get_name());
    this->set_surname(unit.get_surname());
    this->set_fathername(unit.get_fathername());
}

Full_name::~Full_name() {
#ifdef DEBUG
    cout << "\n_full_name Destructor is called.\n";
#endif // SHOW_DESTR
}

int Full_name::set_name(string name) {
    if (name.length() > 0) this->name = name;
    else {
        return -1;
    }
    return 0;
}

int Full_name::set_surname(string surname) {
    if (surname.length() > 0) this->surname = surname;
    else {
        return -1;
    }
    return 0;
}

int Full_name::set_fathername(string fathername) {
    if (fathername.length() > 0) this->fathername = fathername;
    else {
        return -1;
    }
    return 0;
}

string Full_name::get_name() {
    return this->name;
}

string Full_name::get_surname() {
    return this->surname;
}

string Full_name::get_fathername() {
    return this->fathername;
}

string Full_name::get_full_name() {
    return  this->surname + " " + this->name + " " + this->fathername;
}

int Full_name::input_full_name() {
    bool flag = false;
    string input;

    do {
        flag = true;
        cout << "\nInput name: \n>>";
        cin >> input;
        if (this->set_name(input) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);

    do {
        flag = true;
        cout << "\nInput surname: \n>>";
        cin >> input;
        if (this->set_surname(input) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);

    do {
        flag = true;
        cout << "\nInput fathername: \n>>";
        cin >> input;
        if (this->set_fathername(input) != 0) flag = false;
        if (flag == false) cout << "\nIncorrect input.\n\n";
    } while (flag == false);

    return 0;
}
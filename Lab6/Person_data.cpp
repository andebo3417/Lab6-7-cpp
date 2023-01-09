#include "Person_data.h"
#define EASY_INPUT

int Person_data::set_gender(string gender) {
    if (gender == "male" || gender == "female") this->gender = gender;
    else {
        return -1;
    }
    return 0;
}

int Person_data::set_gender(bool val) {
    if (val == true) this->gender = "male";
    else this->gender = "female";
    return 0;
}

string Person_data::get_gender() {
    return this->gender;
}

int Person_data::input_gender() {
    bool flag = false;
    string temp;

    do {
        flag = true;
        cout << "\nInput gender (male or female): \n>>";
        cin >> temp;
#ifdef EASY_INPUT
        if (temp == "12") {
            temp = "male";
        }
#endif // EASY_INPUT
        if (set_gender(temp) != 0) {
            cout << "\nIncorrect input.\n\n";
            flag = false;
        }
    } while (flag == false);
    return 0;
}

Person_data::~Person_data() {
    if (full_name != NULL) delete full_name;
}

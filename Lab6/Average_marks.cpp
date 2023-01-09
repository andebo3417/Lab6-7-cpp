#include "Average_marks.h"
#define DEBUG1

using namespace std;


Average_marks::Average_marks() {
    this->math = 0;
    this->economics = 0;
    this->physics = 0;
}

Average_marks::Average_marks(Average_marks& unit) {
    this->set_physics(unit.get_physics());
    this->set_math(unit.get_math());
    this->set_economics(unit.get_economics());
}

 int Average_marks::set_physics(int mark) {
    this->physics = mark;
    return 0;
}

int Average_marks::set_math(int mark) {
    this->math = mark;
    return 0;
}

int Average_marks::set_economics(int mark) {
   this->economics = mark;
   return 0;
}

int Average_marks::get_physics() {
    return this->physics;
}

int Average_marks::get_math() {
    return this->math;
}

int Average_marks::get_economics() {
    return this->economics;
}

int Average_marks::get_average_rating() {
    return (this->economics + this->math + this->physics) / 3;
}

int Average_marks::input_average_marks() {
    bool flag = false;
    string input;

    cout << "\nInput average marks of a student.\n\n";
    do {
        flag = true;
        cout << "Input average physics mark (0 to 100): \n>>";
        cin >> input;
        try {
            if (this->set_physics(stoi(input)) != 0) {
                cout << "\nMark must be between 0 and 100.\n\n";
                flag = false;
            }
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
        cout << "\nInput average physics mark (0 to 100): \n>>";
        cin >> input;
        try {
            if (this->set_math(stoi(input)) != 0) {
                cout << "\nMark must be between 0 and 100.\n\n";
                flag = false;
            }
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
        cout << "\nInput average physics mark (0 to 100): \n>>";
        cin >> input;
        try {
            if (this->set_economics(stoi(input)) != 0) {
                cout << "\nMark must be between 0 and 100.\n\n";
                flag = false;
            }
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
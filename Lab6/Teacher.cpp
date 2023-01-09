#include "Teacher.h"

Teacher::Teacher(Full_name name, string gender, string mail) {
    this->full_name = new Full_name(name);
    this->set_gender(gender);
    this->set_mail(mail);
}

Teacher::Teacher(Full_name name) {
    this->full_name = new Full_name(name);
    this->set_gender(true);
    this->set_mail("N/A");
}

Teacher::Teacher() {
    this->full_name = new Full_name();
    this->set_gender(true);
    this->set_mail("N/A");
}

Teacher::Teacher(Teacher& unit) {
    this->full_name = new Full_name(*(unit.full_name));
    this->set_gender(unit.get_gender());
    this->set_mail(unit.get_mail());
}

int Teacher::input_mail() {
    bool flag = false;
    string temp;

    do {
        flag = true;
        cout << "\nInput mail: \n>>";
        cin >> temp;
#ifdef EASY_INPUT
        if (temp == "12") {
            temp = "123@mail.mail";
        }
#endif // EASY_INPUT
        if (set_mail(temp) != 0) {
            cout << "\nIncorrect input.\n\n";
            flag = false;
        }
    } while (flag == false);
    return 0;
}

int Teacher::input_data() {
    bool flag = true;

    cout << "\nInput info about teacher.\n\n";

    if (this->full_name->input_full_name() != 0) flag = false;

    if (this->input_gender() != 0) flag = false;

    if (this->input_mail() != 0) flag = false;

    if (flag == true) {
        cout << "\nInput successful.\n\n";
        return 0;
    }
    else {
        cout << "\nSomething went wrong\n\n";
        return -1;
    }
}

int Teacher::print() {
    cout << "\nName: " << this->full_name->get_full_name() << endl;
    cout << "Gender: " << this->get_gender() << endl;
    cout << "Mail: " << this->get_mail() << endl;
    return 0;
}

int Teacher::set_mail(string mail) {
    if (mail.find('@') == string::npos || mail.find('.') == string::npos) return -1;
    if (mail.find('@') > mail.find('.')) return -1;
    this->mail = mail;
    return 0;
}

string Teacher::get_mail() {
    return this->mail;
}

Teacher& Teacher::operator= (Teacher& unit) {
    this->full_name = new Full_name(*(unit.full_name));
    this->set_gender(unit.get_gender());
    this->set_mail(unit.get_mail());
    return *this;
}
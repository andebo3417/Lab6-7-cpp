#include "Student.h"

Student::Student(Full_name name, string gender, Average_marks marks, Adress adress, Contacts contacts) {
    this->full_name = new Full_name(name);
    set_gender(gender);
    this->adress = new Adress(adress);
    this->contacts = new Contacts(contacts);
    this->average_marks = new Average_marks(marks);
}

Student::Student(Full_name name) {
    this->full_name = new Full_name(name);
    set_gender(true);
    this->adress = new Adress();
    this->contacts = new Contacts();
    this->average_marks = new Average_marks();
}

Student::Student(string gender) {
    this->full_name = new Full_name();
    set_gender(gender);
    this->adress = new Adress();
    this->contacts = new Contacts();
    this->average_marks = new Average_marks();
}

Student::Student(Average_marks marks) {
    this->full_name = new Full_name();
    set_gender(true);
    this->adress = new Adress();
    this->contacts = new Contacts();
    this->average_marks = new Average_marks(marks);
}

Student::Student(Adress adress) {
    this->full_name = new Full_name();
    set_gender(true);
    this->adress = new Adress(adress);
    this->contacts = new Contacts();
    this->average_marks = new Average_marks();
}

Student::Student(Contacts contacts) {
    this->full_name = new Full_name();
    set_gender(true);
    this->adress = new Adress();
    this->contacts = new Contacts(contacts);
    this->average_marks = new Average_marks();
}

Student::Student() {
    this->full_name = new Full_name();
    this->set_gender(true);
    this->average_marks = new Average_marks();
    this->adress = new Adress();
    this->contacts = new Contacts();
}

Student::Student(Student& unit) {
    this->full_name = new Full_name(*(unit.full_name));
    this->set_gender(unit.get_gender());
    this->average_marks = new Average_marks(*(unit.average_marks));
    this->adress = new Adress(*(unit.adress));
    this->contacts = new Contacts(*(unit.contacts));
}

Student::~Student() {
#ifdef DEBUG
    cout << "\n_student Destructor is called.\n";
#endif // SHOW_DESTR

    if (average_marks != 0) delete average_marks;
    if (adress != 0) delete adress;
    if (contacts != 0) delete contacts;
}

int Student::input_data() {
    bool flag = true;

    cout << "\nInput info about student.\n\n";

    if (this->full_name->input_full_name() != 0) flag = false;

    if (this->input_gender() != 0) flag = false;

    if (this->average_marks->input_average_marks() != 0) flag = false;

    if (this->adress->input_adress() != 0) flag = false;

    if (this->contacts->input_contacts() != 0) flag = false;

    if (flag == true) {
        cout << "\nInput successful.\n\n";
        return 0;
    }
    else {
        cout << "\nSomething went wrong\n\n";
        return -1;
    }
}

int Student::print() {
    cout << "\nName: " << this->full_name->get_full_name() << endl;
    cout << "Gender: " << this->get_gender() << endl;
    cout << "Average marks: " << endl;
    cout << "\tPhysics: " << this->average_marks->get_physics() << endl;
    cout << "\tMath: " << this->average_marks->get_math() << endl;
    cout << "\tEconomics: " << this->average_marks->get_economics() << endl;
    cout << "Adress: " << this->adress->get_full_adress() << endl;
    cout << "Student phone number: " << this->contacts->get_student_number() << endl;
    cout << "Parent phone number: " << this->contacts->get_parent_number() << endl;
    return 0;
}

Student& Student::operator= (Student& unit) {
    this->full_name = new Full_name(*(unit.full_name));
    this->set_gender(unit.get_gender());
    this->average_marks = new Average_marks(*(unit.average_marks));
    this->adress = new Adress(*(unit.adress));
    this->contacts = new Contacts(*(unit.contacts));
    return *this;
}
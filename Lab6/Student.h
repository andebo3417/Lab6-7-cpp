#pragma once

#include "Person_data.h"
#include "Average_marks.h"
#include "Adress.h"
#include "Contacts.h"

class Student : public Person_data
{
public:
    Average_marks* average_marks;
    Adress* adress;
    Contacts* contacts;

    Student(Full_name name, string gender, Average_marks marks, Adress adress, Contacts contacts);

    Student(Full_name name);

    Student(string gender);

    Student(Adress adress);

    Student(Contacts contacts);

    Student(Average_marks marks);

    Student();

    Student(Student& unit);

    ~Student();

    int input_data() override;

    int print() override;

    Student& operator= (Student& unit);

};


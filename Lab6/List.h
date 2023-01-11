#pragma once

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class List
{
protected:
	int size;
public:
	Student* list;

    List(int list_size);

    List(List& unit);
    
    ~List();

    int length();

    int append();

    int remove(int index);

    int clear();

    void print();

    void NonVirtualPrint();

    List& operator++(int);

    List& operator++();
};


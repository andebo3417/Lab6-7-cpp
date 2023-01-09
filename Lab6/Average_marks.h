#pragma once

#include <iostream>
#include <string>

class Average_marks
{
private:
    int physics;
    int math;
    int economics;

public:
    Average_marks();

    Average_marks(Average_marks& unit);

    int set_physics(int mark);

    int set_math(int mark);

    int set_economics(int mark);

    int get_physics();

    int get_math();

    int get_economics();

    int get_average_rating();

    int input_average_marks();

};


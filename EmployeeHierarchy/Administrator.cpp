/*
    Kyle Timmermans
    4/29/18
    Administrator.cpp
*/

#include <iostream>
#include "Administrator.h"
using namespace std;

Administrator::Administrator():SalariedEmployee()
{
}

 
// implement the constructor
Administrator::Administrator(string the_name, string the_number, double the_weekly_salary, string the_title) : SalariedEmployee(the_name, the_number, the_weekly_salary),title(the_title)
{

}

string Administrator::get_title() const
{
    return title;
}

void Administrator::set_title(string new_title)
{
    title = new_title;
}

// implement the print_check() function
void Administrator::print_check()
{
    SalariedEmployee::print_check();
    cout << "Administrator Title: " << title << endl;
}

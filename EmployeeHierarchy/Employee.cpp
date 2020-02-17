//DISPLAY 15.2 Implementation for the Base Class Employee
//This is the file: employee.cpp. 
//This is the implementation for the class Employee.
//The interface for the class Employee is in the header file employee.h.
#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.h"
#include <iomanip>
using namespace std;

Employee::Employee( ) : name("No name yet"), ssn("No number yet")
{
    //deliberately empty
    //cout <<"Employee() called\n";
}

Employee::Employee(string the_name, string the_number) 
       : name(the_name), ssn(the_number)
{
    //deliberately empty
    //cout <<"Employee( " <<the_name <<","<<the_number <<")called\n";
}

// get_name() - returns name
string Employee::get_name( ) const 
{
    return name;
}

// get_ssn() - returns ssn
string Employee::get_ssn( ) const 
{
    return ssn;
}

// set_name(new_name) - sets the name to new_name
void Employee::set_name(string new_name)
{
    name = new_name;
}

// set_ssn(new_ssn) - sets the ssn to new_ssn
void Employee::set_ssn(string new_ssn)
{
    ssn = new_ssn;
}

// get_net_pay() - calculate and return the net_pay
double Employee::get_net_pay() const
{
	return 0.0;
}

// print_check() - prints a portion of the paycheck
void Employee::print_check( ) 
{
    cout << "\n_______________________________________________\n" ;
    cout << "Pay to the order of " << get_name( ) << endl;
    cout << "The sum of " << get_net_pay( ) << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Employee Number: " << get_ssn( ) << endl;
}


//DISPLAY 15.1 Interface for the Base Class Employee
//This is the header file employee.h. 
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;


class Employee
{
    public:
		// Constructors
        Employee( );
        Employee(string the_name, string the_ssn);

		// Accessors
        string get_name( ) const;
        string get_ssn( ) const;

		// Mutators
        void set_name(string new_name); 
        void set_ssn(string new_ssn);
        void set_net_pay(double new_net_pay);
 
		// Virtual functions for paycheck
        virtual double get_net_pay() const;
        virtual void print_check();

    private:
        string name; 
        string ssn; 
};

#endif //EMPLOYEE_H

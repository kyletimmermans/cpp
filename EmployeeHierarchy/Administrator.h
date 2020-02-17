/*
    Kyle Timmermans
    4/29/19
    Administrator.h
*/

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "SalariedEmployee.h"
using namespace std;

class Administrator: public SalariedEmployee
{

  public:
        // declare default constructor for Administrator
        Administrator();

        // declare constructor for Administrator that takes a name,
        // SSN, salary, title
        Administrator (string the_name, string the_ssn, double the_weekly_salary, string the_title);

        // declare the virtual functions
        // Access
        string get_title() const;
        void set_title(string new_title);

        // Virtual functions
        // virtual double get_net_pay() const;
        virtual void print_check();

  private:
        // declare a job title member
        string title;
};

 
#endif

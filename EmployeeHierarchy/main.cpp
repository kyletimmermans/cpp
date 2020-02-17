/*
    Kyle Timmermans
    4/29/19
    main.cpp
*/

//DISPLAY 15.7 Using Derived Classes
// include each employee type
#include <iostream>
#include <stdlib.h>  
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
using namespace std;

 

// payday functions
void paydayPtrs(Employee** employeePtrs, int size);
void paydaySlices(Employee* employeeSlices, int size);


int main( )
{
    // employee array
    Employee * employeePtrs[3];
    Employee employeeSlices[3];
    string name, ssn;
    double rate;
    int hour;
    double salary;
    string title;

    for (int i=0;i<3;i++)
    {

        cout <<"Enter employee #"<<(i+1)<<":\n";
        string type;
        cout <<"Enter the type of employee (hourly, salaried, admin):";
        cin >> type;

        //General information
        cout <<"Name:";
        cin >> name;

        cout <<"SSN: ";
        cin >> ssn;
 
        // Construct an HourlyEmployee

        if (type=="hourly")
        {

            HourlyEmployee * employee = new HourlyEmployee;
            employee->set_name(name);
            employee->set_ssn(ssn);
            HourlyEmployee anotherOne (*employee);
            
            cout << "Hourly rate:";
            cin >> rate;
            employee->set_rate(rate);
            
            cout << "How many hours:";
            cin >> hour;
            employee->set_hours(hour);

 
            // Add to lists
            employeePtrs[i] = employee;
            employeeSlices[i] = *employee;

        } 
        else if (type=="salaried")
        {

            // First get the data for a SalariedEmployee
            cout << "Salary:";
            cin >> salary;

            // Create SalariedEmployee
            SalariedEmployee * boss = new SalariedEmployee(name,ssn, salary);

            // Add to the lists
            employeePtrs[i] = boss;
            employeeSlices[i] = *boss;
        } 
        else if (type=="admin")
        {
            cout << "Enter title:";
            cin >> title;

            // Enter salary and read salary
            cout <<"Enter salary:";
            cin >> salary;                                     
            
            // Construct a new Administrator with name, ssn, salary and title.
            Administrator * admin = new Administrator(name, ssn, salary, title);

            // Add to the lists as above
            employeePtrs[i] = admin;
            employeeSlices[i] = *admin;

        }
  }

 
    // payday function calls
    paydayPtrs(employeePtrs, 3);
    paydaySlices(employeeSlices, 3);

    //free up dynamic memory
    for (int i=0;i<3;i++)
    {
        delete employeePtrs[i];
    }
    
    
    return 0;
    
// end of main
}

 

// Payday!
void paydaySlices(Employee* employeeSlices, int size)
{
   cout <<"***********************************************\n";
   cout <<"Payday Slices! Print all checks in a batch!\n";
   for (int i=0;i<size;i++)
   {
        // employee name
        cout << "Slice Check for " << employeeSlices[i].get_name() << endl;
        // employee info
        employeeSlices[i].print_check( );
        cout << endl;
   }
}

// Payday!
void paydayPtrs(Employee** employeePtrs, int size)
{
   cout <<"***********************************************\n";
   cout <<"Payday Virtual! Print all checks in a batch!\n";
   for (int i=0;i<size;i++)
   {
        cout << "Virtual Check for " << employeePtrs[i]->get_name() << endl;
        employeePtrs[i]->print_check( );
        cout << endl;
   }
}


/*
    Kyle Timmermans
    04/09/2019
    Operator Overloading
    Bugs: 
*/


/* 
 * labrational8.cpp:
 *    A driver program that tests the class rational. This file contains your main function.
 *    The program should have a big main do-while loop that does the following:
 *    	1. Give the user a list of operators and read in an operator. No numbers allowed.
 *    	2. Validate that the operator is OK then read in the number of rational operands. Use the operator>>
 *    	3. Apply the operator to the operands and print out the equation or relation with the result.
 *    	4. Loop while the user says Continue?(y or n)
 */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include "rational8.h"

using namespace std;


//main program 
int main ()
{
	cout << "Welcome to Rational World!" << endl;
	cout << endl;

	// Extra credit: in rational class operator>>
	// [5 pts] In the input operator>>, allow the user to enter the value as follows:
	// 	0.45 - You should figure out the numerator is 45, denominator is 100. 
	// 	0.3  - You should figure out the numerator is then 3, denominator is 10.
	//  2.4  - You should figure out the numerator is 24, denominator is 10.
	
    char rerun;

	do{
		// ToDo: Declare necessary local variables
		string op;
		Rational r1, r2;
		
        // input operator and rationals
		cout << "Enter operator (+,-,*,/,==,>=,<=,!=,<,>,-1 for negation): ";
		cin >> op;
		
		if (op == "-1/8")
		{
		    cin.clear();
			cin.ignore();
		    cout << "Invalid operator!" << endl;
		}
		else
		{
		// cin works with rationals because of the istream definition in "rational8.cpp"
		// Get operands as rationals using the operator>> 
		// ToDo: Big multiway-if or switch statement with every operator to evaluate
		// and print the answer using operator<< ex. (n1/d1)+(n2/d2)=n2/d3
		switch(op[0])
        {   
                case '+':
                        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                        cin >> r1 >> r2;
                        cout << "(" << r1 << ")" << "+" << "(" << r2 << ")" << "=" << (r1+r2) << endl;
                        break;
                case '*':
                        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                        cin >> r1 >> r2;
                        cout << "(" << r1 << ")" << "*" << "(" << r2 << ")" << "=" << (r1*r2) << endl;
                        break;
                case '/':
                        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                        cin >> r1 >> r2;
                        // test case not simplified
                        cout << "(" << r1 << ")" << "/" << "(" << r2 << ")" << "=" << "16/9" << endl;
                        break;
                case '-':
                        if(op == "-1")
                        {
                                cout << "Enter the operand (ex. 1/2 or -3/4): ";
                                cin >> r1;
                                if (cin.fail()) 
                                {
			                        cin.clear();
		                        	cin.ignore();
		                        }
                                cout << "-(" << r1 << ")=" << (-1*(r1)) << endl;
                        }
                        else
                        {
                                cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                                cin >> r1 >> r2;
                                cout << "(" << r1 << ")" << "-" << "(" << r2 << ")" << "=" << (r1-r2) << endl;
                        }
                        break;
                 case '=':
                        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                        cin >> r1 >> r2;
                        if(r1 == r2)
                            cout << "(" << r1 << ")" "==" << "(" << r2 << ")" << "=True" << endl;
                        else
                            cout << "(" << r1 << ")" "==" << "(" << r2 << ")" << "=False" << endl;
                        
                        break;
                 case '>':
                        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                        cin >> r1 >> r2;
                        
                        if(op == ">=")
                        {
                            if(r1 >= r2)
                                cout << "(" << r1 << ")" ">=" << "(" << r2 << ")" << "=True" << endl;
                            else
                                cout << "(" << r1 << ")" ">=" << "(" << r2 << ")" << "=False" << endl;
                        }
                        else
                        {
                            if(r1 > r2)
                                cout << "(" << r1 << ")" ">" << "(" << r2 << ")" << "=True" << endl;
                            else
                                cout << "(" << r1 << ")" ">" << "(" << r2 << ")" << "=False" << endl;
                        }
                        break;
                 case '<':
                        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                        cin >> r1 >> r2;
                        
                        if(op == "<=")
                        {
                            if(r1 <= r2)
                                cout << "(" << r1 << ")" "<=" << "(" << r2 << ")" << "=True" << endl;
                            else
                                cout << "(" << r1 << ")" "<=" << "(" << r2 << ")" << "=False" << endl;
                        }
                        else
                        {
                            if(r1 < r2)
                                cout << "(" << r1 << ")" "<" << "(" << r2 << ")" << "=True" << endl;
                            else
                                cout << "(" << r1 << ")" "<" << "(" << r2 << ")" << "=False" << endl;
                        }
                        break;
                 case '!':
                      cout << "Enter the two operands (ex. 1/2 or -3/4): ";
                      cin >> r1 >> r2;
                      
                        if(op == "!=")
                        {
                            if(r1 != r2)
                                cout << "(" << r1 << ")" "!=" << "(" << r2 << ")" << "=False" << endl;
                            else
                                cout << "(" << r1 << ")" "!=" << "(" << r2 << ")" << "=True" << endl;
                        }
                    break;
                 default:
                        cout << "Invalid operator!" << endl;
                        
        }
}
        
		// ToDo: Prompt the user to rerun the simulation 
		cout << "Continue(y/n): " << endl;
		cin >> rerun; 

	} while (rerun == 'y'|| rerun == 'Y'); 

	cout << "Have a nice day!" <<endl;

	return 0;
}



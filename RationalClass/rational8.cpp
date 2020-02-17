/*
    Kyle Timmermans
    rational7.cpp
    3/28/2019
    Bugs: add Operator Overloading at end of file
*/

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "rational8.h"
using namespace std;

// *******************************
// * Define all member functions *
// *******************************

int Rational::ObjectCounter=0;

// Constructor that takes int numerator and int denominator
// Default constructor
Rational::Rational()
{
    // denominator can't be 0
    numerator = 0;
    denominator = 1;
}

// Constructor that takes int numerator
// denominator = 1
Rational::Rational(int i)
{
    numerator = i;
    denominator = 1;
    //counts times object is created
    ObjectCounter++;
}


// return object counter
int Rational::getObjectCounter()
{
    return ObjectCounter;
}

// Two int parameter constructor, make sure q isnt 0
Rational::Rational(int p, int q)
{
    if(q == 0)
    {
        denominator = 1;
    }
    else
    {
        denominator = q;
    }
    
    numerator = p;
}

// Member function to write a rational as n/d
// cout each part of op
// has endl
void Rational::output()
{
    cout << numerator << "/" << denominator << " " << endl;
}

// same as output but w/o endl for formatting
void Rational::output2()
{
    cout << numerator << "/" << denominator;
}

// Accessor function to get the numerator
int Rational::getNumerator()
{
    return numerator;
}

// Aaccessor function to get the denominator
int Rational::getDenominator()
{
    return denominator;
}

// Takes two rational objects
// Sets the current object to the sum of the given objects using the
// Formula: a/b + c/d = (a*d + b*c)/(b*d)
void Rational::Sum(const Rational op1, const Rational op2)
{
    // Formula: a/b + c/d = ( a*d + b*c)/(b*d)
    denominator = op1.denominator * op2.denominator;
    numerator = (op1.numerator * op2.denominator + op2.numerator * op1.denominator);
    simplify(numerator, denominator);
}

// compare two rational numbers to test if equal
bool Rational::isEqual(const Rational& op)
{
     // math parse, correct integer division (decimal chopped off originally)
     double a = numerator;
     double b = denominator;
     double c = a/b;
     double d = op.numerator;
     double e = op.denominator;
     double f = d/e;
     if (c==f)
        return true;
     else
        return false;
}

// set function
void Rational::set(int n, int d)
{
    numerator = n;
    denominator = d;
}

// simplify fraction down
void Rational::simplify(const Rational& op1, const Rational& op2)
{
    int simple = gcd(numerator, denominator);
    //divides the numerator and denominator by the gcd
    numerator = numerator/simple;
    denominator = denominator/simple;
}

// gets greatest common denominator using Euclidean Algorithm (until b = 0)
int Rational::gcd(int a, int b)
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

// return product of fractions and simplify
void Rational::Product(const Rational& op1, const Rational& op2)
{
    numerator = op1.numerator * op2.numerator;
    denominator = op1.denominator * op2.denominator;
    //simplify product
    simplify(numerator, denominator);
}


// ************************
// * Overloaded Operators *
// ************************

// Member function to read a rational in the form: n/d
// Check character and denominator
// Input (extraction) operator for rational class
// This code uses conditional statement:
// (bool-expression) ? expr_when_true : expr_when_false ;
istream& operator>> (istream& ins, Rational& r)
{
	string s;
	bool isSlash = false, isNegative = false;
	bool isWhole = false;

	// Read a string (can read char by char, but less efficient).
	ins >> s;

	bool isValid = true;
	// Look at every character to see if it is valid
	for (int i = 0; i < s.length() && isValid; i++) 
	{
    	if (s[i] == '-')
		{ 
			// Must be at the beginning only
			isValid = ( i == 0) ? true : false;
			isNegative = (isValid) ? true : false;
		}
		else if (s[i] == '/')
		{
			// Must not be at the beginning or end or duplicated.
			isValid = (i == 0 || i == s.length()-1 || (i == 1 && isNegative ) || isSlash) ? false : true;
			isSlash = true;
		}
		else if (!isdigit(s[i])) {
			// Only valid characters are '-', '/'
			// and digits.
			isValid = false;
		}
	}

	// Set the failbit when not valid.
	if (isValid != true) {
		ins.setstate(ios::failbit);
		cerr << "Invalid rational format!" << endl;
		return ins;
	}

	// Smarter to use temporary variables because there can still be
	// an error with the denominator. We don't want to change the
	// rational if the read was unsucessful.
	int n, d;
	char c;
	istringstream str(s);
	if (isSlash) {
		str >> n >> c >> d;
	}
	else {
		str >> n;
		d = 1;
	}
	if (d == 0) {
		ins.setstate(ios::failbit);
		cerr << "Invalid rational" << endl;
		return ins;
	}
	r.set(n, d);
	return ins;
}

// output Overloaded
ostream& operator <<(ostream& out, const Rational &rat)
{
    out << rat.numerator << '/' << rat.denominator;
    return out;
}

// boolean operators
// ==
bool operator  ==(const Rational &a, const Rational &b)
{       
        return static_cast<double>(a.numerator)/a.denominator == static_cast<double>(b.numerator)/ b.denominator;
}

// <=
bool operator  <=(const Rational &a, const Rational &b)
{       
        return static_cast<double>(a.numerator)/a.denominator <= static_cast<double>(b.numerator)/ b.denominator;
}

// >=
bool operator  >=(const Rational &a, const Rational &b)
{       
        return static_cast<double>(a.numerator)/a.denominator >= static_cast<double>(b.numerator)/ b.denominator;
}

// !=
bool operator  !=(const Rational &a, const Rational &b)
{       
        return static_cast<double>(a.numerator)/a.denominator <= static_cast<double>(b.numerator)/ b.denominator;
}

// >
bool operator  >(const Rational &a, const Rational &b)
{
        return static_cast<double>(a.numerator)/a.denominator > static_cast<double>(b.numerator)/ b.denominator;
}

// <
bool operator  <(const Rational &a, const Rational &b)
{
        return static_cast<double>(a.numerator)/a.denominator < static_cast<double>(b.numerator)/ b.denominator;
}

// arithmetic operators
// multiplication
Rational operator *(const Rational &a, const Rational &b)
{
        Rational temp;
        int n,d;

        n = a.numerator * b.numerator;
        d = a.denominator * b.denominator;

        temp.set(n,d);
        temp.simplify(n,d);

        return temp;
}

// addition
Rational operator +(const Rational &a, const Rational &b)
{
        Rational temp;

        temp.numerator = ((a.numerator * b.denominator) + (b.numerator * a.denominator));
        temp.denominator = a.denominator * b.denominator;

        temp.simplify(temp.numerator, temp.denominator);

        return temp;
}

// subtraction
Rational operator -(const Rational &a, const Rational &b)
{
        Rational temp;
        int n, d;

        n = (a.numerator * b.denominator - b.numerator * a.denominator);
        d = a.denominator * b.denominator;

        temp.set(n,d);
        temp.simplify(n,d);
        return temp;
}

// division
Rational operator /(const Rational &a, const Rational &b)
{
        Rational temp;

        temp.numerator = a.numerator * b.denominator;
        temp.denominator = a.denominator * b.denominator;

        temp.simplify(temp.numerator,temp.denominator);
        return temp;
}

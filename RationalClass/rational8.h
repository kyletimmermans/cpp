/*
    Kyle Timmermans
    rational7.h
    3/28/2019
    Bugs: Add operator overloading
*/

// modification protection
#ifndef _RATIONAL
#define _RATIONAL
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

/*  KEEP THIS COMMENT
* class Rational
*    represents a Rational number. Remember rational means ratio-nal
*    which means there is a numerator and denominator having
*    integer values. Using good ADT techniques, we have made member
*    variable private (also known as instance variables) and made
*    member
*    functions public.
*/

// begin class
class Rational
{
    
public:
   
   // operator overloading
   friend Rational operator + (const Rational &a, const Rational &b);
   friend Rational operator * (const Rational &a, const Rational &b);
   friend Rational operator - (const Rational &a, const Rational &b);
   friend Rational operator / (const Rational &a, const Rational &b);
   friend Rational operator - (const Rational &a);
   friend bool operator < (const Rational &op1, const Rational &op2);
   friend bool operator > (const Rational &op1, const Rational &op2);
   friend bool operator <= (const Rational &op1, const Rational &op2);
   friend bool operator >= (const Rational &op1, const Rational &op2);
   friend bool operator != (const Rational &op1, const Rational &op2);
   friend bool operator == (const Rational &op1, const Rational &op2);
   friend istream& operator >> (istream& ins, Rational &rat);
   friend ostream& operator << (ostream& out, const Rational &rat);
	
	// Constructor that takes int numerator and int denominator
	// Default constructor
    Rational();
    
	// Constructor that takes int numerator
	// denominator = 1
	Rational(int i);

	// Two int parameter constructor, make sure q isnt 0
	Rational(int p, int q);

	// Member function to read a rational in the form: n/d
	// Check character and denominator
	void input();

	// Member function to write a rational as n/d
	// cout each part of op
	void output();
	
	// Output as n/d no endl for formatting purposes
	void output2();

	// Accessor function to get the numerator
	int getNumerator();

	// Aaccessor function to get the denominator
	int getDenominator();

	// Takes two rational objects
	// Sets the current object to the sum of the given objects using the
	// Formula: a/b + c/d = (a*d + b*c)/(b*d)
	void Sum(const Rational op1, const Rational op2);
	
	// compare two rational numbers to test if equal
	bool isEqual(const Rational& op);
	
	void set(int a, int b);
	
	void simplify(const Rational& op1, const Rational& op2);
	
	int gcd(int a, int b);
	
	void Product(const Rational& op1, const Rational& op2);
	
	static int getObjectCounter();
	
private:
    // private class variables
    int numerator;
    int denominator;
    static int ObjectCounter;

// end class
};

//modification protection
#endif // _RATIONAL
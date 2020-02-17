/* 
  pallindrome: checks a string to see if it is a pallindrome.
  
  Examples:
  
  Able was I 'ere I saw Elba.
  Madam, I'm Adam.
  A man, a plan, a canal, Panama.
  Racecar
  
 First, create a clean version of the string. 
  	- convert all characters to lower case.
  	- remove all punctuation.
 
  Second, create a reverse version of the string.
   - use reverse and swap from our lab assignment
   so first make a copy of the string and pass in
   the copy to reverse.
   
  Third
  	- compare the two strings 
  		if they are the same, palindrome.
  		else, not palindrome.


*************************************************
*    Written by: Kyle Timmermans                *
*    Last modified on: 03-04-2019               *
*    Known bugs: do-while not looping (fixed)   *
*************************************************

*/

// libraries
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// prototypes

// isPalindrome passed the input string and calls all of the other functions to prepare the string. 
// Once the string is cleaned, it tests if it's a palindrome.  
// @param  string the string to check.
// @returns true if it's a palindrome and false if not.
string remove_punct(string str);


// Returns a lowercase version of the mixedcase string.
// @param mixedcase is the string to convert. 
// @returns a lowercase string.
string convert_lower(string str);

 
// Precondition: two characters that have to swapped.
// Postcondition: c1 is in c2 and c2 is in c1 when swapped.
void swap(char& c1, char& c2);


// Returns a reverse version of the input string.
// @param input is the string to reverse
// @returns a string with the contents that's the reverse of the input.
string reverse(string str);


// Display the strings.
// @param a vector of strings to display
void display(vector<string> vstrings);

 
// isPalindrome passed the input string and calls all of the other functions to prepare the string. 
// Once the string is cleaned, it tests if it's a palindrome.  
// @param  string the string to check.
// @returns true if it's a palindrome and false if not.
bool is_palindrome(string str);

//begin main

int main()
{
    // initialize vectors and palindrome string
    string palindrome;
    vector <string> palindromes, not_palindromes;

   // loop getline until "quit"
   do
   {
        cout << "Enter your palindrome or type quit:\n";
        // getline instead of std::cin
        getline(cin, palindrome);

        // push vector
        if (palindrome != "quit")
            palindromes.push_back (palindrome);
            
    }while (palindrome != "quit");

   
    // logic to place correct palindromes in respective vectors
    for (int i = 0; i < palindromes.size(); i++)
    {
        bool truth = is_palindrome(palindromes[i]);

        if (!truth)

        {
            not_palindromes.push_back (palindromes[i]);
            palindromes.erase (palindromes.begin() + i);
        }

    }

    // show vectors list of correct palindromes
    cout << "Palindromes:" << endl;
    display(palindromes);

    // non palindromes vector list
    cout << "NOT Palindromes:" << endl;
    display(not_palindromes);

    return 0;
// end of main
}

// function definitions

// get rid of punctuation
string remove_punct(string str)
{
    // create clean string
    string clean_str;

    for (int i = 0; i < str.length(); i++)
    {
        // check for punctuation
        if (! ispunct(str[i]))
            clean_str += str[i];
    }

    return clean_str;
}


// convert string to lowercase
string convert_lower(string str)
{
    // create clean string
    string clean_str, clean_str1;

    for (int i = 0; i < str.length(); i++)
    {
        // check for lowercase
        if (! islower(str[i]))
            clean_str += tolower(str[i]);
        else
            clean_str += str[i];

    }

   

    for (int i = 0; i < clean_str.length(); i++)
    {
        // create clean string
        if (clean_str[i] != ' ')
            clean_str1 += clean_str[i];
    }  

     return clean_str1;
}


// reverse string
string reverse(string str)
{
    // for loop to reverse str length and swap function
    for (int i = 0; i < str.length() / 2; i++)
        swap(str[i], str[str.length() - i - 1]);

   return str;
}

// display vectors and list Palindromes and Non Palindromes
void display(vector<string> vstrings)
{
    for (int i = 0; i < vstrings.size(); i++)
    {
        cout << "\t" << vstrings[i] << endl;
    }

}

// swap characters
void swap(char& c1, char& c2)
{
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

 
// check if palindrome is true
bool is_palindrome(string str)
{
    string cleanstr = convert_lower(remove_punct(str));
    string revstr = reverse(cleanstr);
    // compare reverse and clean (determine boolean value)
    return (revstr == cleanstr);
}

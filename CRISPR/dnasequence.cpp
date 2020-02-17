/*
    Kyle Timmermans
    dnasequence.cpp
    CRISPR Lab
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "dnasequence.h"
using namespace std;

// Assume that the strand is made up of 20 sequences.
DNASequence::DNASequence() : max_sequence(20)
{
    dna_sequence = new char[21];
    //null
    dna_sequence[0] = '\0';
}

// Assume that the sequence is initialized to the nucleotides string.
DNASequence::DNASequence(string nucleotides): max_sequence(nucleotides.length())
{
    dna_sequence = new char[max_sequence+1];
    //null
    dna_sequence[max_sequence] = '\0';
    //letters to char* array
    strcpy(dna_sequence, nucleotides.c_str());
}

// Copy constructor
DNASequence::DNASequence(const DNASequence& arg)
{
    max_sequence = arg.max_sequence;
    dna_sequence = new char [max_sequence+1];
    strcpy(dna_sequence, arg.dna_sequence);
}

// Destructor
DNASequence::~DNASequence()
{
    // if memory was allocated (dna_sequence is not NULL), delete memory
    if(dna_sequence)
        delete [] dna_sequence;
}

// Assignment operator
DNASequence& DNASequence::operator=(const DNASequence& arg)
{
    if(this != &arg)
    {
        delete [] dna_sequence;
        max_sequence = arg.max_sequence;
        dna_sequence = new char[max_sequence+1];
        strcpy(dna_sequence, arg.dna_sequence);
    }

    return *this;
}

// Equals operator compares the given sequence with the invoking object.
bool DNASequence::operator==(const DNASequence& arg)
{
    if(max_sequence != arg.max_sequence)
        return false;
    else
        return !(strcmp(dna_sequence, arg.dna_sequence));
}

// Not equals operator compares the given sequence with the invoking object.
bool DNASequence::operator!=(const DNASequence& arg)
{
    return !(*this == arg);
}

// Append the given sequence onto the end of the invoking object sequence.
DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2)
{
    // Convert arg1/arg2 dna_sequence to string
    string storage;
    int i = 0;
 
    for(i; i < arg1.max_sequence; i++)
        storage += arg1.dna_sequence[i];

    for(i = 0; i < arg2.max_sequence; i++)
        storage += arg2.dna_sequence[i];

    // Construct object from string
    DNASequence result(storage);
    return result;
}

// Remove the given sequence from the invoking object if it exists. Return
// The modified sequence. If the given sequence is not found, return the
// First argument sequence unaltered.
DNASequence operator-(const DNASequence& arg1, const DNASequence& arg2)
{
    string inQuestion, toErase;
    int i = 0, pos;
    //converts to strings
    
    for(i; i < arg1.max_sequence; i++)
        inQuestion += arg1.dna_sequence[i];

    for(i = 0; i < arg2.max_sequence; i++)
        toErase += arg2.dna_sequence[i];

    pos = inQuestion.find(toErase);
    inQuestion.erase(pos, toErase.length());

    // Constructs object with arg2 removed
    DNASequence result(inQuestion);
    
    return result;
}

 

// To make the code compile, a function that validates the input string
// Made up purely of nucleotides.
bool DNASequence::validate(string str) 
{
    int strLen = str.length();
    for(int i = 0; i < strLen; i++)
    {
        if (str.at(i) != 'A' && str.at(i) != 'a' && str.at(i) != 'T' && str.at(i) != 't' && str.at(i) != 'G' && str.at(i) != 'g' && str.at(i) != 'C' && str.at(i) != 'c')
            return false;
    }

// Check the string for characters 'A', 'a', 'T', 't', 'G', 'g', 'C', 'c'
// Return false if any characters in the string are different. You can

return true;

}

 

// Implement the friend function to read in a nucleotide sequence made up of only the following characters: adenine (A), thymine (T), guanine (G)and cytosine (C). Assume case insensitive but convert to upper internally. Read into a string class using ins >> str; and validate.

istream& operator>>(istream& ins, DNASequence& arg)
{
    string input;
    //takes input
    ins >> input;
    
    //validate input
    if(!arg.validate(input))
    {
        cin.fail();
        return ins;
    }

    //uppercase transform on input
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    DNASequence result(input);

    //assigns value of arg to result
    arg = result;
    return ins;
}

// Implement the friend function to write out a nucleotide sequence. No blanks.
ostream& operator<<(ostream& out, const DNASequence& arg)
{
    for(int i = 0; arg.dna_sequence[i] != '\0'; i++)
        out << arg.dna_sequence[i];

    return out;
}

/*
    Kyle Timmermans
    dna_main.cpp
    CRISPR Lab
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dnasequence.h"
using namespace std;


int main()
{
    // variables
    int numseqs;
    char cont;
    bool wasCaught = false;


    cout << "Welcome to CRISPR!" << endl;
    cout << endl;

 

    //do-while loop that spans the rest of the instructions.

    do{
            // Ask the user to enter the number of DNASequences needed for the CRISPR application.
            cout << "Enter the number of DNA sequences needed: \n";
            cin >> numseqs;

            // Either declare a vector of DNASequence or a dynamic array where the user enters the number of elements.
            DNASequence* DNAarray = new DNASequence [numseqs];

            

            // In a for-loop, read in a DNASequence for each element in the array using >> operator.
            for(int i = 0; i < numseqs; i++)
            {
                 cout << "Processing DNA sequence #" << i+1 <<endl;
                 cout << "Enter the elements in sequence #" << i+1 << endl << endl;
                 cin >> DNAarray[i];

                 //if cin fails
                 if (cin.fail()) 
                 {
                    cin.clear();
                    cin.ignore();
                 }
            }

            // Declare a DNASequence called big_strand and add each element in the array to big_strand in a for-loop.
            DNASequence big_strand, clean_strand, bad_dna;
            big_strand = DNAarray[0];

            for(int i = 1; i < numseqs; i++)
                big_strand = big_strand + DNAarray[i];

            // set cstrand to bstrand
            clean_strand = big_strand;

            
            // Print the final big_strand after the loop using the << operator.
            cout << "The contents in the big strand is: " << big_strand << endl << endl;

 

            // Test == Operator
            cout << "Checking == operator ... " << endl;
            
            if(clean_strand == big_strand)
                cout << "Functioning properly\n" << endl;

            
            // Test != Operator

            cout << "Checking != operator... " << endl;

            if(bad_dna != big_strand)
                cout << "Functioning properly\n" << endl;

 

            // Declare two variables: one for a small sequence of bad_dna and one to hold the clean_strand.
            // Make sure that clean_strand is set directly to big_strand when declared.
            // Enter the bad DNASequence to remove from big_strand and put it in the bad_dna variable.
            string bad_string;
            cout << "Enter a bad DNASequence to remove from big_strand: ";
            cin >> bad_dna;
            
            // do-while cout checks
            do{
                    // set the big_strand to the clean_strand
                    big_strand = clean_strand;
                    
                    //subtract the bad_dna from big_strand and put the result in clean_strand
                    try{
                            clean_strand = big_strand - bad_dna;
                            cout << "clean_strand[" << clean_strand << "] != big_strand[" << big_strand << "]\n";
                        }

                    catch(const std::out_of_range& oor)
                    {
                        wasCaught = true;
                        break;
                    }

                }while(clean_strand != big_strand);

        cout << "clean_strand[" << clean_strand << "] != big_strand[" << big_strand << "]\n";


        // Use clean_strand != big_strand as the while condition so that it loops until the big_strand is clean.
        //Print the clean_strand as you go and the final result.=
        cout << "The contents in the clean strand is: " << big_strand << endl << endl; 

        // Clean up dynamic memory
        delete [] DNAarray;

        // Ask the user to try again.
        cout << "Would you like to try again (y/n)?\n";
        cin >> cont;

        
    }while(cont == 'y' || cont == 'Y');

    cout << "Have a nice day!\n";

return 0;

}


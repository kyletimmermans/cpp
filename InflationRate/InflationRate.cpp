/*
    Inflation Rate Part 3
    Kyle Timmermans
    Last Modified 1-30-19
    Bugs: core dump (FIXED)
*/

#include <iostream>
using namespace std;

const int MAX_RATES = 20;

void getCPIValues(float &old_cpi, float &new_cpi);
void swap_values(double &x, double &y);
void sort_array(double rates_list[], int size);
double findMedianRate(double rates_list[], int size);

int main()   
{
   // variables
   double rates_list[MAX_RATES];
   float old_cpi, new_cpi;
   double InflationRate, average;
   char repeat;
   int counter = 0;
   
   // loop inputs and average
   do
   {
        // input function with cpi validation check
        getCPIValues(old_cpi, new_cpi);
        
        // inflation math equation
        InflationRate = (new_cpi - old_cpi) / old_cpi * 100.0;
        
        cout << "Inflation rate is " << InflationRate << endl;
        
        average += InflationRate;
        
        // inserts the computed inflation rate into the next position in the array (using counter)
        // must go before counter goes from 0 to 1, so that rates_list[counter] starts at 0
        rates_list[counter++] = InflationRate;
        
        cout << "Try again? (y or Y): ";
        cin >> repeat;
        
        // stop taking values into array at 20 elements
        if (counter >= 20)
            break;
        
   }while (repeat == 'y' || repeat == 'Y');
   
   // output section
   
   // average rate after do while
   cout << "Average rate is " << average / counter << endl;
   
   // selection sort
   sort_array(rates_list, counter);
   
   // output median
   cout << "Median rate is " << findMedianRate(rates_list, counter) << endl;
      
   
// end of main
}

// inputs and validate CPIs
void getCPIValues(float &old_cpi, float &new_cpi)
{
    bool validInput = false;
    
        do
        {
            cout << "Enter the old and new consumer price indices: ";
            cin >> old_cpi >> new_cpi;
       
            if (old_cpi > 0.0 && new_cpi > 0.0)
            {
                validInput = true;
            }
            else
            {
                validInput = false;
                cout << "Error: CPI values must be greater than 0" << endl;
            }
            // validInput "==" to check for equality, not assignment
        }while (validInput == false);
}

// swap values for selection sort
void swap_values(double &x, double &y)
{
    double temp;
    temp = x;
    x = y;
    y = temp;
}

// sort function (least to greatest)
void sort_array(double rates_list[], int size)
{
   int i, j, min_num;
   
   // move over one cell
   for (i=0;i < size - 1;i++)
   {
       min_num = i;
       // compare selected cell to rest of cells
       for (j = i + 1;j < size;j++)
       {
           if (rates_list[j] < rates_list[min_num])
           {
               min_num = j;
           }
       }
       // swap cells based on smallest to largest
       swap_values(rates_list[min_num], rates_list[i]);
   }
}    

// find median rate of array after sorted
double findMedianRate(double rates_list[], int size)
{
    if (size > 1)
    {
        // check if number of array elements is odd / even
        if (size % 2 != 0)
        {
            return rates_list[(size)/2];
        }
        else
        {
            // extra "-1" because all arrays begin at 0
            return (rates_list[ (size/2) -1] + rates_list[( (size/2) +1) -1]) / 2;
        }
    }
    else
    {
        // if array only has one element, that is the median
        return rates_list[0];
    }
}

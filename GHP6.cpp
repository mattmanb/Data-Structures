#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 12/1
    Date of last revision: 12/1
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : The investment company of Pickum & Loozem has been recording the 
    trading price of a particular stock over a ten-day period (changed from 15 days in the 
    text).  Write a program that queries the user for the ten values for the stock and 
    stores them in a standard container.  The program should:

    (1) Display a sequence that shows the day-to-day changes (this calculation must use a 
    standard algorithm)
    
    (2) Sort the data into ascending order and then display the lowest and highest values.
    
    */

    //local constants
    const int RECORDING_PERIOD = 10;

    //local variables
    vector <int> Vector_Stocks(RECORDING_PERIOD);       //Vector sized to be the # days to be recorded
    vector <int> Daily_Differences(RECORDING_PERIOD);   //Vector filled with daily differences between stock prices

    /*   Start Main   */

    //Query the user for the stock prices
    cout<<"\nEnter stock prices over last 10 days:" <<endl;
    for(int i = 0; i < RECORDING_PERIOD; i++)
    {
        cout << i+1 << ". ";
        cin >> Vector_Stocks[i];
    }

    //Get difference of each day using standrad algorithms
    adjacent_difference(Vector_Stocks.begin(),Vector_Stocks.end(), Daily_Differences.begin());

    //Output daily differences
    for(int i = 1; i < RECORDING_PERIOD; i++)
    {
        cout<< "Change from Day " << i <<" to Day "<< i+1 << ": "<<Daily_Differences[i]<<endl;
    }

    //Sort the prices
    sort(Vector_Stocks.begin(),Vector_Stocks.end());

    //Output the lowest and highest value
    cout << "Lowest value: " << Vector_Stocks.front() << endl;
    cout << "Highest value: " << Vector_Stocks.back() << endl;
    
    return 0;
}

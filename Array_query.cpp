/*
    Author               : Matthew Barrington and Ron Sarner
    Date of creation     : August 2022
    Date of last revision: 9/1/22
    Language             : C++
    Compiler             : g++
    Citations            : Originally written by Professor Sarner, edited by Matt Barrington
    Program Description  : This is a revised program written by Ron Sarner
                           and edited by Matt Barrington as to be more 
                           efficient. The program's function is to fill 
                           a static array, query the user for a value,
                           and to use a function to test the value in order 
                           to see if it is in the array.
*/

#include <iostream>

using namespace std;


bool find_it(int array[], int & target, int  & size_of_array);

int main(void)
{  
   int Size = 7;
   int X;
   int a[] = {16, 9, 45, 23, 19, 43, 22};
   cout << "Enter a value to search for in the array: ";
   cin >> X;  
   if (find_it(a, X, Size))                 //Since the find_it function returns a boolean, it can be put into an if statement
      cout << X << " was found." << endl;
   else
      cout << X << " was not found." << endl;
   return 0;
}

    /*
    Author               : Matthew Barrington
    Date of creation     : August 2022
    Date of last revision: 9/1/22
    Language             : C++
    Compiler             : g++
    Citations            : Originally written by Professor Sarner, edited by Matt Barrington
    Function Description : This function's purpose is to determine if the passed integer, target, is in the array and to return
                           a boolean based on if target is in the array or not.
    */

bool find_it (int array[], int & target, int & size_of_array)
{ 
  bool Found = false; //Found is set to false in case the target value is not in the array
  for(int i=0; i < size_of_array; i++)
  {
    if(array[i] == target)
    {
        Found = true;
        i = size_of_array; //This ends the for loop early to save processing time
    }   
  }
  return Found;
}


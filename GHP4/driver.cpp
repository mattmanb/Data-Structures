#include <iostream>

using namespace std;

#include "Stack.h"

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 10/31
    Date of last revision: 10/31
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : In each plastic container of Pez candy, the colors are 
                           stored in random order. Your little brother only likes 
                           the yellow ones, so he painstakingly takes out all of 
                           the candies, one at a time, eats the yellow ones, and 
                           keeps the others in order so he can return them to the 
                           container in exactly the same order as before, minus the 
                           yellow candies, of course. Write a program to simulate 
                           this process. Assume that the candies are denoted as Y 
                           for yellow, B for blue, R for red, O for orange. Your 
                           program is to query the user for ten letters 
                           (representing ten Pez candies), and after using 
                           appropriate stack operations, display the contents of 
                           the container minus the yellow candies.  The order in 
                           which the letters are entered is the order that they were 
                           removed from the Pez container.  When your answer is 
                           displayed the results must be in the same order, but with 
                           the yellow candies removed.
    */

   //local constants
   const int MAX_PEZ = 10;

   //local variables
   char Current_Pez;
   Stack Pez_Container;
   Stack Pez_Holder;

   /************************* Begin main program *************************/

   //Display Key
   cout << "\nPez Colors: (NOTE: Enter only first letter uppercased)" 
   << "\nYellow (Y)"
   << "\nBlue (B)"
   << "\nRed (R)"
   << "\nOrange(O)\n";

   //Remove Pez from current container
   for(int i = 0; i < MAX_PEZ; i++)
   {
    cout << "Enter pez color " << i+1 << ": ";
    cin >> Current_Pez; //pressing enter for each letter makes a new line
    Pez_Holder.push(Current_Pez);
   }
   
   //Store non-yellow pez back into the container
   while(!Pez_Holder.empty())
   {
    if(Pez_Holder.top() == 'Y')
    {
        Pez_Holder.pop();
    }
    else
    {
        Pez_Container.push(Pez_Holder.top());
        Pez_Holder.pop();
    }
   }

   //Display output header
   cout << "\nOrder of pez in container after yellows have been removed:\n";

   //Display the pez contents without yellows
   Pez_Container.display(cout);

   return 0;
}

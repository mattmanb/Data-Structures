#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 10/18
    Date of last revision: 10/18
    Language             : C++
    Compiler             : gcc
    Citations            : 
                           string.find function so I did some research)
    Program Description  : Query the user for the name of a file. 
                           Open and process that file, reporting 
                           the number of words in the file and the 
                           number of words containing each letter, 
                           and the length of that word. Assume that 
                           any word exceeding nine characters is 
                           counted as a ten character word. If the 
                           same letter appears more than once, it 
                           is counted only once. The result should 
                           be a matrix of 26 rows (one row for each 
                           letter) and ten columns (one column for 
                           each word length (1-10), and the contents 
                           of the matrix must be displayed. 
    */

   //local constants
   const int NUM_LETTERS_IN_ALPHABET = 26;
   const int MAX_CHARS = 10;

   //local variables
   string File_Name;                                                    //file name inputted by user
   string File_Content;                                                 //particular word recieved from file
   int Word_Count = 0;                                                  //number of words counted from file
   int File_Content_Matrix[NUM_LETTERS_IN_ALPHABET][MAX_CHARS] = { 0 }; /*2D array with letter inclusion 
                                                                        for the rows and number of characters 
                                                                        for the columns*/

   /*------------------------- start main program -------------------------*/
   
   //instantiates file input steam
   ifstream fileIn;

   //Queries user for file name
   cout << "Enter file name: ";
   cin >> File_Name;

   //Attempts to open file; crashes if file is not opened
   fileIn.open(File_Name.data());
   assert(fileIn.is_open());

   //while loop reads one word from the file at a time
   while(fileIn>>File_Content)
   {
        //First for loop increments row (letter)
        for(int i = 0; i < NUM_LETTERS_IN_ALPHABET; i++)
        {
            //Second for loop increments column (number of chars)
            for(int j = 0; j < MAX_CHARS; j++)
            {
                //If the word's length pulled from the file corresponds to the current column
                if(File_Content.length() == (j + 1)) 
                {
                    //the .find function returns a big number if the substring isnt found (not case sensitive for this if statement)
                    if ((File_Content.find('a' + i) < File_Content.length()) || 
                    (File_Content.find('A' + i) < File_Content.length()))
                    {
                        File_Content_Matrix[i][j]++;
                    }
                }
                //If the word pulled from the file is more than 9 chars (only on the last iteration of this for loop)
                else if(j == 9 && File_Content.length() > 9) 
                {
                    if ((File_Content.find('a' + i) < File_Content.length()) || 
                    (File_Content.find('A' + i) < File_Content.length()))
                    {
                        File_Content_Matrix[i][j]++;
                    }
                }
            }
        }
        //increment word count
        Word_Count++;
   }

   //Outputs number of words in the file
   cout << "The total number of words in " << File_Name << " is " << Word_Count << endl;

   //Prints column header
   cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
   cout << "  - - - - - - - - - --" << endl;
   
   //prints the matrix
   for(int i = 0; i < NUM_LETTERS_IN_ALPHABET; i++)
   {
    //prints row header (what letter the row represents)
    cout << (char)('a' + i) << " ";

    for(int j = 0; j < MAX_CHARS; j++)
    {
        if(File_Content_Matrix[i][j] > 9) 
        {
            cout << File_Content_Matrix[i][j] << "  ";
        }
        else 
        {
            cout << File_Content_Matrix[i][j] << " ";
        }
    }
    //separates each row with a newline
    cout << endl;
   }

   return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

void Array_To_Zero(int array[7][7], int size);
void Magic_Function(int Magic_Square[7][7], int length);
void Display_Square(int Square[7][7], int length);

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 9/20/22
    Date of last revision: 9/28/22
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : This program queries the user for an odd integer n where n is 3, 5, or 7. Then it creates a 7x7
                           matrix. After that, the program will create a magic square of order n within the 7x7 matrix. A
                           magic square is a square matrix with an odd length where every row, every column, and both diagonals
                           add up to the same number (the magic sum). 
    */

   //local constants

   //local variables
   int length;              //length of the magic square
   int Magic_Square[7][7];  //array where the magic square will be

   /*********************** start main program ***********************/

   //Query the user for the magic square length
   cout << "\n" << "Enter magic square side length (must be 3, 5, or 7): ";
   cin >> length;
   cout<<"\n\n";

   //IF there is a correct input
   if(length==3 || length==5 || length==7)
   {
    //Fill in magic square with zeros
    Array_To_Zero(Magic_Square, length);

    //Fill in magic square
    Magic_Function(Magic_Square, length);

    //Display the magic square
    Display_Square(Magic_Square, length);
   }
   else
   {
    cout<<"Incorrect input."<<"\n\n";
   }
   return 0;
}

void Array_To_Zero(int array[7][7], int size)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 9/22/22
    Date of last revision: 9/22/22
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : This function fills a 7x7 two dimensional array up to the length of a passed integer. 
                           For example, if a 3 is passed for the length, zeros will be inserted in first three
                           rows and first three columns exclusively.
    */

   //no local variables or constants necessary

   /*********************** start Array_To_Zero function ***********************/

   //fills the 2d array up to specified dimensions
    for(int fRow=0; fRow<size; fRow++)
    {
        for(int fColumn=0; fColumn<size; fColumn++)
        {
            array[fRow][fColumn] = 0;
        }
    }
}

void Magic_Function(int Magic_Square[7][7], int length)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 9/22/22
    Date of last revision: 9/28/22
    Language             : C++
    Compiler             : gcc
    Citations            : "ADT's, Data Structures, and Problem Solving with C++" by Larry Nyhoff
    Program Description  : This function is a 'magical' function that fills in a magic square of 
                           length 3, 5 or 7.
    */

   //local constants
   const int BOTTOM_ROW = length - 1;
   const int LEFT_COLUMN = 0;

   //local variables
   int Numbers_Placed = 0;
   int Placement_Number = 1;
   int Numbers_To_Be_Placed;
   int Column_Starting_Position;

   /*********************** start Magic_Function function ***********************/

   //calculate amount of numbers that need to be placed to fill the magic square
   Numbers_To_Be_Placed = pow(length, 2); //cmath library :-)

   //Calculate the starting column of 1 in the magic square
   Column_Starting_Position = length / 2;

   //loop that will fill the magic square; 'if' statements constitute all rules and situations
   for(int i = 0, j = Column_Starting_Position; Numbers_Placed < Numbers_To_Be_Placed; Numbers_Placed++)
   {
    if((Magic_Square[i][j] == 0) && (i>=0) && (j<length))
    {
        Magic_Square[i][j] = Placement_Number;
        Placement_Number++;
        i--;
        j++;
    }
    else if((i<0) && (j<length) && (Magic_Square[BOTTOM_ROW][j] == 0))
    {
        i = BOTTOM_ROW;
        Magic_Square[i][j] = Placement_Number;
        Placement_Number++;
        i--;
        j++;
    }
    else if((i>=0) && (j==length) && (Magic_Square[i][LEFT_COLUMN] == 0))
    {
        j = LEFT_COLUMN;
        Magic_Square[i][j] = Placement_Number;
        Placement_Number++;
        i--;
        j++;
    }
    else if((Magic_Square[i][j] != 0) || ((i<0) && (j==length)))
    {
        i+=2; //moves the placement position down two rows
        j--;  //moves the placement postion to the left one column
        Magic_Square[i][j] = Placement_Number;
        Placement_Number++;
        i--;
        j++;
    }
   }
}

void Display_Square(int Square[7][7], int length)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 9/22/22
    Date of last revision: 9/28/22
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : This function displays a magic square
    */
   
    /*********************** start Display_Square function ***********************/

    cout << "Magic Square!" << "\n\n";
    for(int row = 0; row<length; row++)
    {
        for(int column = 0; column<length; column++)
        {
            if(Square[row][column] > 9)
                cout << Square[row][column]<<" ";
            else
                cout << Square[row][column]<<"  ";
        }
        cout << endl;
    }
    cout << "\n";
}

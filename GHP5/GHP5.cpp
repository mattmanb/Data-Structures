#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;
char StackStringToChar(stack<string> Word_Stack);
char QueueStringToChar(queue<string> Word_Queue);

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 11/15
    Date of last revision: 11/15
    Language             : C++
    Compiler             : gcc
    Citations            : 
    Program Description  : Modify the basic assignment so it queries the user for 
                           the name of a file containing one word per line. Open 
                           that file, process each word using basic stack and queue 
                           operations to determine if it is a palindrome, and if 
                           so, print it. At the end report the total number of 
                           palindromes found and the total number of words processed. 
                           Also keep track of the number of palindromes containing 
                           the letter z (irrespective of case), and the length of 
                           each palindrome containing a z. At the end display the 
                           number of these palindromes and all of them sharing the 
                           longest length. Thus, if the longest palindrome containing 
                           a z is seven characters long, all seven character 
                           palindromes containing a z must be displayed.

    */

    //local constants

    //local variables
    int Pali_Counter = 0;
    int Word_Counter = 0;
    int Z_Pali_Counter = 0;
    int Longest_Z_Pali = 0;
    stack<string> Z_Stack; 
    string File_Name;
    string Current_Word;
    string R_Current_Word;
    stack<string> Word_Stack;
    queue<string> Word_Queue;
    bool Is_Pali;
    bool Z_Word;

    /*Start Main Program*/

    cout<<"\n";

    //instantiates file input steam
    ifstream fileIn;

    //Query the user for the file name
    cout << "Enter file name: ";
    cin >> File_Name;

    //Attempts to open file; crashes if file is not opened
    fileIn.open(File_Name.data());
    assert(fileIn.is_open());

    //While there are words left
    while(fileIn >> Current_Word)
    {
        //Increment Word Counter
        Word_Counter++;

        //Assume the current word is a palindrome
        Is_Pali= true;

        //Assume the word doesn't have a z until proven otherwise
        Z_Word = false;

        /*Insert the current word onto a stack and into a queue, as well as
        check to see if the current word contains a z*/
        for(int i = 0; i<Current_Word.length(); i++)
        {
            Word_Stack.push(Current_Word.substr(i,1));
            Word_Queue.push(Current_Word.substr(i,1));
            if(Current_Word.substr(i,1)=="z")
            {
                Z_Word=true;
            }
        }

        //Check to see if the word is a palindrome (and remove all chars from stack/queue)
        for(int i = 0; i<Current_Word.length(); i++)
        {
            if(toupper(StackStringToChar(Word_Stack))==toupper(QueueStringToChar(Word_Queue)))
            {
                Word_Stack.pop();
                Word_Queue.pop();
            }
            else
            {
                Is_Pali=false;
                Word_Stack.pop();
                Word_Queue.pop();
            }
        }
        //Increment Palindrome counter and check for Z
        if(Is_Pali)
        {
            //Output the palindrome
            cout << Current_Word << endl;

            //Increment Palindrome counter
            Pali_Counter++;

            //Search for palindromes with 'z' in them
            if(Current_Word.find("z")<Current_Word.length() || Current_Word.find("Z")<Current_Word.length())
            {
                //Increment Palindromes with z counter
                Z_Pali_Counter++;

                //Check to see if this 'z' palindrome is the longest
                if(Current_Word.length()>Longest_Z_Pali)
                {
                    //Set Longest_Z_Pali to the new value
                    Longest_Z_Pali = Current_Word.length();

                    //empty out the stack of the longest 'z' palindromes
                    while(!Z_Stack.empty())
                    {
                        Z_Stack.pop();
                    }
                    //Add the new longest 'z' palindrome to the stack
                    Z_Stack.push(Current_Word);
                }
                else if(Current_Word.length()==Longest_Z_Pali)
                {
                    Z_Stack.push(Current_Word);
                }
            }
        }
    }
    //Display words processed, number of palindromes, and number of 'z' palindromes
    cout << "\n\n" << "Words Processed        : " << Word_Counter;
    cout << "\n" <<   "Palindromes Found      : " << Pali_Counter;
    cout << "\n" <<   "'z' Palindromes Found  : " << Z_Pali_Counter;

    //Display all of the longest 'z' palindromes
    cout << "\n" <<   "Longest 'z' Palindromes:"<<"\n";
    while(!Z_Stack.empty())
    {
        cout << "\n" << Z_Stack.top();
        Z_Stack.pop();
    }
    cout << "\n\n";

    return 0;
}

char StackStringToChar(stack<string> Word_Stack) {
    string Separate_String = Word_Stack.top();
    char Char_Value = Separate_String[0];
    return Char_Value;
}

char QueueStringToChar(queue<string> Word_Queue) {
    string Separate_String = Word_Queue.front();
    char Char_Value = Separate_String[0];
    return Char_Value;
}

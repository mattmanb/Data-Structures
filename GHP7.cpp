#include <iostream>
#include <string>

using namespace std;

class Hash_Container {
    public:
    //constructor function
    Hash_Container() {
        //fill the Hash_Container with 0's to help find empty spots later
        for(int i = 0; i<15; i++)
        {
            Hashed_Array[i] = "0";
        }
    }

    //This function hashes the passed word and places it into the local Hashed_Array
    void insert(string Word) {
        int i = 0;              //used to help stay inside Hashed_Array's bounds
        bool inserted = false;  //true when word is successfully inserted into Hashed_Array
        int Placement_Pos;      //Position hash points to

        //Hash the Word
        Placement_Pos = ((int)Word[0] + (int)Word[Word.length()-1] - (int)Word[1]) % 15;

        //Insert the Word
        while(!inserted)
        {
            if(Hashed_Array[(Placement_Pos + i) % 15].compare("0") == 0)
            {
                Hashed_Array[(Placement_Pos + i) % 15] = Word;
                inserted = true;
            }
            else
            {
                i++;
            }
        }
    }

    bool find(string Search_Word) {
        /**********************************************/
        /* This function returns the bool value of    */
        /* determining if the word was found          */
        /**********************************************/
        int Word_Hash = 0;  //hash position
        bool found = false; //true if found, stays false if not

        //Hash the Search_Word
        Word_Hash = ((int)Search_Word[0] + (int)Search_Word[Search_Word.length()-1] - (int)Search_Word[1]) % 15;
        
        //Look for the word
        while((Hashed_Array[Word_Hash] != "0") && !found)
        {
            if(Hashed_Array[Word_Hash]==Search_Word)
            {
                found = true;
            }
            else
            {
                Word_Hash= (Word_Hash + 1) % 15;
            }
        }
        return found;
    }

    //This functions displays every element (including empty spaces of the 
    //local Hashed_Array on a newline
    void display()
    {
        for(int i = 0; i<15; i++)
        {
            if(Hashed_Array[i] != "0")
            {
                cout << Hashed_Array[i] << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }

    private:
    string Hashed_Array[15]; //array where hashed values are stored./
};

int main(void)
{
    /*
    Author               : Matthew Barrington
    Date of creation     : 12/6
    Date of last revision: 12/6
    Language             : C++
    Compiler             : gcc
    Citations            :
    Program Description  : Query the user for 10 strings, and store them into a container
                           using a hash class. The hash class will sort on the basis of:
                           (first letter + last letter - second letter) % 15
                           Then display the contents of the container, including the 
                           empty spaces. 
    */

   //local constants
   const string QUIT_VALUE = "-99";

   //local variables
   Hash_Container Storage;  //Hash_Container object from Hash_Container class
   string Word;             //Current word to be entered into the Hash_Container
   string Search_Word;      //Current word to be searched for in the Hash_Container

   /* Start driver */
   //Query user for 10 strings and insert via hashing using Hash_Container class
   cout << "\nEnter 10 strings:" << endl; 
   for(int i = 0; i<10; i++)
   {
    cout << "Enter string " << i + 1 << ": ";
    cin >> Word;
    Storage.insert(Word);
   }

   //display the contents of the hashed container
   cout << "\n";
   Storage.display();

   //query the user for a search word
   cout << "\nEnter a word to search for in the hash container (-99 to quit): ";
   cin >> Search_Word;

   //While the quit value isn't entered:
   while(Search_Word!=QUIT_VALUE)
   {
    if(Storage.find(Search_Word))
    {
        cout << Search_Word << " was found!" << endl;
    }
    else
    {
        cout << Search_Word << " was not found." << endl;
    }
    cout << "\nEnter a word to search for in the hash container (-99 to quit): ";
    cin >> Search_Word;
   }
}
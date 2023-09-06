/********************************************************************
 *Program Name   :   Program 1
 *Author         :	 Matt Barrington
 *Date           :	 4/1/22
 *Course/Section :   CSC110-302
 *Program Description: The local credit union is offering 1.75% annual 
 *   interest on a certificate of deposit.  Input the amount of the 
 *   initial deposit for an account. Then calculate and display the 
 *   amount of interest earned and the balance for the next 5 years.  
 *   Repeat the process until a sentinel value is entered for the 
 *   initial deposit.  The interest earned is the balance * the interest 
 *   rate. Remember that the user could quit without entering any 
 *   initial deposits.
 *
 * BEGIN Calc interest (program 1)
 *    Input balance (or quit)
 *    Clear screen
 *    WHILE(balance is not quit)
 *       FOR(years to calculate)
 *          Calc interest
 *          Calc new balance
 *          Display balance
 *          Display interest 
 *       END FOR
 *       Input balance (or quit)
 *		 Clear screen
 *    END WHILE
 * END Calc interest (program 1)
  ********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(void)
{
	//local constants
	const int QUIT = -99;
	const int MAX_YEARS = 5;
	const double INTEREST_RATE = .0175;
	const int NUM_DECIMAL = 2;
	
	//local variables
	double balance;              							 //initial amount entered by user as well as new balances after interest for each year
	double interest;            							 //dollar amount for the interest of each year
	cout << showpoint << fixed << setprecision(NUM_DECIMAL);

	/**************************start main program*********************/
	
	//Input balance (or quit)
	cout << "\n\n\n\t" << "Enter initial deposit (-99 to quit): ";
	cin >> balance;
	
	//Clear screen
	system("cls");
	
	//WHILE(balance is not quit)
	while(balance != QUIT)
	{
		//FOR(years to calculate)
		for(int years = 0; years < MAX_YEARS; years++)
		{
			//Calc interest
			interest = balance * INTEREST_RATE;
			
			//Calc new balance
			balance += interest;
			
			//Display balance
			cout << "\n\n\t" << "Balance : " << balance;
			
			//Display interest 
			cout << "\n\t" << "Interest: " << interest;
			
		} //END FOR
		
		//Input balance (or quit)
		cout << "\n\n\n\t" << "Enter initial deposit (-99 to quit): ";
		cin >> balance;
		
		//Clear screen
		system("cls");
		
	} //END WHILE

	//return 0 to the operating system
    return 0;

}   //End main program

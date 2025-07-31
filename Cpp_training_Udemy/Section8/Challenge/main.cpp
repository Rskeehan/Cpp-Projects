// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main() {
	// Declare variables for each denomination and initialize them to zero
	int dollars {0};
	const int cents_per_dollar {100};
	int quarters {0};
	const int cents_per_quarter {25};
	int dimes {0};
	const int cents_per_dime {10};
	int nickels {0};
	const int cents_per_nickel {5};
	int pennies {0};
	const int cents_per_penny {1};

	int RemainingCents {};
	
	int cents {};
	cout << "Enter an amount in cents: ";
	cin >> cents;

	// Calculate the number of dollars, quarters, dimes, nickels, and pennies

	dollars = cents / cents_per_dollar; // Calculate dollars
	RemainingCents = cents %= (dollars * cents_per_dollar); // Calculate remaining cents after dollars

	quarters = RemainingCents / cents_per_quarter; // Calculate quarters
	RemainingCents %= cents_per_quarter; // Calculate remaining cents after quarters

	dimes = RemainingCents / cents_per_dime; // Calculate dimes
	RemainingCents %= cents_per_dime; // Calculate remaining cents after dimes

	nickels = RemainingCents / cents_per_nickel; // Calculate nickels
	RemainingCents %= cents_per_nickel; // Calculate remaining cents

	pennies = RemainingCents / cents_per_penny; // Calculate pennies

	//display the results

	cout << "You can provide this change as follows:" << endl;
	cout << "dollars    : " << dollars << endl;
	cout << "quarters : " << quarters << endl;
	cout << "dimes     : " << dimes << endl;
	cout << "nickels   : " << nickels << endl;
	cout << "pennies  : " << pennies << endl;

    cout << endl;
    return 0;
}



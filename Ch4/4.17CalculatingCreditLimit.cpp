#include <stdio.h>
#include <math.h>

// Calculating Credit Limits //

/* write a program that analyzes the credit status of three customers of a company. 
* the company decides to cut its customers' credit limits by 50%.
* for each customer, you're given:
*	a) the customer's account number
*	b) the customer's credit limit before the recession
*	c) the customer's current balance
* 
* the program should calculate and print the new credit limit for each customer
* and determine (and print) which customers have balances that exceed ther new
* limits. the program should analyze three customers.
*/

int main(void) {

	// print header for columns 
	printf("Account Number %10s New Credit Limit %10s Credit Balance\n\n", "", "");

	// decided to research how to initialize and loop through an array 
	int account_numbers[] = { 7484, 3783, 2783 }; 
	int old_credit_limit[] = { 12000, 48000, 4000 };
	int current_balance[] = { 8000, 12000, 3000 };
	int difference[3] = {  }; // array for calculating which account is over the credit limit

	int total_customers = 3; // unnecessary, I could just use '3' in the loop, but thought this was a better way to create scalability
	
	// loops through accounts, calculates new limits, and calculates the difference between old and new limits
	for (int counter = 0; counter < total_customers; counter++) { 

		difference[counter] = (old_credit_limit[counter] / 2) - current_balance[counter]; // difference is old / 2 minus balance
				
		// prints data in columns
		printf("%d %20s %d %20s %d\n", account_numbers[counter], "", (old_credit_limit[counter] / 2), "", (difference[counter])); 

		// if the difference is over ther limit, print a flag for that account number
		if ((difference[counter]) < 0) {
			printf("Flag %d for being over limit.\n\n", account_numbers[counter]);
		}
	}
	return 0;

}

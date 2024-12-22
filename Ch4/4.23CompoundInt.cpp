#include <stdio.h>
#include <math.h>

// Calculating the Compound Interest with Integers //

/* modify the program of 4.4 (in textbook) so that it uses only
integers to calculate the compound interest. treat all monetary
amounts as integral numbers of pennies. then "break" the result into
its dollar portion and cents portion by using the division and remainder
operations, respectively. */

/* author note: the textbook does not use an algebraically complete
depiction of calculating compound interest. this program uses
their forumla */


int main(void) {

	// initial principal deposit
	int principal = 1000; 

	// interest percentage rate
	int rate = 5;
	
	// total pennies, used to separate pennies from dollars in loop
	int total_pennies = principal * 100; 
	
	// prints column header
	printf("%4s%21s%21s\n", "Year", "Deposit Dollars", "Deposit Cents");

	// loop, cycles through "10" years of interest
	for (int year = 1; year <= 10; ++year) {

		// updates value in total_pennies
		total_pennies = total_pennies + (total_pennies * rate) / 100; 

		// divides off dollar amount
		int updated_amount = total_pennies / 100; 

		// takes last two values in total_pennies to print the "cent" value
		int cents = total_pennies % 100;	

		printf("%4d %20d%21d\n", year, updated_amount, cents);   
		
	}
}

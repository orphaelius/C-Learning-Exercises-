#include <stdio.h>

// Develop a C program to calculate the interest accrued on a bank customer's mortgage. For each customer, the following facts are available;
//	a) the mortgage amount
//	b) the mortgage term
//	c) the interest rate

// The program should input each fact, calculate the total interest payable, and add it to the mortgage amount to get the total amount payable. 
// It should calculate the required monthly payment by dividing the total amount payable by the number of months in the mortgage term. the program
// should display the required monthly payment. the program should process each customer's account at a time. 

int main(void) {
	// initialize variables
	int mortgage_amount = 0;
	int mortgage_term = 0;
	float interest_rate = 0;

	/* input each fact -
	* with sentinel value to abort
	* calculate total interest payable -
	* add it to mortgage amount -
	* yields total amount payable -
	* divides total amount payable by mortgage term values -
	* display the required monthly payment - 
	* process single account per time
	* output all information	
	*/

	// display message for user input, gather user input, store input into variables
	printf("Please enter the total mortgage amount: \n");
	scanf("%d", &mortgage_amount);

	printf("Please enter the mortgage term, in years: \n");
	scanf("%d", &mortgage_term);

	printf("Please enter the interest rate: \n", interest_rate);
	scanf("%f", &interest_rate);

	// calculations
	interest_rate /= 100;
	int number_of_payments = mortgage_term * 12; // years of mortgage times number of months in a year to calculate total amount of monthly payments
	float total_interest_owed = mortgage_amount * interest_rate * mortgage_term; // mortgage amount times interest rate = total interest owed over term
	float lifetime_total_owed = mortgage_amount + total_interest_owed; // mortgage amount plus total interest = total amount owed
	float monthly_payment = lifetime_total_owed / number_of_payments; // monthly payment = total amount owed / number of payments

	// output information
	printf("The monthly payment for your loan is %f, to be paid out over %d months.\n", monthly_payment, number_of_payments);

	return 0;
}

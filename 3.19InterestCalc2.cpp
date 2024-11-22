#include <stdio.h>

/* Develop a program that uses scanf to input principal, rate, and days for several loans.
* The program should calculate and display the simple interest for each loan using the following formula:
* interest = principal * rate * days / 365
*/


int main(void) {

	// initialize variables
	int principal = 0;
	float rate = 0.0;
	int days = 0;
	float interest_charge = 0.0;

	
	// display initial promp/ask for input, take input, store input
	// create while loop, add sentinel value of -1
	// calculate interest charge on loan
	// display message of loan details including interest charge each cycle
	// iterate until sentinel value is entered
	printf("%s", "Enter the loan principal amount (enter '-1' to exit): \n");	

	while (1) {				
		
		scanf("%d", &principal);

		if (principal == -1) {
			break;
		}

		printf("Enter the interest rate: \n");
		scanf("%f", &rate);
		printf("Enter the length of the loan in days: \n");
		scanf("%d", &days);
		
		interest_charge = (principal * rate * days) / 365;

		printf("Loan Principal: $%d\n", principal);
		printf("Interest Rate: %.2f percent\n", rate);   
		printf("Term of Loan: %d days\n", days); 
		printf("Total Interest Charge: $%.2f\n", interest_charge); 

		// re-iterate prompt message to user
		printf("%s", "Enter the loan principal amount (enter '-1' to exit): \n");
		
	}
	return 0;
}
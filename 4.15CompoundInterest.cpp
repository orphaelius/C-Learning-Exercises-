#include <stdio.h>
#include <math.h>

// Modified Compound Interest Program //

/* modify the compound interest program of section 4.5 to repeat
* its steps for interest rates of 5%, 6%, 7%, 8%, 9%, and 10%.
* use a for loop to vary the interest rate */

int main(void) {

	double principal = 1000.0;
	double rate = 0.05;

	printf("%4s%21s\n\n", "Year", "Amount on Deposit");

	for (rate = 0.05; rate <= 0.1; rate = rate + 0.01) {
		printf("Rate: %.2f \n", rate);

		for (int year = 1; year <= 10; ++year) {
			double amount = principal * pow(1.0 + rate, year);
			printf("%4d%21.2f\n", year, amount);			
		}				
		puts("");			
	}
}


#include <stdio.h>
#include <math.h>

// Recursive Exponentation //

int recursiveExponentation(int base, int power); // Function prototype

int base = 0; // Both for user input
int power = 0;

int main(void) { // Main function
	printf("Enter the base:\n");
	scanf("%d", &base);
	printf("Enter the exponent:\n");
	scanf("%d", &power); 

	recursiveExponentation(base, power); // Function call

	return 0;
}

int recursiveExponentation(int base, int power) { // Recursive exponentation function. 

	int tempCalc = 0; // Variable for calculating exponential iteration and return value

	for (int i = power; i > 0; i--) { // Decrements through input power until reaching 1

		tempCalc = pow(base, i); 

		if (pow(base, i) == base) { // If current power is 1, print 
			printf("%d to the power of 1 is equal to the %d.\n", base, base); 
			return 0;
		}

		else { // Print each exponential calculation until if statement is true
			printf("%d to the power of %d is: %d\n", base, power, tempCalc);  
		}
	}

	return tempCalc;   
}
#include <stdio.h>

// a prime number is any natural number greater than 1 that is divisible only by 1 and itself. write a c program that reads an integer, 
// and determines whether it is a prime number or not

int main(void) {
	// initialize variables
	int num = 0; // user input number to test
	int i = 2; // test divisor, greater than 1, starting a 2. will increment.
	int prime = 0; // initialized to calculate how many factors are found (how many numbers divide num evenly)

	// prompt for user input
	printf("Enter any natural number and I will determine whether it is prime or not: \n");
	scanf("%d", &num);  

	// check if number is 2 before running loops
	if (num == 2) {
		printf("The number %d is prime.\n", num);
	}

	// if number is not 2, run additional conditions
	// while i is less than the input number:
	// check if remainder is 0. if remainder is 0, 
	else {

		while (i < num) {
			// if num is divisible by i, starting at 2. if true, it meants num has a divisor other than 1 and itself.
			if (num % i == 0) { 
				// if remainder is 0, it increments prime (searching for remainder of 1)
				prime++;
			}
			// increments test divisor (searching for remainder of 1)
			i++;  
		}
		
		// checks how many divisors were found. if none, the number is prime
		// display results
		if (prime == 0) { 
			printf("The number %d is prime.\n", num);
		}

		else {
			printf("The number %d is not prime.\n", num);
		}

	}

	
		
}

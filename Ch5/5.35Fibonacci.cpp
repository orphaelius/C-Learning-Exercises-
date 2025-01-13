#include <stdio.h>
#include <math.h>

// Fibonacci //

int n = 0;

unsigned long long fibonacci(int n); // Function prototype

int main(void) { // Main function
	printf("Enter the nth number in the Fibonacci Sequence you'd like to return:\n"); // Display/request nth place in Fibonnaci sequence to return
	scanf("%d", &n);

	if (n < 0) { // If user input is less than zero, return error code
		printf("That is not a valid entry.\n");		
	}

	else {
		printf("That fibonacci number is %llu", fibonacci(n)); // Function call 
	}
}

unsigned long long fibonacci(int n) { // Fibonnaci sequence function	

	unsigned long long num1 = 0;
	unsigned long long num2 = 1;
	unsigned long long fibSum = 0; 

	for (int i = 0; i <= n; i++) { // Iterate to calculate Fibonacci "sum"

		if (n == 0) { // If input is 0, return 0
			return 0;
		}

		if (n == 1) { // If input is 1, return 1
			return 1;
		}
		
		if (n == 2) {
			return 1;
		} 		
		 
		if (i == 0) { // Debugging
			// printf("fib(0) = 0\n");
		}
			
		else if (i == 1) { // Debugging
			// printf("fib(1) = 1\n");
		}				
			
		else {

			fibSum = num1 + num2;
			// printf("fibonacci (%d) = %llu\n", i, fibSum); // For debugging
			num1 = num2;
			num2 = fibSum;
		}	
			
	} 

	return fibSum; 
}
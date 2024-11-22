#include <stdio.h>

// Factorial //



/* a) write a program that reads a non-negative integer and computes and prints its factorial
* 
* b) write a program that estimates the value of the mathematical constant e by using the formula:
*	e = 1 + 1/1! + 1/2! + 1/3! etc (1 / 1, 1 / (2 * 1), 1 / (3 * 2 * 1))
* 
* c) write a program that computes the value of e^x by using the formula:
*	e^x = 1 + x/1! + x^2/2! + x^3/3! etc
*/




int main(void) {
	int num = 0;
	int factorial = 1;
	int product = 1;	

	// Example A // 
	
	// while loop that decrements an input number from input n to 1
	// multiply input number by (input number - 1) (ie, 5 * 4, 3 * 2, etc)
	// product equals first calculation times following calculation etc, decrementing to 1 
	// example formula: n! = n × (n - 1) × (n - 2) × (n - 3) × ... × 1		

	printf("Enter a non-negative integer and I will print the product of its factorials: \n");
	scanf("%d", &num); 	
	
	while (num > 1) { // num needs to be greater than 1. multiplying by 0 will yield 0.	
		// printf("temp num is: %d\n", num);				

		factorial = num * (num - 1);
		// printf("factorial is: %d\n", factorial);		

		num--; 

		product *= factorial; 
			 	

		num--;		
	}	
	printf("The product is: %d\n\n", product);
	
	return 0;
		

}
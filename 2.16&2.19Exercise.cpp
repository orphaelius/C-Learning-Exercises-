#include <stdio.h>

int main(void) {
	// arithmetic. write a program that reads two integers from the user then displays their sum, product, difference, quotient, and remainder.
	int num1 = 0;
	int num2 = 0;

	// prompt user for integers, take integer input
	printf("Enter your two integers, user: ");
	scanf("%d %d", &num1, &num2);
	
	
	int sum = num1 + num2;
	int average = (num1 + num2) / 2;
	int prod = num1 * num2;
	// int diff = num1 - num2;
	// int quot = num1 / num2;
	// int remainder = num1 % num2;
	

	int smallest = 0;
	int largest = 0;

	
	printf("The sum of your integers is: %d\n", sum);
	printf("The product of your integers is: %d\n", prod);
	// printf("The quotient of your integers is: %d\n", quot);
	// printf("The difference of your integers is: %d\n", diff);	
	// printf("The remainder of your integers is: %d\n", remainder);
	printf("The average of your integers is: %d\n", average);

	if (num1 < num2) {
		int smallest = num1;
		int largest = num2;
		printf("%d is the smallest integer\n", num1);
		printf("%d is the largest integer\n", num2);
	}

	if (num1 > num2) {
		int smallest = num2;
		int largest = num1;
		printf("%d is the smallest integer\n", num2);
		printf("%d is the largest integer\n", num1);
	}

}
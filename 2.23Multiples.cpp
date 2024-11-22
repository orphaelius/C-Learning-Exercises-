#include <stdio.h>

// Write a program that reads two integers and determines and displays whether the first is a multiple of the second.
// Use the remainder operator

int main(void) {

	// initialize variables
	int number1 = 0;
	int number2 = 0;

	printf("Enter two numbers. I will determine whether the first is a multiple of the second: \n");
	scanf("%d %d", &number1, &number2);

	int multiple = number2 % number1;

	if (multiple == 0) {
		printf("%d is a multiple of %d", number1, number2);
	}

	if (multiple != 0) {
		printf("%d is not a multiple of %d", number1, number2);
	}



}
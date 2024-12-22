#include <stdio.h>

int main(void) {

	//2.4 and 2.5 Exercises

	// a) State that a program will calculate the product of 3 integers
	printf("This program will calculate the product of three integers...\n");

	// b) Prompt the user to enter 3 integers
	printf("O' fated user, dare to enter three integers: \n");
	
	// c) Define the variables x, y, and z to be of type int and initialize to 0
	int x = 0;
	int y = 0;
	int z = 0;

	// d) Read 3 integers from the keyboard and store them in variables x, y, and z
	scanf("%d %d %d", &x, &y, &z);

	// e) Define the variable results, compute the product of the integers in the variables x, y, and z, and use that product to initialize the variable result
	int result = x * y * z;

	// f) Display "The product is" followed by the value of the int variable result
	printf("The product of your three integers, dear user, is: %d\n", result);

	// end function
}

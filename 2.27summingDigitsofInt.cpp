#include <stdio.h>

// Write a program that inputs one 4-digit number, sums each of the individual digits, and displays the result. Use division and remainder operator). 
// HINT: Use division and remainder operator. i.e., 3 + 5 + 8 + 1 = 17

int main(void) {

	// initialize variable
	int initial_dig = 0;

	// request user input
	printf("Enter any 4-digit integer and I will determine the total sum of each individual digit: \n");
	scanf("%d", &initial_dig);

	// break 4-digit integer into smaller integers. 'int' does not return decimals:
	int dig_four = initial_dig % 10; // yields remainder of 1
	int dig_three = (initial_dig / 10) % 10; // yields remainder of 8
	int dig_two = (initial_dig / 100) % 10; // yields remainder of 5
	int dig_one = (initial_dig / 1000) % 10; // yields remainder of 3

	// add up each digit integer:
	int sum = dig_four + dig_three + dig_two + dig_one;

	printf("%d", sum);
	
	return 0;
}




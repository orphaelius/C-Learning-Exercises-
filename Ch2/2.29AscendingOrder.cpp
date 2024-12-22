#include <stdio.h>

// Write a program that inputs three different numbers from the user. Display the numbers in increasing order.
// An if statement's body can contain more than one statement
// Prove that it works by running it on all six possible orderings of the numbers. Does it work with duplicate numbers?

int main(void) {

	// initialize variables
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	// request input from user
	printf("Enter 3 different numbers and I will sort them in ascending order: \n");
	scanf("%d %d %d", &num1, &num2, &num3);

	// possible combinations:
	/* num1, num2, num3
	* num1, num3, num2
	* num2, num1, num3
	* num2, num3, num1
	* num3, num1, num2
	* num3, num2, num1
	
	*/

	if (num1 < num2 && num1 < num3 && num2 < num3) {
		int first = num1;
		int second = num2;
		int third = num3;

		//print this bad boy
		printf("The numbers in ascending order are: %d %d %d", num1, num2, num3);
	}

	if (num1 < num2 && num1 < num3 && num3 < num2) {
		int first = num1;
		int second = num3;
		int third = num2;

		//print this bad boy
		printf("The numbers in ascending order are: %d %d %d", num1, num3, num2);
	}

	if (num2 < num1 && num2 < num3 && num1 < num3) {
		int first = num2;
		int second = num1;
		int third = num3;

		//print this bad boy
		printf("The numbers in ascending order are: %d %d %d", num2, num1, num3);
	} 

	if (num2 < num1 && num2 < num1 && num3 < num1) {
		int first = num2;
		int second = num3;
		int third = num1;

		//print this bad boy
		printf("The numbers in ascending order are: %d %d %d", num2, num3, num1);
	} 

	if (num3 < num1 && num3 < num2 && num1 < num2) {
		int first = num3;
		int second = num1;
		int third = num2;

		//print this bad boy
		printf("The numbers in ascending order are: %d %d %d", num3, num1, num2);
	}

	if (num3 < num1 && num3 < num2 && num2 < num1) {
		int first = num3;
		int second = num2;
		int third = num1;

		//print this bad boy
		printf("The numbers in ascending order are: %d %d %d", num3, num2, num1);
	}

	return 0;

}

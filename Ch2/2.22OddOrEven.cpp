#include <stdio.h>

// Write a program that reads an integer then determines and displays whether it's odd or even. Use the remainder operator.
// an even number is a multiple of two. Any multiple of two leaves a remainder of zero when divided by two.


int main(void) {
	int number1 = 0;

	printf("Enter any number and I will determine whether it is even or odd: \n");
	scanf("%d", &number1);

	int new_num = (number1 % 2);
	
	if (new_num == 0) {
		printf("%d is an even number!", number1);
	}

	if (new_num != 0) {
		printf("%d is an odd number!", number1);
	}

	return 0;




}

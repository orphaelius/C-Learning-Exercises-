#include <stdio.h>

// write a program that reads in the side of a square (length in units) and then prints that square
// out of asterisks. your program should work for squares of all side sizes between 1 and 20.

/*
* initialize variables
* print initial input prompt
* add sent value
* scanf to take input (between 1 and 20 only)
* calculate the size of square and print asterisks




*/

int main(void) {
	int square_len = 0;	
	
	printf("Enter a number between 1 and 20 and I will build an asterisk box (-1 to stop): \n");
	scanf("%d", &square_len); 

	if (square_len == 1 || square_len >= 20) {
		printf("That is not a valid number...");
	}

	if (square_len > 1 && square_len < 20) {
		int counter_one = 1;
		while (counter_one <= square_len) {

			if (square_len == -1) {
				break;
			}
			printf("*");

			int counter_two = 1;
			while (counter_two < square_len) {
				printf("*");
				counter_two++;
			}

			counter_one++;
			printf("\n");

		}
	}
}

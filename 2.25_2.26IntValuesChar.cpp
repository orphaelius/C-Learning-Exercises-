#include <stdio.h>

// 2.25 Write a C program that takes in a letter from user input, and displays both the letter and the integer representation of the letter. For example, 
// if the input is 65, the output should be '65 = A.'

// 2.26 Inverse version of 2.25. Write a program that takes an integer from user input and displays the letter or character representation of that integer.

// Combined both exercises.

int main(void) {

	char letter;
	int integer = 0;

	// take input
	printf("Enter any letter followed by any integer, and I will return the integer representation of that letter and the character representation of that integer: \n");
	scanf("%c %d", &letter, &integer);

	// represent character value as integer and integer value as character
	int rep_letter = letter;
	char rep_integer = integer;

	// print result
	printf("The integer representation of %c = %d.\nThe character representation of %d = %c.\n", letter, rep_letter, integer, rep_integer);



	
}
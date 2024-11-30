#include <stdio.h>

// ASCII Values //

/* write a program to convert and print the characters for the
ASCII values 0 to 127. print 10 characters per line.*/

// main function
int main(void) {

	printf("This program prints all ASCII values from 0 through 127.\n\n");  
	
	// main loop, iterates 0 through 127, incrementing by 1 at each iteration
	for (int counter = 0; counter <= 127; counter++) {	

		// this statement evaluates the value of the counter. ASCII values are decimal values from 0 - 32, 
		// so printing only using a %c format specifier for all values skips through these initial decimal values
		// i've included an else statement to print the initial decimal values
		if (counter >= 32 && counter <= 127) {
			printf("%c ", counter); 

		} else { 
			printf("%d ", counter);
		}	

		// this takes the value of counter, divides by 10, and checks remainder
		// using a remainder of 9 prints a newline character since values begin 
		// at 0
		if (counter % 10 == 9) {
			puts("");
		}			
	}	
}

// i originally designed this program to work with an array, using a loop to push
// values into the array and then using a counter to print those values at certain
// increments. after successfully printing out the ascii values, i looked online
// to see what could be improved about the code. i had overlooked the simplicity
// of using the counter value to print, really optimizing the amount of 
// code necessary to reach the same solution. 
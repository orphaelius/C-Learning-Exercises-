#include <stdio.h>
#include <math.h>

// Table of Decimal, Binary, Octal, and Hexadecimal Equivalents //

/* write a program that prints a table of the binary, octal, and
 hexidecimal equivalents of the decimal numbers 1- 256. hint:
 you can display an integer as an octal or hexadecimal value
 with the conversion specifications %o and %X respectively */

int main(void) {

	// initialize binary value array. holds (up to) 8 digits because a byte is 8 digits long. 
	int bin[8] = {};

	// print header for the columns
	printf("%s %20s %20s %20s\n", "Decimal Value", "Hexidecimal Value", "Octal Value", "Binary Value");

	// main loop
	for (int i = 0; i < 256; i++) {
		int decimalValue = i;				
		
		// initialize the binary position to perform operations upon.
		int binaryPosition = 7;

		// loop to convert decimal number to binary by calculating the remainder and dividing by 2		
		while (decimalValue > 0 && binaryPosition >= 0) {   
			bin[binaryPosition] = decimalValue % 2;   
			decimalValue = decimalValue / 2; 
			binaryPosition--;   
		} 

		// displays results for decimal, hex, and octal
		printf("%-16d %-26X %-20o", i, i, i); 

		// loops through the binary array and prints each position value
		for (int k = 0; k < 8; k++) {
			printf("%d", bin[k]);
		}

		// new line for next iteration!
		printf("\n");
		
	}

	return 0;
}

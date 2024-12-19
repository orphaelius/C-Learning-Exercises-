#include <stdio.h>

// Roman-Numeral Equivalent of Decimal Values //

/* write a program that prints a table of the Roman
Numeral equivalents for the decimal numbers in the
range of 1 to 100. */


int main(void) {
	int i = 0; // main loop counter to loop through decimal values
	int numeral = 0; // primary roman numeral counter for iterating through values
	
	printf("%s %30s\n", "Decimal Value", "Roman Numeral Equivalent"); // main header
	
	for (i = 1; i <= 100; i++) { // loops from 1 to 100
		printf("%-20d", i); // prints current decimal value

		numeral = i; // sets numeral value to current counter value		
		
		if (numeral == 100) { // if numeral value is 100, print c, reset value to 0 to skip remaining statements
			printf("C");
			numeral = 0;
		} 

		if (numeral >= 90) { // prints XC for values 90-98, reduces value by 90
			printf("XC");
			numeral -= 90;
		}

		if (numeral >= 50) { // prints L for values 50-88, reduces value by 50
			printf("L");
			numeral -= 50;
		}
		
		if (numeral >= 40) { //  prints XL for 40-48, reduces value by 40
			printf("XL");			
			numeral -= 40;			
		}

		while (numeral >= 10) { // for any values over 10-38, print X and reduce by 10
			printf("X");			
			numeral -= 10;
		}

		if (numeral >= 5) { 
			if (numeral % 10 == 9) { // print IX for any value that ends in 9
				printf("IX");				
				numeral -= 9;
			}
			else {
				printf("V"); // print V for any value that is 5			
				numeral -= 5;
			}
		}

		// loops through numeral value. prints IV for any number that ends in 4
		// prints I for any numeral value that doesn't trigger above statements
		// values 1 - 3; 6 - 8
		while (numeral > 0) {
			if (numeral % 10 == 4) {
				printf("IV");
				numeral -= 4;				
			}
			else {
				printf("I");
				numeral -= 1;
			}
		}		
		printf("\n");
	}
}
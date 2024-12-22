#include <stdio.h>

// Diamond Printing Program //

/*write a program that prints a diamond shape (drawn below).
your printf statements may print either one asterisk (*) or
one blank. use nested for statements and minimize the number
of printf statements. */

/*         *
*		  ***
*		 *****
*	    *******
*	   *********
*		*******
*	     *****
*	      ***
*	       *
*/


int main(void) {
	int rows = 10;


	// Top Half //
	for (int counter = 1; counter <= rows; counter++) {


		// Top Left Quadrant	
		for (int space = 1; space <= rows - counter; space++) {
			printf(" ");
		}

		for (int asterisk = 1; asterisk <= counter; asterisk++) {
			printf("*");
		}

		// Top Right Quadrant		
		for (int asterisk = 1; asterisk <= counter; asterisk++) {
			printf("*");
		}




		puts("");
	}

	// Bottom Half //
	for (int counter = 1; counter <= rows; counter++) {

		// Bottom Left Quadrant		
		for (int space = 1; space <= counter; space++) {
			printf(" ");
		}

		for (int asterisk = 9; asterisk >= counter; asterisk--) {
			printf("*");
		}

		// Bottom Right Quadrant		
		for (int asterisk = 9; asterisk >= counter; asterisk--) {
			printf("*");
		}
		puts("");
	}



	// Odd Diamond Pattern //

	// Top Half //





}

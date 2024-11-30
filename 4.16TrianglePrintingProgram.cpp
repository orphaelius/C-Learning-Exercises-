#include <stdio.h>
#include <math.h>

// Triangle Printing Program //

/* write a program that printes 4 different triangle patterns separately,
* one below the other. use for loops to generate the patterns. all asterisks (*)
* should be printed by a single printf statement of the form printf("%s","*");
* this causes the asterisks to print side-by-side. hint: the last two patterns
* require that each line begin with an appropriate number of blanks. */


int main(void) {	
	int rows = 10;
	
	// Triangle A //
	for (int counter = 1; counter <= rows; counter++) {
		
		for (int tri1 = 1; tri1 <= counter; tri1++) 

			if (tri1 <= counter) { 
				printf("%s", "*");
			}

		puts("");		
	}

	puts("");

	// Triangle B //
	for (int counter = 1; counter <= rows; counter++) {

		for (int tri1 = 10; tri1 >= counter; tri1--)

			if (tri1 >= counter) {
				printf("%s", "*");
			}

		puts("");
	}

	puts(""); 

	// Triangle C //
	// why //
	for (int counter = 1; counter <= rows; counter++) {
		int space = 9;

		// spaces
		for (int space = 1; space >= rows - counter; space++) {
			printf(" 9");
		}

		for (int tri1 = 1; tri1 >= counter; tri1++) {
			printf("%s", "*");
		}

		puts("");

		puts("");
	}



	// Triangle D //
	for (int counter = 1; counter <= rows; counter++) { 

		// spaces
		for (int space = 1; space <= rows - counter; space++) { 
			printf(" ");
		}
		
		for (int tri1 = 1; tri1 <= counter; tri1++) {
			printf("%s", "*");
		}
		
		puts("");		
	}

	puts("");


}
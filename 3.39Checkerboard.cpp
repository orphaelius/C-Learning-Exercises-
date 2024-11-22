#include <stdio.h>


// Checkerboard Pattern of Asterisks //

// 8 x 8 checkerboard asterisk pattern //

/*
* initialize function
* 
* initialize variables
* 
* counter for outer
* counter for inner
* 
* outer while loop - for columns
* reset inner counter each time to produce 8 asterisks per row times 8
* 
* 
* inner while loop - for rows
* print asterisk with space
* if column plus row %2 is 0, print asterisk
* if column is odd, print space at beginning
* 
* increment inner counter
* print new line
* increment outer counter
* 
* print new line
* 
* 

*/


int main(void) { // initialize function
	
	int counter_outer = 0; // counter to produce each row n amount of times 
	int counter_inner = 0; // counter to produce n amount of asterisks per row

	while (counter_outer < 8) { // outer loop, set to loop 8 times
		
		counter_inner = 0; // resets inner counter each time the outer loop iterates, allowing each row to start at 0 again

		while (counter_inner < 8) { // inner loop

			if ((counter_outer + counter_inner) % 2 == 0) { // if the sum of outer and inner counter divded by 2 has a remainder of 0, then print the asterisk
				printf("%s", "* ");
			}
			else {
				printf("%s", " "); // else print a space, every other row
			}
						
			counter_inner++; // increment the inner counter	
		}

		puts(""); // print new line
		counter_outer++; // increment counter (it's good practice to put counter at the end/bottom of a loop						
	}

	return 0;
}
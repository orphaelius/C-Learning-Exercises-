#include <stdio.h>
#include <math.h>

// Bar Chart Printing Program //

/* write a program that reads 5 numbers between 1 and 30.
* for each number read, the program should print a line
* containing that number of adjacent asterisks ( * ).
*/

int main(void) {
	// array to store input from user
	int num[5] = { };

	// learned that sizeof is a way to calculate the total amount of bytes stored in an array. typically,
	// an int is 4 bytes, so if you divide, say, the size of an array with 5 ints (or 20 bytes) by the 
	// bytes at [0] (or 4 bytes), you get th value of 5. this is a way to find the size of an array. 
	int size = sizeof(num) / sizeof(num[0]);

	// learned a neat trick to end a program if input parameters aren't adhered to!
	int end_program = 0;
	
	// loop to take input from user, loop through the num[] array
	for (int counter = 0; counter < size; counter++) {
		scanf("%d", &num[counter]);	

		// if input is greater than 30, display message, trigger end_program = true
		if (num[counter] > 30) { 
			printf("You've broken the parameters.. ending program..\n"); 
			end_program = 1; 
		}
	}

	// end program (from above)
	if (end_program) { 
		return 0; 
	}

	// outer loop, loops through the size of num[]
	for (int counter = 0; counter < size; counter++) { 

		// inner loop, loops through the values at each num[] position, prints asterisks until i == num[value]
		for (int i = 0; i < num[counter]; i++) {
			printf("*");
		}

		// new line!
		puts(""); 

	}	

}

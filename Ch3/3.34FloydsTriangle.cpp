#include <stdio.h>

// Floyd's Triangle //

/* floyd's triangle is a right-angle triangular array of natural numbers. it is defined by filling rows with consecutive integers.
* thus, row 1 will have the number 1, row 2 will have the numbers 2 and 3, and so on. write a program that draws a 10-line floyd's
* triangle. an outer loop can control the number of lines to be printed and an inner loop can ensure that each row contains the correct number of integers.
* 
* row 1
* row 2 3
* row 4 5 6
* row 7 8 9 10 
* row 11 12 13 14 15
* row 16 17 18 19 20 21
* row 22 23 24 25 26 27 28
* row 29 30 31 32 33 34 35 36
* row 37 38 39 49 41 42 43 44 45
* row 46 47 48 49 50 51 52 53 54 55
* 
* 
* initialize variables
*  
* outer loop:
* controls the number of lines to be printed
* while any integer <= 10, maximum row count
* my initial thought was to increment here, but it incremented essentialy 55 times 
*  
* inner loop:
* ensures each row contains the correct number of integers 
* while integer two < 55: incorrect logic. seemed correct in my initial thought process, as that's the end number for 10 rows of numerically-ordered consecutive integers,
* however the correct logic is to print a number, num, n times per row. so, row one has a starting value of num, then increment the inner loop counter. this prints num n times, reaches counter_two
* increment, and once counter_two is greater than counter_one, it moves to incrementing counter_one and starting over. 
* increment ++
* 
* print 
* 
* end program
*/

int main(void) {
	int rows = 10;  // outer loop- maximum number of rows
	int counter_one = 1;  // starting counter
	int counter_two = 0; //inner loop variable
	int num = 1; // starting number, call to print during loop

	printf("Floy'd Triangle is right-angle triangular array of numbers, like so: \n\n");
	
	while (counter_one <= rows) { // outer loop condition- while starting counter is less than or equal to row number, ends when counter = rows
		counter_two = 1; 

		while (counter_two <= counter_one) {   	// while inner loop variable is less than or equal to the starting number at its current value	  	 		
			printf("%3d", num++);   // print number 
			counter_two++; // increment the inner loop variable value						
		}
		printf("\n");
		counter_one++; // increment starting number value  
	}

	return 0;

}


	
	

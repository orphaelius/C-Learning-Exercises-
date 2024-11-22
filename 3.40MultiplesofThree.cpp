#include <stdio.h>

// Multiples of 3 //

/*
* write a program that keeps printing the multiples of the integer of 3, namely 3, 9, 27, 91, 273, etc. the loop should not terminate. 
* what happens when you run it?
* 
* 
* initialize function
* 
* initialize variables
* multiple
* 
* while loop
* print multiples
* multiple value = multiple x 3 (sets each subsequent value in loop to current number x 3)* 
* 
* print multiples* 
* 
* LOGIC
* starting number at 1, bc powers start at 1
* while loop to increment, increment number at end of loop
* if number = 3, 9, 27, 81, etc... num 
* current number = number times 3
*/


int main(void) {
	int multiple = 1; // all powers start at 1 (ie 3^0 = 1) 

	while (multiple <= 10000) { // loop through integers/restart with new num value (loop doesn't close on original exercise, i added a way to stop the loop just to run it)

		printf("%d\n", multiple); // print current number/multiple of 3		
		multiple *= 3; // variable num = current numx3. ie 1x3=3, 3x3=9, 9x3=27, etc
	}

	return 0;

}
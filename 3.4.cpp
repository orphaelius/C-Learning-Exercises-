#include <stdio.h>


// Write a C statement to accomplish each of the following tasks:
// a) define variable x to be of tpe in and set it to 1
// b) define variable sum to be of type in and set it to 0
// c) add variable x to variable sum and assign the result to variable sum
// d) print "the sum is: " followed by the value of the variable sum


int main(void) {

	int x = 1; // int x starts at (value can change, here it starts at 1)
	int sum = 0; // int sum starts at zero. initialized.

	// while loop, increments x by 1 per iteration, adds 1 to sum each iteration, stops when x reached 15
	while (x < 15) { // x is less than 15

		sum += x; // sum equals sum (starting at 0) plus x (starting at 1)
		++x; // incremement x by 1 tick per loop
	}

	printf("The sum is: %d\n", sum); // print statement after x reaches 15 and stops while loop


}

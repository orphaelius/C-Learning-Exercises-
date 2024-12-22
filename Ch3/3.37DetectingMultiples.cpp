#include <stdio.h>

// Detecting Multiples of a Number //

/*
* write a program that prints 500 dollar signs ($) one after the other, separated by a space. after every fiftieth dollar sign, 
* the program should print a newline character. 
* 
* hint: count from 1 to 500. use the remainder operator to recognize when the counter reaches a multple of 50
* 
* initalize function
* 
* initialize variables
* remainder variables
* starting int
* current int
* 
* loops
* 
* while starting in is less than or equal to 500
* current int = starting int 
* 
* if current int % 50 == 0
*	print newline
* 
* increment
*
* return 0
*  
*/

int main(void) {
	int starting_num = 0;
	int current_num;
	int remainder_counter;

	while (starting_num < 500) {
		current_num = starting_num;

		if (current_num % 50 == 0) { 
			printf("\n");
		}
		printf("$ ");
		starting_num++; 
	}


}

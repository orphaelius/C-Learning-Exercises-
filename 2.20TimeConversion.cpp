#include <stdio.h>

// Write a program that asks the user to enter the total time elapsed, in seconds, since an event occurred and converts the time to 
// hours, minutes, and seconds. The time should be displayed as hours:minutes:seconds (use modulus operator)



int main(void) {

	
	// declare initial variable:
	int input_seconds = 0;

	// ask for user input:
	printf("How much time, in seconds, has elapsed since your last dental appointment?\n");
	scanf("%d", &input_seconds);

	// set up formulas and subsequent variables:
	int seconds = input_seconds % 60;
	int minutes = (input_seconds % 3600) / 60;
	int hours = input_seconds / 3600;

	// display the time lapsed in 00:00:00 format
	printf("%d:%02d:%02d\n", hours, minutes, seconds);

	return 0;

}
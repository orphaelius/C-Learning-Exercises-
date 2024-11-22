#include <stdio.h>

// Write a program that asks the user to enter the total time elapsed, in seconds, since an event occurred and converts the time to 
// hours, minutes, and seconds. The time should be displayed as hours:minutes:seconds (use modulus operator)



int main(void) {

	// declare initial variable for the function
	
	int input_seconds = 0;	

	printf("How much time, in seconds, has elapsed since your last dental appointment?\n");
	scanf("%d", &input_seconds);

		
	
	if (input_seconds < 60) {
		int seconds = input_seconds % 60;
		int minutes = input_seconds / 60;
		printf("00:00:%d", input_seconds);
	}

	if (input_seconds < 3600) {
		int seconds = input_seconds % 60;
		int minutes = input_seconds / 60;
		printf("00:%d:%d", minutes, seconds);
	}

	if (input_seconds >= 3600) {
		int seconds = input_seconds % 60;
		int minutes = input_seconds / 60;
		int hours = minutes / 60;
		printf("%d:%d:%d", hours, minutes, seconds);
	}
	

}
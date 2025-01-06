#include <stdio.h>

// Time in Seconds //

/* write a function that takes the time as three arguments
(hours, minutes, seconds) and returns the number of 
seconds since the last time the clock "struck 12." use this
function to calculate the amount of time in seconds between
two times, both of which are within one 12-hour cycle of
the clock. */

int lastStruck12(int hour, int minute, int second); 
int hour, minute, second; 

int main(void) {
	printf("Enter the current standard time (hour, minute, and second):\n");
	scanf("%d%d%d", &hour, &minute, &second); 
	lastStruck12(hour, minute, second);  

}

int lastStruck12(int hour, int minute, int second) { 

	if (hour > 12 || minute > 60 || second > 60) {
		printf("You will pay for this.\n");
		return 0; 
	}	 	
	int tempHour = hour * 3600;
	int tempMinute = minute * 60;
	int tempTime = second + tempMinute + tempHour;	
	
	if (tempTime == 43200) {
		printf("The clock is striking... beware...\n");
		return 0; 
	}

	if (tempTime > 43200 || tempTime <= 0) { 
		printf("That is surely not a real time.\n");
		return 0; 
	}	

	printf("It's been %d seconds since the clock struck 12.\n", tempTime); 	
	return 0;
	
}
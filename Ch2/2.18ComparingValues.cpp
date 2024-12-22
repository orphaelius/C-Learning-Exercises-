#include <stdio.h>

// Write a program that asks the user the enter the highest rainfall ever recorded in one season for a country,
// and the rainfall in the current year for that country,
// obtains the values from the user, checks if the current rainfall exceeds the highest rainfall, and prints
// an appropriate message on the screen. If the current rainfall is higher, it assigns that value as the highest 
// rainfall ever. Use only the single-selection form of the if statement you learned in this chapter

int main(void) {

	// initial variables for highest rainfall and current rainfall
	int record_rain = 587;
	int current_rain = 0;

	// request rainfall input from user, print if current rainfall is lesser or greater than the record. 
	// reassign record rainfall if current rainfall is greater:
	printf("Welcome to Rainfall Comparison. Please enter the current annual rainfall, in millimeters, for your country: \n");
	scanf("%d", &current_rain);

	if (current_rain < record_rain) {
		printf("The current annual rainfall, %d mm, is less than the record annual rainfall, %d mm", current_rain, record_rain);
	}

	if (current_rain > record_rain) {
		int new_record_rain = current_rain;
		printf("Wow, %d mm is a new record for annual rainfall in your country!\n", new_record_rain);
	}





}

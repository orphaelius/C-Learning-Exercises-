#include <stdio.h>

// Maximum heart rate formula is 220 minus one's age (in years).
// Target heart rate is 50-85% of one's maximum heart rate
// Write a program that prompts for and inputs a user's age, then calculates and displays the user's maximum heart rate and range
// of the user's target heart rate

int main(void) {

	// initialize variables
	int user_age = 0;

	// prompt user for age
	printf("Enter your age and I will calculate your maximum heart rate and your target heart rate range: \n");
	scanf("%d", &user_age);

	// formulas
	int max_heart_rate = 220 - user_age;
	int low_end_target_range = max_heart_rate * (.5);
	int high_end_target_range = max_heart_rate * (.85);


	printf("Your maximum heart rate is %d.\nThe target heart rate range for your age is between %d and %d.", max_heart_rate, low_end_target_range, high_end_target_range);

}

#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

// Coin Tossing //

/* Write a program that simulates coin tossing. For each toss, display
Heads or Tails. Let the program toss the coin 100 times, and count the
number of heads and tails. Display the results. The program should call
a function flip that takes no arguments and returns 0 for tails and 1
for heads. If the program realistically simulates the coin tossing,
then each side of the coin should appear approximately half the time
for a total of approximately 50 heads and 50 tails. */

int flip(void);

int main(void) {
	srand(time(NULL));	

	int tails = 0;
	int heads = 1;
	int tailsCount = 0;
	int headsCount = 0;
	int counter = 1;

	while (counter <= 100) { 
		if (flip() == 0) {
			printf("Coin toss is tails!\n");
			tailsCount++;
		}
		else {
			printf("Coin toss is heads!\n");
			headsCount++; 
		}

		counter++;  
	}

	printf("Total tails: %d\n", tailsCount); 
	printf("Total heads: %d\n", headsCount); 

	return 0;
}

int flip(void) {	

	if ((rand() % 2) == 0) {
		return 0;
	}
	else {
		return 1;
	}		
}


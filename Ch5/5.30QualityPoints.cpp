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
	int heads = 0;
	int tails = 0;
	for (int i = 0; int i <= 100; i++) {

		if (flip(void) == 0) {
			printf("Coin toss is tails!\n");
			tails++;
		}

		if (flip(void) == 1) {
			printf("Coin toss is heads!\n");
			heads++
		}
		
	}
	printf("Total tails: %d\n", tails);
	printf("Total heads: %d\n", heads); 

}

int flip(void) { 
	srand(time(NULL));  

	int coinToss = (rand() % (1 - 0 + 1)) + lower;
	return coinToss; 
	 
}


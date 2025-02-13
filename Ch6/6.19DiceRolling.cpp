// Dice Rolling // 

/* This program simulates rolling two dice. It reads
* rand() twice to roll the first and second die, respectively,
* then calculates their sum. Uses a one-dimensional array to 
* tally the numbers of times each possible sum appears.
*
*		Written by: Orphaelius
*		Date: February 2, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

// Function prototypes
int diceRoll(int sumOfDice[], size_t size); // Dice-rolling function
void printArray(int sumOfDIce[], size_t size); // Printing function

int main(void) {
	srand(time(NULL));
	size_t size = SIZE; 
	int sumOfDice[SIZE] = { 0 };
	
	diceRoll(sumOfDice, size);  
	printf("%s%20s\n", "Dice Roll Sum", "Roll Frequency");
	printArray(sumOfDice, size);

	return 0;
}

int diceRoll(int sumOfDice[], size_t size) { 
	int sum = 0; 
	int rolls = 0;

	while (rolls < 36000) {
		int firstDie = (1 + rand() % 6);  
		int secondDie = (1 + rand() % 6);  
		sum = firstDie + secondDie;    

		if (sum == 2) {
			sumOfDice[0]++; 
		}
		else if (sum == 3) {
			sumOfDice[1]++;
		}
		else if (sum == 4) {
			sumOfDice[2]++;
		}
		else if (sum == 5) {
			sumOfDice[3]++;
		}
		else if (sum == 6) {
			sumOfDice[4]++;
		}
		else if (sum == 7) {
			sumOfDice[5]++;
		}
		else if (sum == 8) {
			sumOfDice[6]++;
		}
		else if (sum == 9) {
			sumOfDice[7]++;
		}
		else if (sum == 10) {
			sumOfDice[8]++;
		}
		else if (sum == 11) {
			sumOfDice[9]++;
		}		
		else {
			sumOfDice[10]++;
		}

		rolls++; 
	}	

	return 0;  

}

void printArray(int sumOfDice[], size_t size) {  

	for (size_t i = 0; i < size; ++i) {
		printf("%13zu%20d\n", i + 2, sumOfDice[i]); 
	}
}



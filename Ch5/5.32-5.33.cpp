#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

// Guess the Number (and modified version for 5.33) //

/* Write a program that plays the game of "guess the number" as follows:
your program chooses  the number to be guessed  by selecting an integer
at random in the range 1 to 1000. The program then types:

"I have a number between 1 and 1000.
Can you guess my number?
Please type your first guess."

The player types a first guess. The program responds with one of the following:

1. Excellent! You guessed the number!
2. Too low. Try again.
3. Too high. Try again.

if the guess is incorrect, your program should loop until the player guesses
the number. Your program should keep telling the player 'too high' or 'too low'
to help the player zero in on the correct answer. */


int guessTheNumber(void); // Function prototype
int playerTries(int guessCount);

int main(void) { // Main function

	srand(time(NULL)); // Sets random number to time in seconds since Unix epoch, essentially a random seed generator

	int guess = 0; // For user input
	int currentNumber = guessTheNumber(); // Calls guessTheNumber function and sets result to currentNumber 
	int guessCount = 0; // Counter for total user guesses before currentNumber is guessed

	printf("I have a number between 1 and 1000.\n");
	printf("Can you gsadfasduess my number?\n");
	printf("Please type your first guess:\n");

	while (1) {	// Loops until number is guessed correctly

		scanf("%d", &guess); // Takes input		

		if (currentNumber == guess) {
			printf("Excellent! You guessed the number!\n");
			break; 
		}

		if (currentNumber > guess) {
			printf("Too low. Try again:\n");
			guessCount++;
		}

		else {
			printf("Too high. Try again:\n");
			guessCount++;
		}
	}

	playerTries(guessCount);

}

int guessTheNumber(void) { // Random number generator 
	return (1 + rand() % 1000);
}

int playerTries(int guessCount) {

	if (guessCount == 10) {
		printf("Either you know the secret or you got lucky!\n");
	}

	if (guessCount < 10) {
		printf("Either you know the secret or you got lucky!\n");
	}

	if (guessCount > 10) {
		printf("You should be able to do better!\n");
	}

	return 0;
}
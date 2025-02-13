#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Simulating Rock, Paper, Scissors //

/* This program follows a program as described in
Learn to Program (5.257). There were a few issues with the
code in the text:

1) The game round is initially set to '0' and
will trigger a win, loss, or draw at round 0
then move to round 1. This causes issues with
the 'best 2 out of 3' algorithm. I adjusted to
make this more logical and now the program starts
at round 1.

2) the function getStringFromShape is initially
written in the textbook to return a non-constant
character, which causes the program to repeatedly
crash. I changed the function to a constant string
literal type which resolved the issue. The program
now runs as intended. */

// UPDATES FOR EXERCISE 6.20 //

/*
1) Created a game loop function and pushed the main body to new function. 
2) Created array to store total counts of player wins and computer wins
3) Updated game loop to loop for 10000 games, tally total wins per contender,
   and return these counts to the array in main.
4) Added tabular output for printing results
   


*/

enum GameStatus { CONTINUE, GAME_WON, GAME_LOST }; // constants that represent the game status
enum RoundStatus { DRAW, WON, LOST }; // constants represent the round status
enum Shape { ROCK, PAPER, SCISSORS }; // constants representing the possible game shapes

enum Shape computerPlayRandomShape(void); // playRandomShape function
enum Shape playerPlayRandomShape(void);

void gameLoop(int totalGamesWon[]);

enum RoundStatus getRoundStatus(enum Shape, enum Shape);
enum Shape convertIntToShape(int);
const char* getStringFromShape(enum Shape);

int main(void) {
	int totalGamesWon[2] = { 0, 0 }; // Index 0 = player; index 1 = computer 	
	gameLoop(totalGamesWon);
	int gamesSum = totalGamesWon[0] + totalGamesWon[1];

	printf("%s%20s%20s\n", "Total Games Played", "Won by Player", "Won by Computer"); 
	printf("%18d%20d%20d\n", gamesSum, totalGamesWon[0], totalGamesWon[1]);

	//printf("Player won %d games, Computer won %d games", totalGamesWon[0], totalGamesWon[1]);	
}

// intake game number via i counter
void gameLoop(int totalGamesWon[]) {
	int totalGamesPlayed = 0;
	srand(time(NULL)); // randomize based on current time

	while (totalGamesPlayed < 100) { 
		
		enum GameStatus gameStatus = CONTINUE; // may be win or loss too
		int bestOFN = 3; // best of 3 games
		int winThreshold = (bestOFN / 2) + 1;
		// int winThreshold = (bestOFN / 2) + 1;
		int playerWinCount = 0;
		int computerWinCount = 0;

		int roundNum = 1;
		while (CONTINUE == gameStatus) {
			printf("============================================\nRound %d\n============================================\n", roundNum++);
			//printf("Enter 0 (ROCK), or 1 (PAPER), or 2 (SCISSORS): ");
			//int playerShapeInt = -1;
			//scanf(" %d", &playerShapeInt);	
			enum Shape playerShape = playerPlayRandomShape();
			//enum Shape playerShape = convertIntToShape(playerShapeInt);
			enum Shape computerShape = computerPlayRandomShape();
			enum RoundStatus roundStatus = getRoundStatus(playerShape, computerShape);

			switch (roundStatus) {
			case DRAW:
				printf("It's a DRAW!\n");
				break;

			case WON:
				printf("Player WON!\n");
				if (++playerWinCount == winThreshold) {
					totalGamesWon[0]++;
					gameStatus = GAME_WON;
				}

				break;

			case LOST:
				printf("Player LOST!\n");
				if (++computerWinCount == winThreshold) {
					totalGamesWon[1]++;

					gameStatus = GAME_LOST;
				}

				break;
			}
		}

		switch (gameStatus) {
		case GAME_WON:
			printf("**Best of %d games is WON by player!**\n", bestOFN);
			break;

		case GAME_LOST:
			printf("**Best of %d games is WON by computer!**\n", bestOFN);
			break;

		case CONTINUE:
		default:
			printf("**ERROR! Should not reach here!**");
		}

		totalGamesPlayed++;
	}
}

// play a random shape and display result
enum Shape computerPlayRandomShape(void) {

	enum Shape randomShape = convertIntToShape(rand() % 3);
	printf("Computer played %s\n", getStringFromShape(randomShape));
	return randomShape;
}

enum Shape playerPlayRandomShape(void) {

	enum Shape randomShape = convertIntToShape(rand() % 3);
	printf("Player played %s\n", getStringFromShape(randomShape));
	return randomShape;
}

enum RoundStatus getRoundStatus(enum Shape playerShape, enum Shape computerShape) {
	if (playerShape == computerShape) {
		return DRAW;
	}
	else if ((playerShape == ROCK && computerShape == SCISSORS)
		|| (playerShape == SCISSORS && computerShape == PAPER)
		|| (playerShape == PAPER && computerShape == ROCK)) {
		return WON;
	}
	else {
		return LOST;
	}
}

enum Shape convertIntToShape(int shapeValue) {
	return (enum Shape)shapeValue;

}

const char* getStringFromShape(enum Shape shape) {
	switch (shape) {
	case ROCK:
		return "ROCK";
	case PAPER:
		return "PAPER";
	case SCISSORS:
		return "SCISSORS";
	}
	return "";
}
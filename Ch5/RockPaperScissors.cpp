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

enum GameStatus { CONTINUE, GAME_WON, GAME_LOST }; // constants that represent the game status
enum RoundStatus { DRAW, WON, LOST }; // constants represent the round status
enum Shape { ROCK, PAPER, SCISSORS }; // constants representing the possible game shapes

enum Shape computerPlayRandomShape(void); // playRandomShape function

enum RoundStatus getRoundStatus(enum Shape, enum Shape);
enum Shape convertIntToShape(int);
const char* getStringFromShape(enum Shape); 

int main(void) {
	srand(time(NULL)); // randomize based on current time
	enum GameStatus gameStatus = CONTINUE; // may be win or loss too
	int bestOFN = 3; // best of 3 games
	int winThreshold = (bestOFN / 2) + 1;

	int playerWinCount = 0;
	int computerWinCount = 0;

	int roundNum = 1;

	// while game is not complete
	while (CONTINUE == gameStatus) {
		printf("==================\nRound %d\n==================\n", roundNum++);
		printf("Enter 0 (ROCK), or 1 (PAPER), or 2 (SCISSORS): ");

		int playerShapeInt = -1;
		scanf(" %d", &playerShapeInt);

		enum Shape playerShape = convertIntToShape(playerShapeInt);
		enum Shape computerShape = computerPlayRandomShape();

		enum RoundStatus roundStatus = getRoundStatus(playerShape, computerShape);

		switch (roundStatus) {
		case DRAW:
			printf("It's a DRAW!\n");
			break;

		case WON:
			printf("Player WON!\n");
			if (++playerWinCount == winThreshold) {
				gameStatus = GAME_WON;
			}
			break;

		case LOST:
			printf("Player LOST!\n");
			if (++computerWinCount == winThreshold) {
				gameStatus = GAME_LOST;
			}
			break;
		}
	}

	switch (gameStatus) {
	case GAME_WON:
		printf("**Best of %d game is WON by player!**\n", bestOFN);
		break;

	case GAME_LOST:
		printf("**Best of %d game is WON by computer!**\n", bestOFN);
		break;

	case CONTINUE:
	default:
		printf("**ERROR! Should not reach here!**");
	}
}

// play a random shape and display result
enum Shape computerPlayRandomShape(void) {

	enum Shape randomShape = convertIntToShape(rand() % 3);
	printf("Computer played %s\n", getStringFromShape(randomShape));
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

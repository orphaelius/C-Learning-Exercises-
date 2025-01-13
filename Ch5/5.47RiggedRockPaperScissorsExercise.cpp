#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Simulating Rock, Paper, Scissors //

/* Modify the program to have a method with custom logic that 
programmatically chooses the player's shape too instead of
relying on user input. Apply a strategy that increases the
player's odds of winning by counting the quantity of each
shape the computer plays and ensuring the least-played
shape has the highest chance of being selected in the next
round. */

/* 
*	a) Modified existing enum type and playRandomShape function to generate both player and computer shape
*	b) Modified main function body to call functions and print both plays each round
*	c) Added a function computerShapeCounts to keep track of which shapes computer "plays" for debugging
*	d) Added new function playRiggedShape to introduce a rigged process in the game. The function automatically
*	chooses the computer's first shape and then cycles through each shape after that. 
*	e) Added a structure to return two arguments from function playRiggedShape
*	f) Modified playRiggedShape to select a shape for the player that consistently wins each round
*/

enum GameStatus { CONTINUE, GAME_WON, GAME_LOST }; // CONSTANTS that represent the game status
enum RoundStatus { DRAW, WON, LOST }; // CONSTANTS that represent the round status
enum Shape { ROCK, PAPER, SCISSORS }; // CONSTANTS that representing the possible game shapes

enum Shape playRandomShape(void); // Plays random shape to start the cycle
struct controlShapes playRiggedShape(void); 
struct controlShapes { // Structure to allow return of multiple arguments from playRiggedShape function
	enum Shape riggedComputerShape; // For computer
	enum Shape riggedPlayerShape; // For player
};

enum RoundStatus getRoundStatus(enum Shape, enum Shape); // Function that determines status of each round (win, loss, etc)
enum Shape convertIntToShape(int); // Function to convert ints (currently out of 0, 1, or 2) to "shapes" ie rock, paper, scissors
const char* getStringFromShape(enum Shape);

int computerShapeCounts(int rockCount, int paperCount, int scissorsCount); // Function to track computer shape counts -- used for debugging originally

int main(void) {
	srand(time(NULL));	

	int rockCount = 0; // Counters to track computer shape counts 
	int paperCount = 0;
	int scissorsCount = 0;	
	
	enum GameStatus gameStatus = CONTINUE; // Game status
	int bestOFN = 3; // Total rounds played
	int winThreshold = (bestOFN / 2) + 1; // Places limitation on game rounds

	int playerWinCount = 0; // Counter for rounds player wins
	int computerWinCount = 0;// Counter for rounds computer wins

	int roundNum = 1; // Counter for current round number, starting at 1
	
	while (CONTINUE == gameStatus) { // Loops until player count or computer count reaches winThreshold (currently 3)

		printf("==================\nRound %d\n==================\n", roundNum++);
		//printf("Enter 0 (ROCK), or 1 (PAPER), or 2 (SCISSORS): ");
				
		struct controlShapes shapes = playRiggedShape(); // Gets the rigged shapes for each opponent

		enum Shape computerShape = shapes.riggedComputerShape; // Passes shape value into computerShape     
		printf("Computer played %s\n", getStringFromShape(computerShape));   
		enum Shape playerShape = shapes.riggedPlayerShape; // Passes shape value into playerShape 
		printf("Player played %s\n", getStringFromShape(playerShape));   
		 
		if (computerShape == 0) { // Added if statements to count computer shapes during game loop -- originally used for debugging
			rockCount++;
		}

		if (computerShape == 1) { 
			paperCount++; 
		}

		if (computerShape == 2) { 
			scissorsCount++; 
		}				

		enum RoundStatus roundStatus = getRoundStatus(playerShape, computerShape); // Tracks which opponent wins each round

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
		computerShapeCounts(rockCount, paperCount, scissorsCount); 		

		break;

	case GAME_LOST:

		printf("**Best of %d game is WON by computer!**\n", bestOFN);
		computerShapeCounts(rockCount, paperCount, scissorsCount);  
		
		break;

	case CONTINUE:

	default:
		printf("**ERROR! Should not reach here!**");
	}
}

enum Shape playRandomShape(void) { // Selects a random shape for COMPUTER opponent

	enum Shape randomShape = convertIntToShape(rand() % 3);		
	
	return randomShape;
}

struct controlShapes playRiggedShape(void) { // Function that rigs the results in the "PLAYERS'S" favor by playing the winning shape each round
	 
	static enum Shape riggedComputerShape = ROCK;   
	static enum Shape riggedPlayerShape = PAPER; 
	struct controlShapes result; 
	
	if (riggedComputerShape == ROCK) { 
		riggedComputerShape = PAPER; 
		riggedPlayerShape = SCISSORS;   
	}

	else if (riggedComputerShape == PAPER) {
		riggedComputerShape = SCISSORS; 
		riggedPlayerShape = ROCK; 
	}

	else {
		riggedComputerShape = ROCK; 
		riggedPlayerShape = PAPER;  
	}

	result.riggedComputerShape = riggedComputerShape;  
	result.riggedPlayerShape = riggedPlayerShape; 

	return result;  
	
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

int computerShapeCounts(int rockCount, int paperCount, int scissorsCount) { // Introduced for debugging
	
	printf("Total computer counts:\n"); 
	printf("Rock: %d\n", rockCount);  
	printf("Paper: %d\n", paperCount);  
	printf("Scissors: %d\n", scissorsCount);  
	
	return 0;

}
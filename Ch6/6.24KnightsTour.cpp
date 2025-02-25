

/******************************************************************************
						
						// Knight's Tour //

	This program simulates the movement of a lone knight along a "chessboard."
	Users may manipulate the knight's location, print the board, or elect
	to automatically simulate the movement of a knight, where the knight will
	make moves until each square is landed upon once.

	Written by: Orphaelius
	Date: 02/16/2025

******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8 // Chessboard row count
#define COLUMNS 8 // Chessboard column count
#define OPTIONS 12 // Total options for instructions array
#define CHARLIM 30 // Maximum characters allowed in string
#define SINGLE 1 // Move one place
#define DOUBLE 2 // Move two places

// Function prototypes
void displayDescription(void); // Obvious
// Displays instructions
void displayInstructions(char array[OPTIONS][CHARLIM]);
int getSwitchKey(int* key); // Get the key. We gotta get out of here..
// Moves knight around chessboard in an array of directions
void moveDirection(int board[ROWS][COLUMNS], int beenHere[ROWS][COLUMNS],
	int* knightX, int* knightY, int key, int* newPositionCounter);
// Prints the current state of the chessboard
void printChessboard(int array[ROWS][COLUMNS], int* knightX, int* knightY);
// Tracks every "square" the knight lands upon
void hasVisited(int array[ROWS][COLUMNS], int* knightX, int* knightY, 
	int* newPositionCounter);
// Automatically runs knight until every square is landed upon
void autoRunKnight(int accessibility[ROWS][COLUMNS], int directions[8][2], 
	int* knightX, int* knightY);

/******************************************************************************
	Function: main()
	Description: Simulates knight on a chessboard
	Side Effects: Manipulates various arrays and knight position values
	Parameters: ---
	Return: ---
******************************************************************************/
int main(void) {
	srand(time(NULL));
	// 2D "chessboard" 
	int board[ROWS][COLUMNS] = { 0 };
	// Board to track all "squares" the knight has visited
	int beenHere[ROWS][COLUMNS] = { 0 };
	// Array for heuristic approach
	int accessibility[ROWS][COLUMNS] =
	{ 2, 3, 4, 4, 4, 4, 3, 2,
	  3, 4, 6, 6, 6, 6, 4, 3,
	  4, 6, 8, 8, 8, 8, 6, 4,
	  4, 6, 8, 8, 8, 8, 6, 4,
	  4, 6, 8, 8, 8, 8, 6, 4,
	  4, 6, 8, 8, 8, 8, 6, 4,
	  3, 4, 6, 6, 6, 6, 4, 3,
	  2, 3, 4, 4, 4, 4, 3, 2 };

	// Instructions for user input/knight movement
	char instructions[OPTIONS][CHARLIM] =
	{ "(0) to move north 1, east 2",
	  "(1) to move north 2, east 1",
	  "(2) to move north 2, west 1",
	  "(3) to move north 1, west 2",
	  "(4) to move south 1, west 2",
	  "(5) to move south 2, west 1",
	  "(6) to move south 2, east 1",
	  "(7) to move south 1, east 2",
	  "(-1) to exit",
	  "(9) to print the chessboard",
	  "(10) to print beenHere",
	  "(11) to auto run knight!" };

	int directions[8][2] = {
		{-1, 2},  // North 1, East 2
		{-2, 1},  // North 2, East 1
		{-2, -1}, // North 2, West 1
		{-1, -2}, // North 1, West 2
		{1, -2},  // South 1, West 2
		{2, -1},  // South 2, West 1
		{2, 1},   // South 2, East 1
		{1, 2} };   // South 1, East 2
				

	int knightX = 4; // Row number
	int knightY = 4; // Column number 
	board[knightX][knightY] = 1; // Starting position for knight!
	// Starting position for knight in accessibility array 
	accessibility[knightX][knightY] = 1; 
	beenHere[knightX][knightY] = 1; // Ensures initial position is tracked
	int key = 0; // Switch key
	int newPositionCounter = 0;
	int roll = 0;

	displayDescription();
	displayInstructions(instructions);

	while ((key == getSwitchKey(&key)) != -1) {

		switch (key) {

		case 0:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 1:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 2:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 3:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 4:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 5:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 6:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 7:
			moveDirection(board, beenHere, &knightX, &knightY, key, 
				&newPositionCounter);
			break;
		case 9:
			printChessboard(board, &knightX, &knightY);
			break;
		case 10:
			printChessboard(beenHere, &knightX, &knightY);
			break;
		case 11:
			autoRunKnight(accessibility, directions, &knightX, &knightY);
			printChessboard(accessibility, &knightX, &knightY);
			break;
		}

		displayInstructions(instructions);
	}
} // End main

/******************************************************************************
	Function: displayDescription()
	Description: Prints instructions for playing the game
	Side Effects: ---
	Parameters: ---
	Return: ---
******************************************************************************/
void displayDescription(void) {
	printf("%s %s\n", "Move your knight around an otherwise empty chessboard using",
		"various prompts.");
} // End displayDescription

/******************************************************************************
	Function: displayInstructions()
	Description: Prints instructions for playing the game
	Side Effects: ---
	Parameters: char array instructions[][], array for instruction strings
	Return: ---
******************************************************************************/
void displayInstructions(char array[OPTIONS][CHARLIM]) {
	puts("\nChoose from the options below:");
	for (size_t i = 0; i < OPTIONS; ++i) {
		for (size_t j = 0; j < CHARLIM; ++j) {
			printf("%c", array[i][j]);
		}
		puts("");
	}
	printf("Input: ");
} // End displayInstructions

/******************************************************************************
	Function: getSwitchKey()
	Description: Grabs switch key
	Side Effects: Points to "key" value, changes it
	Parameters: Pointer to "key"
	Return: key
******************************************************************************/
int getSwitchKey(int* key) {
	scanf("%d", key);
	return *key;
} // End getSwitchKey

/******************************************************************************
	Function: moveDirection()
	Description: Moves knight in a particular direction depending on input or
		block a potential move if end result is beyond the array bounds
	Side Effects: Resets former position of knight by resetting place to "0",
		changes current position of knight on "chessboard", and updates the
		beenHere array
	Parameters: chessboard array, pointers to knightX and knightY, switch key
	Return: ---
******************************************************************************/
void moveDirection(int board[ROWS][COLUMNS], int beenHere[ROWS][COLUMNS],
	int* knightX, int* knightY, int key, int* newPositionCounter) {

	board[*knightX][*knightY] = 0; // Reset currently position	

	int dx = 0; // "Delta" for row
	int dy = 0; // "Delta" for column

	switch (key) {

	case 0: // North 1, East 2 // 
		dx = -1; dy = 2;
		break;
	case 1: // North 2, East 1 // 
		dx = -2; dy = 1;
		break;
	case 2: // North 2, West 1 //
		dx = -2; dy = -1;
		break;
	case 3: // North 1, West 2 // 
		dx = -1; dy = -2;
		break;
	case 4: // South 1, West 2 // 
		dx = 1; dy = -2;
		break;
	case 5: // South 2, West 1 // 
		dx = 2; dy = -1;
		break;
	case 6: // South 2, East 1 // 	
		dx = 2; dy = 1;
		break;
	case 7: // South 1, East 2 // 
		dx = 1; dy = 2;
		break;
	}

	// Used to ensure moves are not out of bounds
	int potentialX = *knightX + dx;
	int potentialY = *knightY + dy;

	if (potentialX >= 0 && potentialX < ROWS && potentialY >= 0
		&& potentialY < COLUMNS) {
		// Knight position in row = dx values added to
		// current position (and same formula for column position)
		*knightX += dx;
		*knightY += dy;
		board[*knightX][*knightY] = 1; // Value on board = 1
		// Updates beenHere array
		hasVisited(beenHere, knightX, knightY, newPositionCounter);  

	}
	else { // Get back over there!
		printf("Knight would move off the board!\n");
	}
} // End moveDirection

/******************************************************************************
	Function: hasVisited()
	Description: Keep track of every position knight has visited on the board
	Side Effects: Changes hasBeen array elements to 1 if visited
	Parameters: board array, hasBeen array
	Return: ---
******************************************************************************/
void hasVisited(int beenHere[ROWS][COLUMNS], int* knightX, int* knightY, 
	int* newPositionCounter) {

	if (beenHere[*knightX][*knightY] == 0) {
		(*newPositionCounter)++;
		printf("New space counter: %d\n", *newPositionCounter);
	}
	else {
		printf("Knight has been here already.\n");
	}
	beenHere[*knightX][*knightY] = 1;
} // End hasVisited

/******************************************************************************
	Function: countNewCoords()
	Description: Update newPositionCounter each time the knight has not
		landed on that position
	Side Effects:
	Parameters:
	Return: NOT SURE YET
******************************************************************************/

/******************************************************************************
	Function: autoRunKnight()
	Description: Loops potential moves knight can make based on whether or not
		the potential next move is of lesser or greater value (ie squares
		located in the center interior of the board are easier to visit, whereas
		the corners and edges less so). It loops until each square has been
		visited once.
	Side Effects: Minimal side effects. Points to knight x and y coords and can
		directly modify these values.
	Parameters: accessibility array, directions array, pointers to knight x and y
	Return: ---
******************************************************************************/
void autoRunKnight(int accessibility[ROWS][COLUMNS], int directions[8][2], 
	int* knightX, int* knightY) {
	
	int moves = 0; // Total moves knight can make
	// Loops until each square has been visited once
	while (moves <= ROWS * COLUMNS) { 
		
		// Set outside the range for the max degree of 8 in order to compare
		int minDegree = 9; 
		int bestMoveIndex = -1; // Direction knight moves
		
		for (int i = 0; i < 8; i++) { // Runs through all 8 possible moves
			int potentialX = *knightX + directions[i][0]; // New row position
			int potentialY = *knightY + directions[i][1]; // New column position

			// Ensures move is in bounds of the array
			if (potentialX >= 0 && potentialX < ROWS && potentialY >= 0 
				&& potentialY < COLUMNS) {				

				int degree = accessibility[potentialX][potentialY];
				// If the degree of the new square is smaller, reassign the 
				// new space to minDegree
				if (degree < minDegree) {
					minDegree = degree;
					bestMoveIndex = i; // Updates to best move
				}						
			}		
		}		

		if (bestMoveIndex != -1) {
			*knightX += directions[bestMoveIndex][0]; // Updates positioning
			*knightY += directions[bestMoveIndex][1];
			moves++;
			printf("Moved to (%d, %d)\n", *knightX, *knightY);
		}		
	}

	printf("Knight has visited all squares.........\n");
	
} // End autoRunKnight

/******************************************************************************
	Function: printChessboard()
	Description: Prints current knight position on the chessboard
	Side Effects: ---
	Parameters: board array, pointers to knightX and knightY
	Return: ---
******************************************************************************/
void printChessboard(int array[ROWS][COLUMNS], int* knightX, int* knightY) {
	for (size_t i = 0; i < ROWS; ++i) {
		for (size_t j = 0; j < COLUMNS; ++j) {
			if (*knightX == i && *knightY == j) {
				printf("%c   ", 'K');
			}
			else {
				printf("%d   ", array[i][j]);
			}
		}
		puts("");
		puts("");
	}
} // End printChessboard


/******************************************************************************

							// Turtle Graphics //

	This program tracks a turtle as it moves along a two-dimensional array
		using various user inputs. The turtle may trace its path using a pen
		and this path may be displayed on the screen at-will.

	Written by: Jon-Austin

	Date: 02/11/2025

******************************************************************************/

#include <stdio.h>
#define HEIGHT 50 // Height of game floor
#define WIDTH 50 // Width of game floor
#define ELEMENTS 8 // Total options in instructions array
#define CHARLIM 60 // String character limit for instructions array

void displayDescription(); // Obvious
void showInstructions(char array[ELEMENTS][CHARLIM]); // Displays game options
int getKey(int* getSwitchKey); // Grabs switch key
void printFloor(int array[HEIGHT][WIDTH], int turtleX, int turtleY); // Well..
int turnRight(int* directionFacing); // Turns turtle 90 degrees to right
int turnLeft(int* directionFacing); // Turns turtle 90 degrees to left
// Moves turtle (n) spaces in current direction facing 
void moveAnySpace(int array[HEIGHT][WIDTH], int* turtleX, int* turtleY,
	int* east, int* south, int* west, int* north, int* penDown, int* spaces);
// Moves turtle 10 spaces in current direction facing
void moveTenSpaces(int array[HEIGHT][WIDTH], int* turtleX, int* turtleY,
	int* east, int* south, int* west, int* north, int* penDown);
// Determines, tracks, and resets direction of turtle
int cardinalDirection(int* directionFacing, int* east, int* south, int* west, int* north);
// Function to reset values of each cardinal direction in memory
void resetBoolean(int* east, int* south, int* west, int* north);
// Changes and tracks current pen positioning
void penPosition(int* penDown, int key);
void tenSpacesMessage(void);
void anySpacesMessage(int* spaces); 

/******************************************************************************
	Function: main()
	Description: Turtle game. Move turtle around game board. See above.
	Side Effects: Fun
	Parameters: ---
	Return: ---
******************************************************************************/
int main(void) {

	// Char "string" array for displaying instructions
	char instructions[ELEMENTS][CHARLIM] =
	{ "(1) to remove pen from the drawing position,",
	  "(2) to put pen in the drawing position",
	  "(3) to turn right",
	  "(4) to turn left",
	  "(5) to travel 10 spaces",
	  "(6) to print the game floor",
	  "(7) to travel (any) spaces",
	  "(9) to end program" };

	// Initialize "game" floor
	int floor[HEIGHT][WIDTH] = { 0 };
	int turtleX = 0; // Turtle position in row
	int turtleY = 0; // Turtle position in column
	floor[turtleX][turtleY] = 1; // Starting turtle position
	int getSwitchKey = 0; // Well, you know the drill
	int penDown = 0; // Using Boolean logic to control whether pen is up or down
	// 0 = east, 1 = south, 2 = west, 3 = north
	int directionFacing = 0;
	int spaces = 0; // Takes input for moving (n) spaces

	// Cardinal direction variables here track which direction turtle is facing 
	// at any given time using Boolean logic 
	// (ie east = 1 means turtle is facing east)
	int east = 1;
	int south = 0;
	int west = 0;
	int north = 0;

	displayDescription();
	printf("Turtle is currently facing East!\n"); // Turtle starting direction!
	showInstructions(instructions);

	while ((getSwitchKey = getKey(&getSwitchKey)) != 9) {

		switch (getSwitchKey) {
		case 1: // Moves pen up			
			penPosition(&penDown, getSwitchKey);
			printf("Pen is %d", penDown);
			break;

		case 2: // Moves pen down			
			penPosition(&penDown, getSwitchKey);
			printf("Pen is %d", penDown);
			break;

		case 3: // Turtle turns 90 degrees to right
			turnRight(&directionFacing);
			printf("Turned right!\n");
			cardinalDirection(&directionFacing, &east, &south, &west, &north);

			break;

		case 4: // Turtle turns 90 degrees to left
			turnLeft(&directionFacing);
			printf("Turned left!\n");
			cardinalDirection(&directionFacing, &east, &south, &west, &north);
			break;

		case 5: // Turtle moves 10 spaces in a direction
			moveTenSpaces(floor, &turtleX, &turtleY, &east, &south,
				&west, &north, &penDown); 
			break;

		case 6: // Prints current game floor			
			printFloor(floor, turtleX, turtleY);
			break;

		case 7: // Moves turtle (n) spaces
			printf("Enter spaces to move: ");
			scanf("%d", &spaces);     
			moveAnySpace(floor, &turtleX, &turtleY, 
				&east, &south, &west, &north, &penDown, &spaces);    
			break;

		case 9: // Ends game
			printf("Ending game...\n");
			break;
		}

		showInstructions(instructions);

	}

	return 0;
} // End main

void displayDescription() {
	printf("  //---------------------------------------------------------//\n");
	printf(" //-------------------- TURTLE GRAPHICS --------------------//\n");
	printf("//---------------------------------------------------------//\n\n");
	printf("This program tracks a turtle as it drags a pen across a 50*50 arena.\n\n");
} // End displayDescription

/******************************************************************************
	Function: showInstructions()
	Description: Prints instructions for playing the game
	Side Effects: ---
	Parameters: char array instructions[][], array for instruction strings
	Return: ---
******************************************************************************/
void showInstructions(char array[ELEMENTS][CHARLIM]) {
	puts("\nChoose from options below:");
	for (size_t i = 0; i < ELEMENTS; ++i) {
		for (size_t j = 0; j < CHARLIM; ++j) {
			printf("%c", array[i][j]);
		}
		puts("");
	}
	puts("");
	printf("Input: ");
} // End showInstructions

/******************************************************************************
	Function: cardinalDirection()
	Description: Tracks, changes, and (resets by secondary function call)
		the direction turtle faces
	Side Effects: Modifies cardinal direction values in memory, changes
		directionFacing in memory
	Parameters: pointers to directionFacing, east, south, west, and north
	Return: Current direction (east, south, west, north)
******************************************************************************/
int cardinalDirection(int* directionFacing, int* east, int* south, int* west, int* north) {
	if (*directionFacing == 0) {
		printf("Turtle is facing East!\n");
		resetBoolean(east, south, west, north);
		*east = 1;
		return *east;
	}
	else if (*directionFacing == 1) {
		printf("Turtle is facing South!\n");
		resetBoolean(east, south, west, north);
		*south = 1;
		return *south;
	}
	else if (*directionFacing == 2) {
		printf("Turtle is facing Wewwwwst!\n");
		resetBoolean(east, south, west, north);
		*west = 1;
		return *west;
	}
	else {
		printf("Turtle is facing North!\n");
		resetBoolean(east, south, west, north);
		*north = 1;
		return *north;
	}
} // End cardinalDirection

/******************************************************************************
	Function: resetBoolean()
	Description: Resets all cardinal direction values to zero in memory
	Side Effects: See above
	Parameters: pointers to east, south, west, north
	Return: ---
******************************************************************************/
void resetBoolean(int* east, int* south, int* west, int* north) {
	*east = 0;	*south = 0;	*west = 0;	*north = 0;
} // End resetBoolean

/******************************************************************************
	Function: penPosition()
	Description: Tracks whether pen is "up" or "down" using Boolean logic.
		ie penDown = 0 means false, therefore the pen is "up."
	Side Effects: Changes pen "positioning" in memory
	Parameters: points to penDown, uses switch key to process (see case labels)
	Return: Updated penDown value in memory
******************************************************************************/
void penPosition(int* penDown, int getSwitchKey) {
	if (getSwitchKey == 1) {
		*penDown = 0;
		printf("Pen is raised!\n");
	}
	else if (getSwitchKey == 2) {
		*penDown = 1;
		printf("Pen is in the drawing position!\n");
	}
	else {
		printf("Should not be here...\n");
	}
} // End penPosition

/******************************************************************************
	Function: getKey()
	Description: Grabs switch key for case labels
	Side Effects: ---
	Parameters: getSwitchKey pointer-- modifies the value at the address
	Return: Returns updated value at getSwitchKey address
******************************************************************************/
int getKey(int* getSwitchKey) {
	scanf("%d", getSwitchKey);
	return *getSwitchKey;
} // End getKey

/******************************************************************************
	Function: turnRight()
	Description: Turns turtle right 90 degrees.
	Side Effects: Alters the value of directionFacing in memory
	Parameters: Pointer to directionFacing
	Return: Updated directionFacing value in memory
******************************************************************************/
int turnRight(int* directionFacing) {
	if (*directionFacing >= 3) {
		*directionFacing = 0;
	}
	else {
		(*directionFacing)++;
	}
	return *directionFacing;
} // End turnRight

/******************************************************************************
	Function: turnLeft()
	Description: Turns turtle left 90 degrees.
	Side Effects: Alters the value of directionFacing in memory
	Parameters: Pointer to directionFacing
	Return: Updated directionFacing value in memory
******************************************************************************/
int turnLeft(int* directionFacing) {
	if (*directionFacing <= 0) {
		*directionFacing = 3;
	}
	else {
		(*directionFacing)--;
	}
	return *directionFacing;
} // End turnLeft

/******************************************************************************
	Function: moveAnySpace()
	Description: Moves turtle any space  determined by user in a direction.
	Side Effects: Alters the value of turtleX and turtleY in memory
	Parameters: array[HEIGHT][WIDTH], int *turtleX, int *turtleY
	Return: ---
******************************************************************************/
void moveAnySpace(int array[HEIGHT][WIDTH], int* turtleX, int* turtleY,
	int* east, int* south, int* west, int* north, int* penDown, int* spaces) {

	if (*east == 1) { // FOR EAST //
		if (*turtleY < WIDTH - *spaces) { // checks if moving out of bounds
			anySpacesMessage(spaces);   
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < *spaces; i++) { 
				(*turtleY)++;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}

	else if (*south == 1) { // FOR SOUTH //
		if (*turtleX < HEIGHT - *spaces) {
			anySpacesMessage(spaces);
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < *spaces; i++) { 
				(*turtleX)++;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}

	else if (*west == 1) { // FOR WEST //
		if (*turtleY > WIDTH - *spaces) {
			anySpacesMessage(spaces); 
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < *spaces; i++) {  
				(*turtleY)--;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}

	else {
		if (*turtleX > HEIGHT - *spaces) { // FOR NORTH //
			anySpacesMessage(spaces); 
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < *spaces; i++) {  
				(*turtleX)--;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}
} // End moveAnySpace



/******************************************************************************
	Function: moveTenSpaces()
	Description: Moves turtle ten spaces in a direction.
	Side Effects: Alters the value of turtleX and turtleY in memory
	Parameters: array[HEIGHT][WIDTH], int *turtleX, int *turtleY
	Return: ---
******************************************************************************/
void moveTenSpaces(int array[HEIGHT][WIDTH], int* turtleX, int* turtleY,
	int* east, int* south, int* west, int* north, int* penDown) { 

	if (*east == 1) { // FOR EAST //
		if (*turtleY < WIDTH - 10) { // checks if moving out of bounds
			tenSpacesMessage();
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < 10; i++) {
				(*turtleY)++;

				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}				
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}

	else if (*south == 1) { // FOR SOUTH //
		if (*turtleX < HEIGHT - 10) {
			tenSpacesMessage();
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < 10; i++) {
				(*turtleX)++;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}				
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}

	else if (*west == 1) { // FOR WEST //
		if (*turtleY > WIDTH - 40) {
			tenSpacesMessage();
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < 10; i++) {
				(*turtleY)--;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}

	else {
		if (*turtleX > HEIGHT - 40) { // FOR NORTH //
			tenSpacesMessage();
			//array[*turtleX][*turtleY] = 0; // clears current position!
			for (int i = 0; i < 10; i++) {
				(*turtleX)--;
				if (*penDown == 1) {
					array[*turtleX][*turtleY] = 1;
				}
				else {
					array[*turtleX][*turtleY] = 0;
				}
			}			
		}
		else {
			printf("Turtle would move out of bounds. Change directions.\n");
		}
	}
} // End moveTenSpaces

/******************************************************************************
	Function: printFloor()
	Description: Prints the "game" floor in formatted output
	Side Effects: ---
	Parameters: array[HEIGHT][WIDTH], int turtleX, int turtleY
	Return: ---
******************************************************************************/
void printFloor(int array[HEIGHT][WIDTH], int turtleX, int turtleY) {
	printf("Printing game floor!\n");
	for (size_t i = 0; i < HEIGHT; ++i) {
		for (size_t j = 0; j < WIDTH; ++j) {

			printf("%d ", array[i][j]);
		}
		puts("");
	}
} // End printFloor

void tenSpacesMessage(void) {
	printf("Moving turtle 10 spaces...\n");
}

void anySpacesMessage(int* spaces) {
	printf("Moving turtle %d spaces...\n", *spaces); 
}



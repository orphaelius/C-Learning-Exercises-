/*******************************************************************************

				// MAZE GENERATOR //

	This program combines 7.25-7.27. Initially, the program only generated 
 	a maze of a defined width and height at compile time and found the path. 
  	The cells were manually initialized. Afterwards, the program was modified 
   	to produce this effect via user input- requesting specific dimensions
    	for the size of the maze. The program was then modified to generate a
     	maze entirely at random, and the final product is a combination of all 
      	these into a fluid program that requests user input for a maze size, 
       	then it generates the maze of that size (within bounds), determines
	a fully randomized path within those parameters, prints this generated
 	maze, and then it calls a function to recursively find the path. The
  	final maze is printed to console.

	Written by: Jon-Austin Tharpe

	Date: 04/01/2025

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Maximum dimensions of the maze; allocates memory at compile, then program
// allows for a dynamic size 5 < mazeSize <= 30 via user input
#define WIDTH 30
#define HEIGHT 30 

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define YELLOW  "\x1b[33m"
#define MAGENTA "\x1b[35m"
#define BOLD    "\x1b[1m"




/*******************************************************************************
	Structure: Celltype
	Description: enum struct to store the 'types' of cells represented by the
	maze. All elements default to WALL when maze is initialized.
	Members: WALL, PATH, START, FINISH, VISITED
	Details: In memory, these are simply integer values (think of an array)
*******************************************************************************/
typedef enum {
	WALL = '#',
	PATH = '.',
	START = 'S',
	FINISH = 'F',
	VISITED = 'x'
} CellType;

/*******************************************************************************
	Structure: Maze
	Description: Members are various ways to interact with the Maze structure.
	width and height are defined via user input, start and end coords are
	hard-coded (for now)
	Members: width, height, start/end coords, path coords
	Details: grid[][] will be used to generate the maze, which will be composed
	of Celltype members.
*******************************************************************************/
typedef struct {
	CellType grid[WIDTH][HEIGHT];
	int width;
	int height;
	int startX;
	int startY;
	int endX;
	int endY;
	int pathX;
	int pathY;
	int xPos;
	int yPos;
	int spriteX;
	int spriteY;
} Maze;

void getMazeDimensions(Maze* mPtr);
void assignGridElements(Maze* mPtr);
void initializeMazeWalls(Maze* mPtr);
int isValidMove(Maze* mPtr, int x, int y);
void shuffleDirections(int directions[4][2]);
void generateRandomPath(Maze* mPtr, int startX, int startY);
int recursivePath(Maze* mPtr, int spriteX, int spriteY);
void printMaze(Maze* mPtr);

/*******************************************************************************
	Function: main()
	Description: Calls series of functions to initialize and generate a 
	random maze path based on user input parameters, then finds the path
	recurisively
	Parameters: ---
	Return: ---
*******************************************************************************/
int main(void) {
	srand(time(NULL));
	Maze m;
	Maze* mPtr = &m;

	getMazeDimensions(mPtr);
	initializeMazeWalls(mPtr);
	assignGridElements(mPtr);
	generateRandomPath(mPtr, (*mPtr).startX, (*mPtr).startY); 
	printMaze(mPtr);
	recursivePath(mPtr, (*mPtr).spriteX, (*mPtr).spriteY);
	printMaze(mPtr);

	return 0;
} // End main()

/*******************************************************************************
	Function: getMazeDimensions()
	Description: Passes pointer to the Maze structure and allows a user to
	determine the width and height of their maze. It assigns these values to
	width and height inside the Maze structure. I've included do... while checks
	to ensure that a user stays within the basic dimensional limitations of the
	maze structure defined at compile time.
	Parameters: Pointer to Maze struc
	Return/Side effect: No return, but updates the variables width and height
	within Maze structure
*******************************************************************************/
void getMazeDimensions(Maze* mPtr) {
	// Variables to take user input
	int width = 0;
	int height = 0;
	printf("The maximum dimensions of the maze are 30x30.\n");
	printf("The minimum dimnsions of the maze are 5x5.\n");

	do {
		printf("Please enter the width of your maze (1-30): ");
		scanf("%d", &width);
		if (width < 5 || width > 30) {
			printf("Invalid entry! Please stay within the limitations.\n");
		}
	} while (width < 5 || width > 30);

	do {
		printf("Please enter the height of your maze (1-30): ");
		scanf("%d", &height);
		if (height < 5 || height > 30) {
			printf("Invalid entry! Please stay within the limitations.\n");
		}
	} while (height < 5 || height > 30);

	// Assigns input values to members of Maze structure
	(*mPtr).height = height;
	(*mPtr).width = width;


} // End getMazeDimensions()

/*******************************************************************************
	Function: initializeMazeWalls()
	Description: Initializes the entire maze as "walls" to start, which are
	assigned the char value '#' in the structure
	Parameters: Points to Maze
	Return: ---
*******************************************************************************/
void initializeMazeWalls(Maze* mPtr) {
	for (size_t i = 0; i < (*mPtr).height; ++i) {
		for (size_t j = 0; j < (*mPtr).width; ++j) {
			(*mPtr).grid[i][j] = WALL;
		}
	}
} // End initializeMazeWalls()

/*******************************************************************************
	Function: assignGridElements()
	Description: Assigns vital elements of the maze, like the start x and y
	coordinates for the "sprite" and the START and FINISH locations.
	Parameters: Points to Maze
	Return: ---
*******************************************************************************/
void assignGridElements(Maze* mPtr) {
	(*mPtr).startX = 0;
	(*mPtr).startY = 2;
	(*mPtr).spriteX = (*mPtr).startX;
	(*mPtr).spriteY = (*mPtr).startY;
	(*mPtr).grid[(*mPtr).startX][(*mPtr).startY] = START;
	(*mPtr).grid[(*mPtr).height - 2][(*mPtr).width - 1] = FINISH;

} // End assignGridElements()

/*******************************************************************************
	Function: isValidMove()
	Description: Checks whether a given cell is a valid position to modify into
	a "PATH" cell. The cell is valid if those coordinates are within the Maze
	bounds AND the cell getting modifid is currently a WALL. 
	Parameters: Points to Maze, newX and Y integer values (positions)
	Return: ---
*******************************************************************************/
int isValidMove(Maze* mPtr, int newX, int newY) {
	return (newX > 0 && newX < (*mPtr).height - 1 &&
		newY > 0 && newY < (*mPtr).width - 1 &&
		(*mPtr).grid[newX][newY] == WALL);
}

/*******************************************************************************
	Function: shuffleDirections()
	Description: Shuffles the possible direction vectors used during the generation
	of Maze to ensure a "randomized" traversal path.
	Parameters: 2D integer array representing movement vectors
	Return: ---
*******************************************************************************/
void shuffleDirections(int directions[4][2]) {
	for (int i = 0; i < 4; i++) {
		int j = rand() % 4;
		int tempX = directions[i][0];
		int tempY = directions[i][1];
		directions[i][0] = directions[j][0];
		directions[i][1] = directions[j][1];
		directions[j][0] = tempX;
		directions[j][1] = tempY;
	}
}

/*******************************************************************************
	Function: generateRandomPath()
	Description: Generates a maze path using depth-first search and randomized
	direction "shuffling." Determines PATH by visiting neighboring cells.
	Parameters: Points to Maze, startx, starty coords
	Return: ---
*******************************************************************************/
void generateRandomPath(Maze* mPtr, int startX, int startY) {
	(*mPtr).grid[startX][startY] = PATH;

	int directions[4][2] = {
		{-2, 0}, {2, 0}, {0, -2}, {0, 2}
	};

	shuffleDirections(directions);

	for (int i = 0; i < 4; i++) {
		int newX = startX + directions[i][0];
		int newY = startY + directions[i][1];

		if (isValidMove(mPtr, newX, newY)) {
			// Carve wall between current and new cell
			int wallX = startX + directions[i][0] / 2;
			int wallY = startY + directions[i][1] / 2;
			(*mPtr).grid[wallX][wallY] = PATH;
			generateRandomPath(mPtr, newX, newY);			
		}
	}
}


int recursivePath(Maze* mPtr, int spriteX, int spriteY) {

	if ((*mPtr).grid[spriteX][spriteY] == FINISH) {
		return 1;
	}

	if ((*mPtr).grid[spriteX][spriteY] != PATH && (*mPtr).grid[spriteX][spriteY] != START) {
		return 0;
	}

	CellType temp = (*mPtr).grid[spriteX][spriteY];
	(*mPtr).grid[spriteX][spriteY] = VISITED;

	// Explore neighboring cells (down, up, right, left)
	if (spriteX + 1 < mPtr->height && recursivePath(mPtr, spriteX + 1, spriteY)) return 1;
	if (spriteX - 1 >= 0 && recursivePath(mPtr, spriteX - 1, spriteY)) return 1;
	if (spriteY + 1 < mPtr->width && recursivePath(mPtr, spriteX, spriteY + 1)) return 1;
	if (spriteY - 1 >= 0 && recursivePath(mPtr, spriteX, spriteY - 1)) return 1;

	(*mPtr).grid[spriteX][spriteY] = temp; // backtrack
	return 0;

} // 



/*******************************************************************************
	Function: printMaze()
	Description: Prints Maze structure/members/etc
	Parameters: Points to Maze
	Return: ---
*******************************************************************************/
void printMaze(Maze* mPtr) {
	puts(""); // Adds left padding to console display, just cleaner look

	for (int i = 0; i < (*mPtr).height; i++) {  // Loop over rows
		for (int j = 0; j < (*mPtr).width; j++) {  // Loop over columns 
			// Print the character representation of the cell
			switch ((*mPtr).grid[i][j]) {
			case START:
				printf(BOLD GREEN "  S" RESET);
				break;
			case FINISH:
				printf(BOLD RED "  E" RESET);
				break;
			case PATH:
				printf(CYAN "  ." RESET);
				break;
			case VISITED:
				printf(YELLOW "  x" RESET);
				break;
			case WALL:
				printf(BOLD "  #" RESET);
				break;

		}
		printf("\n\n"); // Add spacing for better readability
	}
} // End printMaze()

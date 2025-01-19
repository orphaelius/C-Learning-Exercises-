#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 


// The Tortoise and The Hare Race //

typedef enum { // Enumeration constants for contender MoveTypes
	FAST_PLOD,
	SLIP,
	SLOW_PLOD,
	SLEEP,
	BIG_HOP,
	BIG_SLIP,
	SMALL_HOP,
	SMALL_SLIP

} MoveType;

MoveType tortoiseMoveType();
MoveType hareMoveType();

int trackPrintingFunction(); // Displays track on screen
int randomNumberGenerator(); // Randomly rolls a number to determine contender MoveType

void clearScreen(); // Clears screen with each iteration

const int finishLine = 70; // Finish line marker
int positionTortoise = 1;
int positionHare = 1;

int main(void) {
	srand(time(NULL));

	printf("================================================================================\n");
	printf("=========================== ON YOUR MARK, GET SET... ===========================\n");
	printf("=================================== BANG!!! ====================================\n");
	printf("============================= AND THEY'RE OFF!!! ===============================\n");
	printf("================================================================================\n\n\n\n");

	trackPrintingFunction(); // Displays track before race begins

	while (positionTortoise < finishLine && positionHare < finishLine) {   
		clearScreen(); // Clears screen with each iteration (once per second) to provide the illusion of moving contenders

		MoveType tortoiseMove = tortoiseMoveType(); // 
		MoveType hareMove = hareMoveType(); // 			
		
		switch (tortoiseMove) { // Updates the TORTOISE position on the track based on the MoveType roll returned from the tortoiseMoveType function
		case FAST_PLOD:
			positionTortoise += 3;				
			break;

		case SLOW_PLOD:
			positionTortoise += 1;				
			break;

		case SLIP:
			positionTortoise -= 6;				
			break;

		default:
			printf("Move type: Stopped.\t");
			printf("%d", tortoiseMove);
			break;
		}

		switch (hareMove) { // Updates the HARE position on the track based on the MoveType roll returned from the hareMoveType function
		case SLEEP:								
			break;

		case BIG_HOP:
			positionHare += 9;				
			break;

		case BIG_SLIP:
			positionHare -= 12;
			break;

		case SMALL_HOP:
			positionHare += 1;
			break;

		case SMALL_SLIP:
			positionHare -= 2;
			break;

		default:
			printf("Move type: Stopped.");
			printf("%d", hareMove);
			break;
		}	

		/* Series of checks */

		if (positionTortoise < 1) { // Ensures the position of the TORTOISE does not go below the starting position
			positionTortoise = 1;
		}

		if (positionHare < 1) { // Ensures the position of the HARE does not go below the starting position
			positionHare = 1;
		}

		if (positionTortoise > finishLine) { // If the TORTOISE passes the finish line, its position is set to the finish line 
			positionTortoise = finishLine;			
		}

		if (positionHare > finishLine) { // If the HARE passes the finish line, its position is set to the finish line  
			positionHare = finishLine;			
		}
		
		trackPrintingFunction(); // Reprints track on screen

		Sleep(1000); // Calls Windows sleep function, iterating the loop every 1 second until one of the contenders reaches the FINISH LINE		
	}		

	if (positionTortoise >= finishLine) { // Checks if TORTOISE has reached finish line, if so, displays winning message
		printf("TORTOISE WINS!!! YAY!!!\n");
	}

	if (positionHare >= finishLine) {
		printf("HARE WINS. YUCH.\n");
	}
}


int trackPrintingFunction() { // Drafts each line on the "track" and tracks/displays position of each race contender on the track
	
	for (int i = 1; i <= finishLine; i++) {		

		// printf("Line %d\t", i);
		printf("(((");
		for (int j = 0; j <= 41; j++) {

			printf("-");

			if (j == 19 || j == 21) {
				printf(")");
				printf("  ");
				printf("  ");
				printf("(");
			}
		}
		printf(")))");

		if (i == positionTortoise && i == positionHare) {
			printf(" T H");
		}

		if (i == positionTortoise) {
			printf(" T");
		}

		if (i == positionHare) {
			printf(" H");
		}	
		puts("");
		//puts("");
	}	
	printf("\n");

	return 0;
}


MoveType tortoiseMoveType() { // Calls on randomNumGen function to determine which MoveType TORTOISE rolls
	int num = randomNumberGenerator();

	if (1 <= num && num <= 5) {
		return FAST_PLOD;
	}

	if (6 <= num && num <= 7) {
		return SLIP;
	}

	if (8 <= num && num <= 10) {
		return SLOW_PLOD;
	}
}

MoveType hareMoveType() { // Calls on randomNumGen function to determine which MoveType HARE rolls
	int num = randomNumberGenerator();

	if (1 <= num && num <= 2) {
		return SLEEP;
	}

	if (3 <= num && num <= 4) {
		return BIG_HOP;
	}

	if (num == 5) {
		return BIG_SLIP;
	}

	if (6 <= num && num <= 8) {
		return SMALL_HOP;
	}

	if (9 <= num && num <= 10) {
		return SMALL_SLIP;
	}
}

int randomNumberGenerator() { // Returns random number between 1 and 10
	return rand() % 9 + 1;
}

void clearScreen() { // Clears screen for reprinting track. Sustains illusion of contestants moving along track.
	system("cls");
}

/*******************************************************************************

							// Oblique Box //

	This assignment requests a program that prints a simple table showing
	the odds of 2 players rolling either an odd or even number on a 6d die, with
	each player winning only if their odd/even number is rolled. I added some
	QOL and functional updates to make it more realistic, including a rollDie()
	function that rolls the die 10,000 times to return a more realistic
	probability of each player rolling that specific number. While potentially
	insignificant, the fundamental probability of rolling each number is
	obviously 1/6, though when applied, these odds are invariably more nuanced,
	as shown after the program runs.

	Written by: Jon-Austin

	Date: 03/07/2025

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIEVALS 6
#define PLAYERS 2
#define MAXCHARS 8

// Function Prototypes //
int rollDie(int* die);
void fillArray(int dieValues[DIEVALS]);
int fillProbability(int rollCounts[DIEVALS], int* probability);
void determineProbability(int* die, int* rollCounts);
int evenOrOdd(int dieValues[DIEVALS], int evenOdd[DIEVALS]);
void printTable(int dieValues[DIEVALS], int rollCounts[DIEVALS],
	const char players[PLAYERS][MAXCHARS], const char header[3][20],
	int evenOdd[DIEVALS], const char numberType[PLAYERS][MAXCHARS],
	int probability[DIEVALS]);
void printMinusOneTable(int dieValues[DIEVALS], int rollCounts[DIEVALS],
	const char players[PLAYERS][MAXCHARS], const char header[4][20],
	int evenOdd[DIEVALS], const char numberType[PLAYERS][MAXCHARS],
	int probability[DIEVALS]);



/*******************************************************************************
	Function: main()
	Description: Takes user input, process, prints output..
	Parameters: ---
	Return: ---
*******************************************************************************/
int main(void) {

	srand(time(NULL));
	int i = 0;
	int die = 0; // Die value rolled
	int dieValues[DIEVALS] = { 0 };
	int rollCounts[DIEVALS] = { 0 };
	int probability[DIEVALS] = { 0 };
	const char players[PLAYERS][MAXCHARS] = { "Alice", "Bob" };
	const char numberType[PLAYERS][MAXCHARS] = { "Odd", "Even" };
	int evenOdd[DIEVALS] = { 0 };
	const char header[4][20] = { "Number on Die", "Odd or Even", "Winner", "Probability" };

	fillArray(dieValues);
	determineProbability(&die, rollCounts);
	evenOrOdd(dieValues, evenOdd);

	fillProbability(rollCounts, probability);
	printTable(dieValues, rollCounts, players, header, evenOdd, numberType,
		probability);

	return 0;
} // End main()

/*******************************************************************************
	Function: fillArray()
	Description: Fill dieValues array with appropriate values
	Parameters: dieValues array
	Return: ---
*******************************************************************************/
void fillArray(int dieValues[DIEVALS]) {
	for (int i = 0; i < DIEVALS; ++i) {
		dieValues[i] = i + 1;
	}
} // End fillArray()

/*******************************************************************************
	Function: determineProbability()
	Description: Takes the 1/6 odds to new heights by "rolling" the die 10,000
	times, using a counting mechanic to keep track of each rolled value
	Parameters: Points to die, points to rollCounts, the array of value counts
	Return: ---
*******************************************************************************/
void determineProbability(int* die, int* rollCounts) {

	for (int i = 0; i < 10000; ++i) {
		*die = rollDie(die);
		*(rollCounts + *die - 1) += 1;
	}
} // End determineProbability()

/*******************************************************************************
	Function: fillProbability()
	Description: Takes rollCounts array counts for each rolled value and
	calculates the probability of each value being rolled out of total rolls
	Parameters: rollCounts array, points to probability array
	Return: Probability
*******************************************************************************/
int fillProbability(int rollCounts[DIEVALS], int* probability) {

	for (int i = 0; i < DIEVALS; ++i) {
		*(probability + i) = (rollCounts[i] / 10000.0) * 100.0; // percentage
		//printf("die %d chance: %d\n", i + 1, probability[i]);
	}

	return *probability;
} // End fillProbability()

/*******************************************************************************
	Function: evenOrOdd()
	Description: Dynamically determines which values are even or odd instead of
	simply printing these arbitrarily to the console
	Parameters: ---
	Return: evenOdd array//whether element is even or odd
*******************************************************************************/
int evenOrOdd(int dieValues[DIEVALS], int evenOdd[DIEVALS]) {
	for (size_t i = 0; i < DIEVALS; i++) {
		if ((dieValues[i] % 2) == 0) {
			evenOdd[i] = 1; // 1 for even, true
		}
		else {
			evenOdd[i] = 0; // 0 for odd, false
		}
	}
	return evenOdd[DIEVALS];
} // End evenOrOdd()

/*******************************************************************************
	Function: rollDie()
	Description: Simple, rolls a 6d die, returns random value
	Parameters: Points to die
	Return: Random die value
*******************************************************************************/
int rollDie(int* die) {
	*die = rand() % 6 + 1;
	return *die;
} // End rollDie()

/*******************************************************************************
	Function: printTable()
	Description: Prints all results from functions in formatted tabular output
	to console
	Parameters:
	Return: ---
*******************************************************************************/
void printTable(int dieValues[DIEVALS], int rollCounts[DIEVALS],
	const char players[PLAYERS][MAXCHARS], const char header[4][20],
	int evenOdd[DIEVALS], const char numberType[PLAYERS][MAXCHARS],
	int probability[DIEVALS]) {

	int j = 0; // boolean for even/odd in loop, used as index
	int winner = 0; // boolean for winner, used as index

	// Print header
	for (int i = 0; i < 4; ++i) {
		printf("%s\t", header[i]);
	}
	puts("");
	for (int i = 0; i < 51; ++i) {
		printf("%c", '-');

	} // End print header
	puts("");

	for (int i = 0; i < DIEVALS; ++i) {

		if (evenOdd[i] == 0) {
			j = 0;
			winner = 0;
		}
		else {
			j = 1;
			winner = 1;
		}

		printf("%13d\t%11s\t%6s%12d%%", dieValues[i], numberType[j], players[winner],
			probability[i]);
		puts("");
	}

} // End printTable()

void printMinusOneTable(int dieValues[DIEVALS], int rollCounts[DIEVALS],
	const char players[PLAYERS][MAXCHARS], const char header[4][20],
	int evenOdd[DIEVALS], const char numberType[PLAYERS][MAXCHARS],
	int probability[DIEVALS]) {

	int j = 0; // boolean for even/odd in loop, used as index
	int winner = 0; // boolean for winner, used as index

	// Print header
	for (int i = 0; i < 4; ++i) {
		printf("%s\t", header[i]);
	}
	puts("");
	for (int i = 0; i < 51; ++i) {
		printf("%c", '-');

	} // End print header
	puts("");

	for (int i = 0; i < DIEVALS; ++i) {

		if (evenOdd[i] == 0) {
			j = 0;
			winner = 0;
		}
		else {
			j = 1;
			winner = 1;
		}

		printf("%13d\t%11s\t%6s%12d%%", dieValues[i], numberType[j], players[winner],
			probability[i]);
		puts("");
	}

} // End printTable()




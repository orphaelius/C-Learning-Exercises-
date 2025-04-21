#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TOTALSTRINGS 6 // Current amount of strings
#define STRINGMAXCHAR 100 // Limit memory for input

// Function prototypes
void getStrings(char inputStrings[][STRINGMAXCHAR]);
void convertAllStrings(char inputStrings[][STRINGMAXCHAR], int convertedIntegers[], char* len);
void calcSum(int convertedIntegers[], int* sum);
void calcAverage(int convertedIntegers[], int* sum, int* average);

int main(void) {
	char inputStrings[TOTALSTRINGS][STRINGMAXCHAR] = { {0} };
	int convertedIntegers[6] = { 0 };
	char len = 0;
	int sum = 0;
	int average = 0;

	getStrings(inputStrings); // Get strings
	// Convert to integer values
	convertAllStrings(inputStrings, convertedIntegers, &len);
	calcSum(convertedIntegers, &sum);
	calcAverage(convertedIntegers, &sum, &average);
	/* 
	for (size_t i = 0; i < TOTALSTRINGS; ++i) {
		printf("number %zu: %d\n", i + 1, convertedIntegers[i]);
	} */

	return 0;
} // End main()

void getStrings(char inputStrings[][STRINGMAXCHAR]) {
	for (size_t i = 0; i < TOTALSTRINGS; ++i) {
		printf("Enter an integer string: ");
		if (fgets(inputStrings[i], STRINGMAXCHAR, stdin)) {
			size_t len = strlen(inputStrings[i]);
			if (len > 0 && inputStrings[i][len - 1] == '\n') {
				inputStrings[i][len - 1] = '\0';
			}
			printf("You entered: %s\n", inputStrings[i]);
		}
		else {
			fprintf(stderr, "Input error.\n");
		}
	}
} // End getStrings()

void convertAllStrings(char inputStrings[][STRINGMAXCHAR], int convertedIntegers[], char* len) {
	for (size_t i = 0; i < TOTALSTRINGS; ++i) {
		convertedIntegers[i] = strtol(inputStrings[i], &len, 10);
	}
} // End convertAllStrings()

void calcSum(int convertedIntegers[], int* sum) {
	for (size_t i = 0; i < TOTALSTRINGS; ++i) {
		*sum += convertedIntegers[i];
	}
	printf("Sum of the converted integer strings: %d", *sum);
} // End calcSum()

void calcAverage(int convertedIntegers[],int* sum, int* average) {
	*average = *sum / TOTALSTRINGS;
	printf("average of the converted integer strings: %d", *average);
} // End calcAverage()



// Very simple progrma to convert an input phrase into Pig Latin //

#include <stdio.h>
#include <string.h>
#define MAXINPUT 100

// Function prototypes
void inputString(char string[], int* len);
void convertString(char* string, char* string2);

// Main
int main(void) {
	char inputPhrase[MAXINPUT] = { " " };
	char pigLatinPhrase[MAXINPUT] = { " " }; 
	int len = 0;
	
	inputString(inputPhrase, &len);
	printf("Entered: %s\n", inputPhrase);
	convertString(inputPhrase, pigLatinPhrase);  
	printf("new string: %s\n", pigLatinPhrase);  
	return 0;
} // End main()

// Grab string via user input
void inputString(char string[], int *len) {
	printf("Enter a phrase to encode into Pig Latin: ");
	fgets(string, MAXINPUT, stdin);
	string[strlen(string) - 1] = '\0';
	*len = strlen(string);	
} // End inputString()

void convertString(char* string, char* string2) {	
	char tempString[MAXINPUT] = { "" }; // For transferring updated string into
	char* token = strtok(string, " "); // Delimits tokens by spaces
	char firstLetters[2] = { " " }; // Stores first letters of each word during while loop	
	int tempLength = 0; // Used to determine length of each token
	int charsToCopy = 0; // Determines total characters to copy over
	
	// Seperates string into individual tokens
	while (token != NULL) {
		tempLength = strlen(token);
		charsToCopy = -1 + tempLength;
		strncat(string2, token + tempLength - charsToCopy, charsToCopy);

		firstLetters[0] = token[0];
		strcat(string2, firstLetters);
		strcat(string2, "ay");
		strcat(string2, " ");

		token = strtok(NULL, " ");
	}	
} // End convertString()


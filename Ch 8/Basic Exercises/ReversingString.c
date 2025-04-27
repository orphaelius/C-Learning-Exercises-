// This program takes user input then reverses and tokenizes/reverses that string //

#include <stdio.h>
#include <string.h>
#define MAXINPUT 150

// Function prototypes
void inputString(char string[], int* len);
void reverseString(char userString[], char* reversedString); 
void tokenizeReverseString(char userString[], char* reversedString);

// Main
int main(void) {
	char userString[MAXINPUT] = { " " };
	char reversedString[MAXINPUT] = { " " };
	char reversedString2[MAXINPUT] = { " " }; 
	int len = 0;
	inputString(userString, &len); 
	reverseString(userString, reversedString);
	printf("You entered %s\n", userString);
	printf("Reversed string: %s\n", reversedString);

	tokenizeReverseString(userString, reversedString2);
	printf("Tokenized and reversed string: %s", reversedString2);
	return 0;
} // End main()

void inputString(char string[], int* len) {
	printf("Enter a phrase to have reversed: ");
	fgets(string, MAXINPUT, stdin); 
	string[strlen(string) - 1] = '\0';
	*len = strlen(string);
} // End inputString()

void reverseString(char userString[], char* reversedString) {
	// Defines a string length to be used as a condition 
	// and assign a NULL terminator 
	int inputStrLen = strlen(userString);
	userString[inputStrLen] = '\0';
	reversedString[inputStrLen] = '\0';
	// Loop that assigns the last element of input string to
	// the first element of the reversed string
	for (size_t i = 0; i < inputStrLen; ++i) {
		reversedString[i] = userString[inputStrLen - 1 - i];
	}
} // End reverseString()

void tokenizeReverseString(char userString[], char* reversedString) {
	char* token = strtok(userString, " ");
	char tempString[MAXINPUT] = { "" }; 	

	while (token != NULL) {
		strcat(tempString, token);	 		
		token = strtok(NULL, " ");
	}

	int inputStrLen = strlen(tempString); 
	tempString[inputStrLen] = '\0'; 
	reversedString[inputStrLen] = '\0';  
	// Loop that assigns the last element of input string to
	// the first element of the reversed string

	for (size_t i = 0; i < inputStrLen; ++i) { 
		reversedString[i] = tempString[inputStrLen - 1 - i]; 
	}	
} // End tokenizeReverseString()
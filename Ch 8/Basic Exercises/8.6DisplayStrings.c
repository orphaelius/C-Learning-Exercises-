// Take a string as input and display in lower/upper case //

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRINGLIMIT 100
void getString(char userString[]);
void convertToLower(char userString[]);
void convertToUpper(char userString[]);
void displayString(char userString[]); 

int main(void) {
	char userString[STRINGLIMIT] = { " " }; 
	getString(userString);
	displayString(userString);

	convertToLower(userString);
	displayString(userString);

	convertToUpper(userString);
	displayString(userString);
}

void getString(char userString[]) {
	printf("Enter any string: ");
	fgets(userString, STRINGLIMIT, stdin);
	userString[strcspn(userString, "\n")] = '\0';	
}

void convertToLower(char userString[]) {
	for (size_t i = 0; i < strlen(userString); ++i) {
		userString[i] = tolower(userString[i]); 
	}	
}

void convertToUpper(char userString[]) {
	for (size_t i = 0; i < strlen(userString); ++i) {
		userString[i] = toupper(userString[i]);
	}
}

void displayString(char userString[]) {
	printf("String: %s\n", userString);
} 
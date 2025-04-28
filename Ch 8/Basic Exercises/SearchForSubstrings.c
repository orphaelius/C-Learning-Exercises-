// Take input for a string and substring, use strstr() to find the first and second 
// occurrence of that substring. Print the remaining portions of the string, etc.

#include <stdio.h>
#include <string.h>
#define MAXINPUT 150

// Function prototypes
void inputString(char string[]);
void findSubstring(char string[], char searchString[]); 

// Main()
int main(void) {
	char userString[MAXINPUT] = { "" };
	char searchString[MAXINPUT] = { "" };
	printf("Enter a string: ");
	inputString(userString);
	printf("Enter a string to search within string: ");
	inputString(searchString);
	findSubstring(userString, searchString);

	return 0;
} // End main()

void inputString(char string[]) {
	fgets(string, MAXINPUT, stdin);
	string[strlen(string) - 1] = '\0';	
} // End inputString()

void findSubstring(char string[], char searchString[]) {
	char* searchPtr;
	int len = 0;
	len = strlen(string);
	int found = 0;

	searchPtr = strstr(string, searchString);
	if (searchPtr != NULL) {
		printf("Substring found at position: %ld\n", searchPtr - string);
		printf("Substring: %s\n", searchPtr);
		found = 1;
	}
	else {
		printf("Substring not found.\n");		
	}
	if (!found) {
		return;
	}
	else {
		searchPtr = strstr(searchPtr + 1, searchString);
		if (searchPtr != NULL) {
			printf("Substring found at position: %ld\n", searchPtr - string);
			printf("Substring: %s\n", searchPtr);
		}
		else {
			printf("Substring not found.\n");
		}
	}	
} // End findSubstring()
	

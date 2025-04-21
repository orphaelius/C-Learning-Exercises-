#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGMAXCHAR 100 
/*
pt2

use strncat to append par tof a string to another
- input two strings
- input the number of chars to append
display first string
sdisplay first string length
displahy appended string


*/

void inputString(char string[]);
void concatStrings(char string1[], char string2[]);
void appendString(char string1[], char string2[]);

int main(void) {
	char string1[STRINGMAXCHAR] = { "" };
	char string2[STRINGMAXCHAR] = { "" };

	/*---------- Begin 8.9 ----------*/
	inputString(string1);
	inputString(string2);

	printf("String 1: %s\n", string1);
	printf("String 1: %s\n", string2);
	concatStrings(string1, string2);
	printf("Concatenated string: %s\n", string1);

	/*---------- Begin 8.10 ----------*/
	inputString(string1);
	inputString(string2);

	printf("String 1: %s\n", string1);
	printf("String 1 length: %d\n", strlen(string1));

	appendString(string1, string2);
	printf("New string 1: %s\n", string1);	

} // End main()

void inputString(char string[]) {
	printf("Enter a string: ");
	fgets(string, STRINGMAXCHAR, stdin);	
	string[strcspn(string, "\n")] = '\0';
} // End inputString()

void concatStrings(char string1[], char string2[]) {
	strcat(string1, " ");
	strcat(string1, string2);
	string1[strcspn(string1, "\n")] = '\0';
	//string1[strlen(string1)] = '\0';
} // End concatStrings()

void appendString(char string1[], char string2[]) {
	size_t appendChars = 0;
	printf("Enter total characters to append from string 2 to string 1: ");
	scanf("%zu", &appendChars);
	strncat(string1, string2, appendChars);
} // End appendString()
// Testing the Character Handling Library //

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIBFUNCTIONS 13

int getCharacter(int* inputChar);
void testAgainstLibrary(char inputChar);

int main(void) {
	int inputChar = ' ';
	getCharacter(&inputChar);
	printf("you entered: %c\n\n", inputChar);
	testAgainstLibrary(inputChar);
	return 0;
}

// Pass by reference initially
int getCharacter(int* inputChar) {
	printf("Enter a character: ");
	*inputChar = getchar();
	return *inputChar;
}

// Streamlined the exercise by embedding all char functions within
// a single test function; loops through functions by deploying the
// counter variable as a switch key
void testAgainstLibrary(char inputChar) {
	int alpha = 0; 
	for (size_t i = 0; i < LIBFUNCTIONS; ++i) {
		switch (i) {			
			
		case 0: // isdigit()
			if (isdigit(inputChar) != 0) {
				printf("%c is a digit.\n", inputChar);
			}
			else {
				printf("%c is not a digit.\n", inputChar);
			}
			break;

		case 1: // isalpha();
			if (isalpha(inputChar) != 0) {
				alpha = 1;
				printf("%c is a letter.\n", inputChar);
			}
			else {
				printf("%c is not a letter.\n", inputChar);
			}
			break;

		case 2: // isalnum();
			if (isalnum(inputChar) != 0) {
				printf("%c is a digit/letter.\n", inputChar);
			}
			else {
				printf("%c is not a digit/letter.\n", inputChar);
			}
			break;

		case 3: // isgraph();
			if (isgraph(inputChar) != 0) {
				printf("%c is a printing character other than a space.\n", inputChar);
			}
			else {
				printf("%c is not a printing character other than a space.\n", inputChar);
			}
			break;

		case 4: // isxdigit();
			if (isxdigit(inputChar) != 0) {
				printf("%c is a hexidecimal digit character.\n", inputChar);
			}
			else {
				printf("%c is not a hexidecimal digit character.\n", inputChar);
			}
			break;

		case 5: // islower();
			if (islower(inputChar) != 0) {
				printf("%c is a lowercase letter.\n", inputChar);
			}
			else {
				printf("%c is not a lowercaseletter.\n", inputChar);
			}
			break;

		case 6: // isupper();
			if (isupper(inputChar) != 0) {
				printf("%c is an uppercase letter.\n", inputChar);
			}
			else {
				printf("%c is not an uppercase letter.\n", inputChar);
			}
			break;

		case 7: // tolower();
			if (alpha) {
				int tempChar = inputChar;
				tempChar = tolower(tempChar);
				printf("Lowercase %c is %c\n", inputChar, tempChar);
			}
			else {
				printf("%c is not a letter, cannot change to lowercase.\n", inputChar);
			}			
			break;

		case 8: //toupper()
			if (alpha) {
				int tempChar = inputChar;
				tempChar = toupper(tempChar);
				printf("Uppercase %c is %c\n", inputChar, tempChar);;
				break;
			}
			else {
				printf("%c is not a letter, cannot change to uppercase.\n", inputChar);
			}
			break;  

		case 9: // isspace();
			if (isspace(inputChar) != 0) {
				printf("%c is a whitespace character.\n", inputChar);
			}
			else {
				printf("%c is not a whitespace character.\n", inputChar);
			}
			break;

		case 10: // iscntrl();
			if (iscntrl(inputChar) != 0) {
				printf("%c is a control character.\n", inputChar);
			}
			else {
				printf("%c is not a control character.\n", inputChar);
			}
			break;

		case 11: // ispunct();
			if (ispunct(inputChar) != 0) {
				printf("%c is a printing character other than a space, digit, or letter.\n", inputChar);
			}
			else {
				printf("%c is not a printing character other than a space, digit, or letter.\n", inputChar);
			}
			break;

		case 12: // isprint();
			if (isprint(inputChar) != 0) {
				printf("%c is a printing character.\n", inputChar);
			}
			else {
				printf("%c is not a printing character.\n", inputChar);
			}
			break;

		default:
			printf("How did I get here? What does it mean to be alive?");

		}
	}	
}
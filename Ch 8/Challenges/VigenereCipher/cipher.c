#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cipherHeader.h" 
#define MAXINPUT 150
#define LETTERS 26

void initializeVigenere(char vigenereSquare[LETTERS][LETTERS]);  
void checkKey(char secretKey[], int* isFalse);
void getString(char string[]);
void encrypt(char* secretKey, char* stringToEncrypt, char* encryptedString); 
void decrypt(char* secretKey, char* decryptedString, char* stringToDecrypt);
int getKey(int* switchKey);  
void showInstructions(void); 
void rinsePalate(); 

int main(void) {
	//char* secretKey = "XMWUJBVYHXZ"; -- key given in exercise
	char secretKey[MAXINPUT] = { "" };
	char stringToEncrypt[MAXINPUT] = { "" };
	char encryptedString[MAXINPUT] = { "" };
	char decryptedString[MAXINPUT] = { "" };
	char stringToDecrypt[MAXINPUT] = { "" };
	char vigenereSquare[LETTERS][LETTERS];
	int isFalse = 0;
	int switchKey = 0;
	showInstructions();
	while ((*switchKey = getKey(&switchKey)) != -1) { 

		switch (*switchKey) {

		case 1: // Enter Secret key	 
			printf("Enter an alphabetical secret key: ");
			rinsePalate();
			getString(secretKey);
			checkKey(secretKey, &isFalse);
			break;

		case 2: // Encrypt a message	
			printf("Enter a sentence to encrypt: ");
			rinsePalate();
			getString(stringToEncrypt);
			printf("Encrypting %s...\n", stringToEncrypt);
			encrypt(secretKey, stringToEncrypt, encryptedString); 
			break;

		case 3: // Decrypt a message	
			printf("Enter a string to decrypt: ");
			getString(stringToDecrypt);
			printf("Decrypting %s...\n", stringToDecrypt); 
			decrypt(secretKey, decryptedString, stringToDecrypt);  
			break;		
		}
		
		showInstructions(); 
		  
	}	
	 
	return 0;
} // End main()

/******************************************************************************
	Function: showInstructions()
	Description: Prints instructions
	Side Effects: ---
	Parameters: ---
	Return: ---
******************************************************************************/
void showInstructions() {
	char instructions[4][MAXINPUT] = {
		{"Enter 1 to enter the secret key"},
		{"Enter 2 to encrypt a message"},
		{"Enter 3 to decrypt a message"},
		{"Enter -1 to exit"}
	};

	for (size_t i = 0; i < 4; ++i) {
		printf("%s\n", instructions[i]); 
	}	
	puts("");
	printf("Input: ");
} // End showInstructions()

/******************************************************************************
	Function: getKey()
	Description: Grabs switch key for case labels
	Side Effects: ---
	Parameters: getSwitchKey pointer-- modifies the value at the address
	Return: Returns updated value at getSwitchKey address
******************************************************************************/
int getKey(int* switchKey) {
	scanf("%d", switchKey); 
	return *switchKey; 
} // End getKey()

/*******************************************************************************
	Function: iuitializeVigenere()
	Description: Initializes 2D vigenereSquare array with appropriate letters;
	not currently implemented
	Parameters: ---
	Return: ---
*******************************************************************************/
void initializeVigenere(char vigenereSquare[LETTERS][LETTERS]) {
	for (size_t i = 0; i < LETTERS; i++) {
		for (size_t j = 0; j < LETTERS; j++) {
			vigenereSquare[i][j] = 'A' + (i + j) % LETTERS;
		}
	}
} // end initializeVigenere()

/*******************************************************************************
	Function: getString()
	Description: Grabs user input, null terminates input string
	Parameters: ---
	Return: ---
*******************************************************************************/
void getString(char string[]) {
	fgets(string, MAXINPUT, stdin);
	string[strlen(string) - 1] = '\0';
} // End inputString()

/*******************************************************************************
	Function: checkKey()
	Description: Determines if a string (key in this case) contains only
	letters (alphanumeric); returns 0 if string is all letters, else returns > 0
	Parameters: ---
	Return: ---
*******************************************************************************/
void checkKey(char secretKey[], int* isFalse) {
	for (size_t i = 0; i < strlen(secretKey); ++i) {
		if (isalpha(secretKey[i]) == 0 && secretKey[i] != '\0') {
			printf("%c\n", secretKey[i]);
			(*isFalse)++;
			break;
		}
	}
	
	if (*isFalse != 0) {
		printf("secret key contains non-letters and is not useable.\n");
		printf("Enter a new secret key: ");
		getString(secretKey); 
		checkKey(secretKey, isFalse);
	}
	else {
		printf("secret key contains only letters\n");		
	}
} // End checkKey()

/*******************************************************************************
	Function: encrypt()
	Description: Encrypts input string using the secret key, copies encrypted
	characters to new string
	Parameters: ---
	Return: ---
*******************************************************************************/ 
void encrypt(char* secretKey, char* stringToEncrypt, char* encryptedString) { 
	char cipher;
	int cipherIntValue = 0;
	int len = strlen(secretKey);
	char tempString[2]; 

	for (size_t i = 0; i < strlen(stringToEncrypt); ++i) {
		
		// If char is lowercase, range is [97-122]
		if (islower(stringToEncrypt[i])) {
			cipherIntValue = ((int)stringToEncrypt[i] - 97 +
				(int)tolower(secretKey[i % len]) - 97) % LETTERS + 97;
			cipher = (char)cipherIntValue; 
			tempString[0] = cipher;
			tempString[1] = '\0';
			strcat(encryptedString, tempString);
		}
		// If char is uppercase [65-90]
		else if (isupper(stringToEncrypt[i])) { 
			cipherIntValue = ((int)stringToEncrypt[i] - 65 +
				(int)toupper(secretKey[i % len]) - 65) % LETTERS + 65; 
			cipher = (char)cipherIntValue; 
			tempString[0] = cipher;
			tempString[1] = '\0';
			strcat(encryptedString, tempString);     
		}	
		else {
			tempString[0] = stringToEncrypt[i];
			strcat(encryptedString, tempString);
		}
	}

	printf("Encrypted string: %s\n", encryptedString);	
} // End encrypt()


void decrypt(char* secretKey, char* decryptedString, char* stringToDecrypt) {
	char tempString[2];
	int letterIndex = 0;
	char cipher;
	int cipherIntValue;
	int len = strlen(secretKey);

	for (size_t i = 0; i < strlen(stringToDecrypt); ++i) {

		// if char is lowercase, range is [97-122]
		if (islower(stringToDecrypt[i])) {
			cipherIntValue = ((int)stringToDecrypt[i] - 97 - ((int)tolower(secretKey[letterIndex % len]) - 97) + LETTERS) % LETTERS + 97;
			cipher = (char)cipherIntValue;
			tempString[0] = cipher;
			tempString[1] = '\0';
			strcat(decryptedString, tempString);
			letterIndex++;
		}
		else if (isupper(stringToDecrypt[i])) { // if it's uppercase [65-90]
			cipherIntValue = ((int)stringToDecrypt[i] - 65 - ((int)toupper(secretKey[letterIndex % len]) - 65) + LETTERS) % LETTERS + 65;
			cipher = (char)cipherIntValue;
			tempString[0] = cipher;
			tempString[1] = '\0';
			strcat(decryptedString, tempString);
			letterIndex++;
		}
		else {
			tempString[0] = stringToDecrypt[i]; 
			tempString[1] = '\0';
			strcat(decryptedString, tempString); 
		}
	}
	printf("Decrypted string: %s\n", decryptedString);
} // End decrypt()

/*******************************************************************************
	Function: rinsePalate()
	Description: Clears buffer
	Parameters: ---
	Return: ---
*******************************************************************************/
void rinsePalate() {
	char endOfLine[10];
	fgets(endOfLine, 10, stdin);
} // End rinsePalate()

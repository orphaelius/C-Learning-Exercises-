#include <stdio.h>

// Separating Digits //

/* write program segements to accomplish each of the following:
a) calculate the int part of the quotient when int a is
divided by int b

b) calculate the int remainder when int a is divded by int b

c) use the program pieces developed above to write a function
that inputs an integer between 1 and 32767 and prints it as a
series of digits, with two spaces between each digit.*/

int digitSeries(int inputNum); // Function prototype 
int printArray(int inputNum); 

int a = 20;
int b = 37;
int quotient = a / b;
int remainder = a % b;

int inputNum = 0;
int digitsArray[5] = { };  
int digitsArrayLength = sizeof(digitsArray) / sizeof(digitsArray[0]);

int main(void) {
	printf("The int part of the quotient when int a is divided by int b is: %d\n", quotient);
	printf("The int part of the remainder when int a is divided by int b is: %d\n", remainder);

	printf("Input any number between 1 and 32767: \n");
	scanf("%d", &inputNum);

	printArray(inputNum);  
}


// This function collects an input number from the user, stores in an array, and prints each index with two spaces between each digit.
int printArray(int inputNum) {

	if (inputNum > 32767 || inputNum <= 0) {
		printf("This is not a valid parameter.");
	}

	int tempNum = inputNum; 	

	for (int i = 0; i < digitsArrayLength; i++) {
		digitsArray[i] = tempNum % 10; // Stores last digit as current index 
		tempNum = tempNum / 10; // Removes last digit from input number      
	}

	for (int i = 0; i < digitsArrayLength / 2; i++) { // Reverses order of array to print digits correctly
		int tempOrder = digitsArray[i];
		digitsArray[i] = digitsArray[digitsArrayLength - i - 1];
		digitsArray[digitsArrayLength - i - 1] = tempOrder; 
	}

	int beginningZeros = 0; // Flag to check for zeros in front of significant digits in the array. So, if user enters something like "123," 
	// since the maximum array length holds up to 5 digits, it will not print 00123 and instead starts printing only when a signficant digit
	// is encountered

	for (int i = 0; i < digitsArrayLength; i++) {
		if (digitsArray[i] != 0 || beginningZeros) { 
			printf("%d ", digitsArray[i]); 
			beginningZeros = 1; // Sets to true after initial zeros have cycled through 
		}
		
	}

	return 0;   
} 

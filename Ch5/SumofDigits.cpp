#include <stdio.h>
#include <math.h>

// Sum of Digits //

/* Write a function that takes an integer and returns the sum of
its digits.*/

int sumOfDigits(int inputNum);

int inputNum = 0;

int main(void) {
	printf("Enter any number below 2 billion:\n");
	scanf("%d", &inputNum);

	sumOfDigits(inputNum); 
}

int sumOfDigits(int inputNum) { // Function to find some of each digit in an integer

	int tempNum = inputNum;
	int lengthNum = inputNum; 
	int sum = 0;
	int len = 0;	
	int lastDigit; 

	if (inputNum < 0 || inputNum > 2000000000) { // Checks if input number is a valid entry
		printf("This is not a valid parameter.\n");
		return 0;
	}

	if (lengthNum == 0) { // Finds length of input number to iterate loop below n times
		len = 1;  
	}
	else { 
		while (lengthNum != 0) { 
			lengthNum /= 10; 
			len++;    
		}		
	}
	
	for (int i = 0; i <= len; i++) { // Loops through input number (len) times to find sum
		
		lastDigit = tempNum % 10; 
		sum += lastDigit; 
		tempNum = tempNum / 10; 
		printf("Sum is %d\n", sum);

	}

	printf("Sum of %d is: %d\n", inputNum, sum); // Prints sum
	return 0;
}
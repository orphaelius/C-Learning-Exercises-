#include <stdio.h>
#include <math.h>

// Rounding Numbers //

/* write a program that reads several numbers and rounds
each of tehse numbers to the nearest integer using 
y = floor(x + .5)
for each number processed, print the original and the
rounded number. */

int main(void) {
	int maxNumbers = 0;
	float tempNum;
	float roundedNum;
	
	printf("This program rounds a series of numbers to the nearest integer.\n");
	printf("Enter the total numbers you have to start the program: \n");
	scanf("%d", &maxNumbers);   	 

	printf("%-20s %s\n\n", "Original Number", "Rounded Number");
	for (int i = 1; i <= maxNumbers; i++) { 
		printf("Enter your number: \n");
		scanf("%f", &tempNum);  

		roundedNum = floor(tempNum + .5);

		printf("%-20f %f\n", tempNum, roundedNum); 
	}
}



#include <stdio.h>
#include <math.h>

// Rounding Numbers //

/* write functions that round numbers to the nearest whole number,
tenths, hundredths, and thousandths positions */

float roundToInteger(float num);
float roundToTenths(float num);
float roundToHundreths(float num);
float roundToThousandths(float num);

float roundedNum; 
float userNum;


int main(void) {
	printf("Enter a number with up to 4 decimal places and I will round it to the neartest whole number, tenths place, hundreths place, and thousandths place:\n\n");
	scanf("%fl", &userNum);
	printf("%-20s %-20s %-20s %-20s\n", "Whole Number", "Tenths", "Hundredths", "Thousandths");
	printf("%-21.0f%-21.1f%-21.2f%.3f", roundToInteger(userNum), roundToTenths(userNum), roundToHundreths(userNum), roundToThousandths(userNum));

	
}



// Functions 
float roundToInteger(float userNum) { // Whole number
	roundedNum = floor(userNum + 0.5);
	return roundedNum;
}

float roundToTenths(float userNum) { // Tenths place
	roundedNum = floor(userNum * 10 + 0.5) / 10;
	return roundedNum;
}

float roundToHundreths(float userNum) { // Hundredths place
	roundedNum = floor(userNum * 100 + 0.5) / 100;
	return roundedNum;
}

float roundToThousandths(float userNum) { // Thousandsth place
	roundedNum = floor(userNum * 1000 + 0.5) / 1000;
	return roundedNum;
}
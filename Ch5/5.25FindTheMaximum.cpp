#include <stdio.h>

// Find the Maximum //

/* write a function hat returns the largest of four
floating point numbers. */

float largestOfFour(float num1, float num2, float num3, float num4);
float num1, num2, num3, num4;

int main(void) {
	printf("Enter 4 floating point numbers and I will return the maximum:\n");
	scanf("%f %f %f %f", &num1, &num2, &num3, &num4);
	float largest = largestOfFour(num1, num2, num3, num4);
	printf("The largest of these 4 numbers is: %f.\n", largest);    
}

float largestOfFour(float num1, float num2, float num3, float num4) {

	float largest = num1;

	if (num2 > largest) {
		largest = num2;
	}

	if (num3 > largest) {
		largest = num3;
	}

	if (num4 > largest) {
		largest = num4;
	}

	printf("Largest is %f\n", largest);
	return largest;
}

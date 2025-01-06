#include <stdio.h>
#include <math.h>

// Hypotenuse Calculator //

/* define a function called hypotenuse that calculates a right
triangle's hypotenuse based on the values of the other two 
sides. the function should take who double arguments and return
the hyptenuse as a double */

// Sides of a Triangle //

/* write a function that reads three nonzero double values
as the sides of a triangle and calculates and returns the
area of the triangle as a double variable. it should also
check whether the numbers represent the sides of a triangle
before calculating the area. use this function in a program
that inputs a series of sets of numbers. */

double hypotenuse(double side1, double side2); // Calculates hypotenuse
double calculateTriangleArea(double side1, double side2, double side3); // Calculates area of triangle

double side1 = 0;
double side2 = 0;
double side3 = 0; 

int main(void) {
	printf("Enter 3 nonzero values and I will tell you if they can represent a triangle: \n") 
	scanf("%lf %lf % lf", &side1, &side2, &side3); 

	/* Calls hypotenuse function
	printf("Enter two sides of the 90 degree triangle and I will return the hypotenuse: \n");
	scanf("%lf %lf", &side1, &side2);
	printf("The hypotenuse is: %f\n", hypotenuse(side1, side2));   
	*/





}

double hypotenuse(double side1, double side2) {
	double tempSide1 = side1 * side1;
	double tempSide2 = side2 * side2;
	double tempSum = tempSide1 + tempSide2;		
	return sqrt(tempSum);
}

double calculateTriangleArea(double side1, double side2, double side3) {
	if ((side1 + side2 > side3) || (side1 + side3 > side2) || (side2 + side3 > side1)) { 
		printf("These could be the sides of a triangle.\n\n");
	}
	else {
		printf("These could not be the sides of a triangle...\n");
	}
	return 0;

}


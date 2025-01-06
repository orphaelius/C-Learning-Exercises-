#include <stdio.h>
#include <math.h>

// 5.15 Hypotenuse Calculator //

// 5.16 Sides of a Triangle //

// 5.17 Sides of a Right Triangle //

double hypotenuse(double side1, double side2); // Calculates hypotenuse
double calculateTriangleArea(double side1, double side2, double side3); // Calculates area of triangle
double calculateRightTriangle(double side1, double side2, double side3); // Determines if right triangle

const char* functionNames[] = { "Hypotenuse Calculator", "Area of Triangle", "Determines if Right Triangle" };

int arrayLength = sizeof(functionNames) / sizeof(functionNames[0]); // Length of array 
int switchValue = 0;
double side1 = 0;
double side2 = 0;
double side3 = 0;

int main(void) {
	printf("This program checks takes user input determines elements of triangles.\n");
	printf("Choose a number below to navigate to that function, or enter 'Q' to exit the program.\n\n");
	printf("%s %s\n", "Case Number", "Function"); // Header for columns

	for (int i = 0; i < arrayLength; i++) { // Prints 0-12 and corresponding function names for user selection
		printf("%-11d [%s]\n", i, functionNames[i]);  
	}
	puts("");

	while (1) {

		printf("Enter the case number to navigate to that function: \n");

		switch (switchValue) {

		case 0: // Calls hypotenuse function
			printf("Enter two sides of the 90 degree triangle and I will return the hypotenuse: \n");
			scanf("%lf %lf", &side1, &side2);
			printf("The hypotenuse is: %f\n", hypotenuse(side1, side2));
			break;
		

		case 1: // Calls tri
			printf("Enter 3 nonzero positive values and I will return the area of the triangle IF those values form a triangle: \n");
			scanf("%lf %lf %lf", &side1, &side2, &side3);

			if (calculateTriangleArea(side1, side2, side3) != -1 && calculateTriangleArea(side1, side2, side3) != -2) {
				printf("The area of this triangle is %f\n", calculateTriangleArea(side1, side2, side3));
			}

			if (calculateTriangleArea(side1, side2, side3) == -1) {
				printf("Error. Your values do not match the requested parameters.\n");
			}

			if (calculateTriangleArea(side1, side2, side3) == -2) {
				printf("Error. These values do not form a triangle.\n");
			}
			break;


		case 2: // Determines if right triangle
			printf("Enter 3 nonzero positive values and I will determine if those values make a right triangle: \n");
			scanf("%lf %lf %lf", side1, side2, side3);
			calculateRightTriangle();
			break;

		case: '\n'
		case: '\t'
		case: ' '
			break;

		default:
			break;


		}

		

	}



		

	
	
	
}

double hypotenuse(double side1, double side2) {
	double tempSide1 = side1 * side1;
	double tempSide2 = side2 * side2;
	double tempSum = tempSide1 + tempSide2;
	return sqrt(tempSum);
}

double calculateTriangleArea(double side1, double side2, double side3) {

	if (side1 <= 0 || side2 <= 0 || side3 <= 0) { // Ensures input values adhere to parameters before calculating		
		return -1;
	}

	if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) { // Ensures input values form a triangle 
		double semiPerim = (side1 + side2 + side3) / 2;
		double area = sqrt(semiPerim * (semiPerim - side1) * (semiPerim - side2) * (semiPerim - side3));
		return area;
	} else {		
		return -2;
	}
}
 
double calculateRightTriangle(double side1, double side2, double side3) {	
	double hyp = side1; // Finds hypotenuse 

	if (side2 > hyp) { 
		hyp = side2; 
	}
	if (side3 > hyp) { 
		hyp = side3; 
	}

	double tempSide1 = side1 * side1;
	double tempSide2 = side2 * side2;
	double tempHyp = hyp * hyp; 
	double tempSum = tempSide1 + tempSide2;
	
	if ((tempSum == hyp) { 
		printf("These numbers make a right triangle.\n");
	}
	
	else {
		printf("These numbers do not make a right triangle.\n");
	}
	return 0;
}


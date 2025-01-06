#include <stdio.h>
#include <math.h>

// Roots of a Quadratic Equation //

/* A quadratic equation is any equation of the form 
ax^2 + bx + c = 0 where a, b, and c are the coefficients
of x. The roots of a quadratic equation can be calculated
by the formula x = (-b+-sqrt(b^2 - 4ac))/2a. If the 
expression, b^2 - 4ac, which is also called the discriminant,
is positive then the equation has real roots. If the 
discriminant is negative, the equation has imaginary (or 
complex) roots. Write a function that accepts the coefficients
of an equation as parameters, checks if te roots are real, and 
calculates the roots of the equation. Write a program to test
this function. */

float quadraticRoots(float coeA, float coeB, float coeC); // Function prototype
float coeA, coeB, coeC; // Variables for user input

int main(void) { // Main function

	printf("Enter 3 coeffecients:\n"); 
	scanf("%f %f %f", &coeA, &coeB, &coeC); // Takes input for 3 coefficients 

	quadraticRoots(coeA, coeB, coeC); 
}

float quadraticRoots(float coeA, float coeB, float coeC) { // Quadratic equation function
	float discriminant = (coeB * coeB) - (4 * coeA * coeC); // Calculates discriminant

	if (discriminant < 0) { // Checks if discriminant is imaginary
		printf("The roots are imaginary!\n");
		return 0;
	}
	// Separates roots
	float root1 = (- coeB + sqrt(discriminant)) / (2 * coeA); 
	float root2 = (-coeB - sqrt(discriminant)) / (2 * coeA);

	printf("The roots of this quadratic equation are: %f or %f\n", root1, root2);   
	return 0;
}



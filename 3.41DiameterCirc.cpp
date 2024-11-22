#include <stdio.h>

// Diameter, Circumference, and Area of a Circle //

/*
* write a program that reads the radius of a circle (as a double value) and computes and prints the diameter, the circumference, and the area.
* use the value 3.14159 for pi. 
*/

// Pseudocode //

/*
* initialize function
* 
* initialize variables
* pi = 3.14159 double
* diameter = 0 double
* circumference = 0 double
* radius = 0 double
* area = 0 double
* 
* print/scan prompt message and store value of radius into radius
* 
* diameter = radius x 2 (d=2r)
* circumference = 2 x pi x radius (2*pi*r)
* area = pi x radius squared (pi * (radius * radius))
* 
* print diameter, circumference, and area
*/

int main(void) {
	double pi = 3.14159;	
	double radius = 0;

	printf("Enter the radius of your circle and I will calculate the diameter, the circumference, and the area: \n");
	scanf("%lf", &radius);

	if (radius > 0) {
		double diameter = radius * 2;
		double circumference = 2 * pi * radius;
		double area = pi * (radius * radius);

		printf("The diameter is: %lf\n", diameter);
		printf("The circumference is: %lf\n", circumference);
		printf("The area is: %lf\n", area);

	}

}
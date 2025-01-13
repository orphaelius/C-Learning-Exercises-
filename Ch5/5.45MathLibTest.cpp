#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Testing Math Library Functions //

double squareRoot(double i); // finds square root 
double cubeRoot(double i); // finds cube root
double powersOfE(double i); // finds power of e  
double logBaseE(double i); // natural logarithm of x
double logBaseTen(double i); // finds log base 10 x
int absolute(int i); // finds absolute value of x 
double ceilR(double i); // rounds x to the smallest integer not less than x
double floorR(double x); // rounds x to the largest integer not greater than x
int power(int x, int y); // x raised to the power y  
double remainderOf(double x, double y); // fmod, remainder of x/y as floating point
double sineScratch(double x);
double cosineScratch(double x);
double tangentScratch(double x);



int main(void) {
	srand(time(NULL)); // Used to randomly generate values
	double randomDecimal = (double)rand() / RAND_MAX; // Randomly generates decimal value
	int randomInt = rand() % 10; // Generates a random integer between 0 and 9

	printf("All functions in this program use recursion to sift through a series of numbers.\n\n");
	printf("Square Root:\n");
	squareRoot(16);
	puts("");

	printf("Cube Root:\n");
	cubeRoot(16);
	puts("");

	printf("Powers of e:\n");
	powersOfE(16);
	puts("");

	printf("Natural e:\n");
	logBaseE(20);
	puts("");

	printf("Log Base 10:\n");
	logBaseTen(1);
	puts("");

	printf("Absolute Value:\n");
	absolute(-20);
	puts("");
	
	printf("Ceiling:\n");
	ceilR(randomDecimal); 
	puts("");

	printf("Powers:\n"); 
	power(randomInt, 1);  
	puts(""); 

	printf("Remainder of (x) / (y) as floating point [fmod]:\n");
	remainderOf(15, randomDecimal); 
	puts("");

	printf("Sine:\n");
	sineScratch(3);   
	puts("");

	printf("Cosine:\n");
	sineScratch(3);
	puts("");

	printf("Tangent:\n");
	sineScratch(3);
	puts("");


}

double squareRoot(double i) {
	if (i < 1) { // Base case, ends recursion
		return 1;
	}

	else {
		printf("The square root of %.2f is %.2f\n", i, sqrt(i)); // Prints square root of (i)
		return squareRoot(i - 1); // Calls itself with (i - 1) until it reaches the base case
	}
}

double cubeRoot(double i) {
	if (i < 1) { // Base case, ends recursion 
		return 1;
	}

	else {
		printf("The cube root of %.2f is %.2f\n", i, cbrt(i)); // Prints square root of (i)  
		return cubeRoot(i - 1); // Calls itself with (i - 1) until it reaches the base case 
	}
}

double powersOfE(double i) {
	if (i < 1) { // Base case, ends recursion 
		return 1;
	}

	else {
		printf("e to the power of %.2f is %.2f\n", i, exp(i)); // Prints square root of (i)   
		return powersOfE(i - 1); // Calls itself with (i - 1) until it reaches the base case  
	}
}

double logBaseE(double i) {
	if (i == 1) { // Base case, ends recursion  
		return 0; 
	}

	else {
		printf("natural log of %.2f is %.2f\n", i, log(i)); // Prints square root of (i)   
		return logBaseE(i - 1); // Calls itself with (i - 1) until it reaches the base case    
	}
}

double logBaseTen(double i) {
	if (i > 100) {
		return 2;
	}

	else {
		printf("Log base 10 of %.2f is %.4f\n", i, log10(i));
		return logBaseTen(i + 1); 
	}

}

int absolute(int i) { 
	if (i > -1) {
		return 1;
	}
	else { 
		printf("The absolute value of %d is %d\n", i, abs(i));  
		return absolute(i + 1); 
	}
}

double ceilR(double i) {   
	
	if (i > 30) {  
		return i; 
	}
	else {
		printf("Ceiling of %.2f is %.2f\n", i, ceil(i)); 
		return ceilR(i + 1);  
	}  
}

int power(int x, int y) {
	int tempExponent = pow(x, y); 
	if (y > 10) {
		return pow(x, y);  
	}

	else {
		printf("%d to the power of %d is: %d\n", x, y, tempExponent);
		return power(x, y + 1);    
	}
}

double remainderOf(double x, double y) {
	
	if (x < 1) {
		return fmod(x, y); 
	}
	else {
		printf("%.2f divided by %.2f is: %.2f\n", x, y, fmod(x, y));
		return remainderOf(x - 1, y);  
	}
}

double sineScratch(double x) {
	if (x < 1) {
		return sin(x);
	}
	else {
		printf("sine %f is %f\n", x, sin(x));
		return sineScratch(x - 1); 
	}
}

double cosineScratch(double x) {
	if (x < 1) {
		return cos(x);
	}
	else {
		printf("cosine %f is %f\n", x, cos(x));
		return cosineScratch(x - 1);
	}
}

double tangentScratch(double x) { 
	if (x < 1) {
		return tan(x);
	}
	else {
		printf("tangent %f is %f\n", x, tan(x));
		return tangentScratch(x - 1);
	}
}





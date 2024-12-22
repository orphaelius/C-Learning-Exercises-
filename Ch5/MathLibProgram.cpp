#include <stdio.h>
#include <math.h>
#define LN10 2.302585092994046
#define PI 3.1459265358979

// Write a program that tests whether math library functions
// actually produce the indicated results

/* To Do
* sentinel value (-1? use in functions)
* condense case bodies into functions?
* 



*/

void userInput1(); // 
void userInput2();

double squareRoot(double x); // finds square root
double cubeRoot(double x); // finds cube root
double powersOfE(double x); // finds power of e 
double logBaseE(double x); // natural logarithm of x
double logBaseTen(double x); // finds log base 10 x  
double absolute(double x); // finds absolute value of x
double ceilR(double x); // rounds x to the smallest integer not less than x
double floorR(double x); // rounds x to the largest integer not greater than x
double power(double x, double y); // x raised to the power y
double remainderOf(double x, double y); // fmod, remainder of x/y as floating point
double sineScratch(double x);
double cosineScratch(double x);
double tangentScratch(double x);
double piFunction(double x);
long long factorialScratch(double x);


 

int main() {

	const char* libraryFunctionNames[] = { // Array of library functions
		"Square Root", "Cube Root", "Powers of nat e", "Natural Logarithm of x", "Log Base 10 x", 
		"Absolute Value", "Ceiling (rounds up to nearest whole number)", "Floor (rounds down to nearest whole number)",
		"Powers (first value to the power of the second value)", "Remainder (fmod, remainder of x/y as floating point value)", 
		"Sine", "Cos", "Tan" };

	// Variables
	int arrayLength = sizeof(libraryFunctionNames) / sizeof(libraryFunctionNames[0]); // Length of array
	int switchCaseValue = 0; // Variable for triggering switch cases
	double x = 1; // Initialized variable for taking values 
	double y = 1; // ^ ^
	double z = 1; // ^ ^	

	printf("This program checks takes user input and compares functions of the math.h library against test cases.\n");
	printf("Choose a number below to navigate to that function, or enter 'Q' to exit the program.\n\n");
	printf("%s %s\n", "Case Number", "Definition"); // Header for columns

	for (int i = 0; i < arrayLength; i++) { // Prints 0-12 and corresponding function names for user selection
		printf("%-11d [%s]\n", i, libraryFunctionNames[i]);
	}
	puts("");

	

	while (1) { 
		printf("Enter a case number: \n");
		
		scanf("%d", &switchCaseValue);		
		switch (switchCaseValue) {			

			// Square Root 
		case 0:
			printf("The square root of any number is a value that when multiplied by itself returns the given value.\n");
			userInput1();
			scanf("%lf", &x);
			//printf("The square root of %.2f is: %.2f\n", x, squareRoot(x));
			printf("sqrt(x) is %f, my function is %f\n", sqrt(x), squareRoot(x));
			break;

			// Cube Root
		case 1:
			printf("The cube root of any number is that number to the third power.\n");
			userInput1();
			scanf("%lf", &x);
			printf("cbrt(x) is %f, my function is %f\n", cbrt(x), cubeRoot(x)); 
			break;

			// Powers of e			
		case 2:
			printf("e is a mathematical constant whose value is approximately 2.71828.\n");
			printf("This case multiplies e by any input power.\n");
			userInput1();
			scanf("%lf", &x);
			printf("exp(x) is %f, my function is %f\n", exp(x), powersOfE(x)); 
			break;

			// Natural log of x 
		case 3:
			printf("This case finds the value of the natural base to an input number.\n");
			userInput1();
			scanf("%lf", &x);			
			printf("log(x) is %f, my function is %f\n", log(x), logBaseE(x));
			break;

			// Log base 10 of x 
		case 4:
			printf("This case returns the log base 10 of an input value.\n");
			userInput1();
			scanf("%lf", &x);			
			printf("log10(x) is %f, my function is %f\n", log10(x), logBaseTen(x));
			break;

			// Absolute value
		case 5:
			printf("This case returns the absolute value of an input number.\n");
			userInput1();
			scanf("%lf", &x);			
			printf("fabs(x) is %f, my function is %f\n", fabs(x), absolute(x)); 
			break;

			// Ceiling
		case 6:
			printf("Ceiling rounds a value up to the next nearest whole number.\n");
			userInput1();
			scanf("%lf", &x);			
			printf("ceil(x) is %f, my function is %f\n", ceil(x), ceilR(x));
			break;

			// Floor
		case 7:
			printf("Floor rounds a value down to the next nearest whole number.\n");
			userInput1();
			scanf("%lf", &x);			
			printf("floor(x) is %f, my function is %f\n", floor(x), floorR(x));
			break;

			// x raised to the power of y
		case 8:
			printf("Thise case raises a number, x, to the power of y.\n");
			userInput2();
			scanf("%lf %lf", &x, &y);			
			printf("pow(x) is %f, my function is %f\n", pow(x, y), power(x, y)); 
			break;

			// Fmod, remainder of x/y as floating point value
		case 9:
			userInput2();
			scanf("%lf %lf", &x, &y);			
			printf("fmod(x) is %f, my function is %f\n", fmod(x, y), remainderOf(x, y));
			break;

			// Sine
		case 10:
			printf("Enter an angle: \n");
			scanf("%lf", &x);			
			printf("sin(x) is %f, my function is %f\n", sin(x), sineScratch(x));
			break;

			// Cosine
		case 11:
			printf("Enter an angle: \n");
			scanf("%lf", &x);			
			printf("cos(x) is %f, my function is %f\n", cos(x), cosineScratch(x));
			break;

			// Tangent
		case 12:
			printf("Enter the angle: \n");
			scanf("%f", &x);			
			printf("tan(x) is %f, my function is %f\n", tan(x), tangentScratch(x));
			break;
		
		//case '\n':
		//case '\t':
		case ' ':
			break;

		default:
			break;
		}
		puts("");
	}
	return 0;
}

// Functions //

void userInput1() { // Requests one value
	printf("Enter a value: \n");
}

void userInput2() { // Requests two values
	printf("Enter two values: \n");
}

double squareRoot(double x) { // Case 0: Calculates square root	using Newton's method of approximation 
	if (x < 0) { // If input value is negative, return -1 
		printf("Impossible...\n");
		return 0;
	}

	if (x == 0) {
		return 0;
	}

	double guess = x / 2.0;
	double epsilon = 0.000001; // Precision point to compare difference of two values

	while (1) { 
		double next_guess = 0.5 * (guess + x / guess);

		if (absolute(next_guess - guess) < epsilon) { // Absolute value 
			break;
		}

		guess = next_guess;
	}
	return guess; 
}

double cubeRoot(double x) { // Case 1: Calculates cube root using Newton's method of approximation
	if (x < 0) {
		printf("Impossible...\n");
		return -1;
	}

	if (x == 0) {
		return 0;
	}

	double guess = x / 3.0;
	double epsilon = 0.000001; // Precision point to compare difference of two values
	double diff = 1;

	while (diff > epsilon || diff < -epsilon) {
		double next_guess = guess - (guess * guess * guess - x) / (3 * guess * guess);
		diff = next_guess - guess;
		guess = next_guess;		
	}
	return guess;
}

double powersOfE(double x) { // Case 2: Calculates e to the power of x  
	double product = 1.0;
	double e = 2.71828; // Initializes value of e
	for (int i = 1; i <= x; i++) { // loops through to square e
		product *= e;
	}
	return product;
}

double logBaseE(double x) { // Case 3: Calculates natural log of x
	double userInputValue = x;
	double seriesSum = 0;
	double term = (userInputValue - 1) / (userInputValue + 1);
	double termPower = term;

	if (userInputValue <= 0) {
		return 0;
	}

	for (int i = 1; i < 100; i += 2) {
		seriesSum += 2 * termPower / i;
		termPower *= term * term;
	}
	return seriesSum;
}

double logBaseTen(double x) { // Case 4: Calculates log base 10 of x
	return logBaseE(x) / LN10;
}

double absolute(double x) { // Case 5: Absolute value of x
	double absoluteValue = x;

	if (absoluteValue < 0) {
		absoluteValue *= -1;
	}
	else {
		printf("This value is already positive...\n");
		return absoluteValue;
	}
	return absoluteValue;
}

double ceilR(double x) { // Case 6: Ceiling Function
	double ceilingRound = x;

	if (ceilingRound >= 0) {
		int roundedUp = (int)ceilingRound + 1;
		return roundedUp;
	}
	else {
		int roundedUp = (int)ceilingRound;
		return roundedUp; 
	}
}

double floorR(double x) { // Case 7: Floor Function
	double floorRound = x;
	int roundedDown = 1;

	if (floorRound >= 0) {
		roundedDown = (int)floorRound; 
		return roundedDown; 
	}
	else {
		roundedDown = (int)floorRound - 1;
		return roundedDown; 
	}
}

double power(double x, double y) { // Case 8: x raised to the power y
	double power = 1;
	double inputVal1 = x;
	double inputVal2 = y;
	for (int i = 1; i <= y; i++) {
		power *= x;
	}
	return power;
}

double remainderOf(double x, double y) { //Case 9: Fmod, remainder of x/y as floating point
	double dividend = x;
	double divisor = y;
	double quotient = x / y;
	double floorQuotient = floorR(quotient);
	return x - (floorQuotient * y);
}

double sineScratch(double x) { // Case 10: Sine function
	x = piFunction(x);
	double sine = 0.0;
	double term = x;

	for (int i = 1; i <= 10; ++i) {
		sine += term;
		term *= -x * x / ((2 * i) * (2 * i + 1));
	}
	return sine;
}

double cosineScratch(double x) { // Case 11: Cosine function
	x = piFunction(x);
	double result = 1.0;
	double term = 1.0;

	for (int i = 1; i <= 10; ++i) {
		term *= (-x * x) / ((2 * i) * (2 * i - 1));
		result += term;
	}
	return result;
}

double tangentScratch(double x) { // Case 12: Tangent function
	double sinValue = sineScratch(x);
	double cosValue = cosineScratch(x);

	if (cosValue == 0) {
		printf("Cannot divide by zero...\n");
		return 0;
	}
	return sinValue / cosValue;
}

// Reduces instability of the Taylor series by reducing x to a smaller value. Sine
// function quickly became erratic after entering values greater than 5.
// range of [0, 2pi]

double piFunction(double x) {
	while (x > 2 * PI) {
		x -= 2 * PI;
	}
	while (x < 0) {
		x += 2 * PI;
	}
	return x;
}

long long factorialScratch(double x) {
	long long factorialValue = 1;
	for (int i = 1; i <= x; i++) {
		factorialValue *= i;
	}
	return factorialValue;
}

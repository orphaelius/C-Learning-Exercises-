#include <stdio.h>
#include <math.h>

// Calculating the Value of Pi //

/*print a table that shows the value of pi approximated by one
term of the series, by two terms, by three terms, and so on. */

/* pi = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 etc */

int main(void) {  
	
	double denominator = 1.0; // denominator to increment by 2	
	double tempPi = 0; 
	double pi = 0;
	double sign = 1; // used to switch between subtraction and addtion
	
	// prints header for columns
	printf("%10s %20s\n", "Denominator Value", "Current Pi Value");

	// main loop, loops through i times to find pi values
	for (int i = 0; i < 500; i++) {
		tempPi = 4 / denominator; // tempPi is 4 / current denominator value
		pi += sign * tempPi; // pi is pi plus or minus tempPi
		sign = -sign; // switches sign!! found this online, very cool..
		
		// prints denominator value and current pi value
		printf("%-21.0f %-5f\n", denominator, pi); 
		denominator += 2; // increments denominator value by 2
	}

	return 0;
}

#include <stdio.h>
#include <math.h>

// Converting Celsius to Fahrenheit //

/* 
* write a program that converts temperatures ranging between 30 degrees celsius and 50
* degrees celsius to the fahrenheit scale. the program should print a table displaying
* temperatures in the two scales side by side.
* 
* F = 9/5(C) + 32 //
*/

int main(void) {
	int celsius = 30; 
	double fahr = 0;
	
	printf("Celsius Temperature %15s Fahrenheit Conversion\n\n", "");

	for (celsius; celsius <= 50; celsius++) {  
		fahr = (celsius * (9.0 / 5.0) + 32);
		printf("%16s %d %32s %.1f\n", "", celsius, "", fahr);  
	}
}


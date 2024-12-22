#include <stdio.h>
#include <math.h>

// Factorials //

/* the factorial function isused frequently in probability problems. 
* the factorial of a positive integer n (written n!, pronounced "n factorial")
* is equal to the product of the positive integers from 1 to n. write a program 
* that evaluates the factorials of the integers from 1 to 5. print the results
* in tabular format. what difficulty might prevent you from calculating the 
* factorial of 20? */

int main(void) {
	int factorial = 0;
	
	printf("Number %15s Factorial Value\n", "");

	for (int counter = 1; counter <= 5; counter++) {
		factorial = tgamma(counter + 1);
		printf("%d %20s %d\n", counter, "", factorial);
	}

	printf("End 4.14...");

	// 20! would require using a different data type to calculate that value //
}

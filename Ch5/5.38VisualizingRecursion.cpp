#include <stdio.h>

// Visualizing Recursion //

unsigned long long int factorial(int number);

int main(void) {
	// Calculate factorial(i) and display result
	
	for (int i = 0; i <= 21; ++i) {		
		//printf("\n");
		printf("\n\tIs the same as factorial %d!, or: %llu\n", i, factorial(i));		
		
	}
	
}

unsigned long long int factorial(int number) {
	printf("%d ", number); 
	 
	if (number <= 1) {	
		
		return 1;
	}
	else {	
		//printf("%d ", number); 
		printf("* "); 
		unsigned long long int facto = number * factorial(number - 1);				
		return (facto);
	}
		
	
}
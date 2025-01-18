#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Fibonacci Implementation //


int fib(int target, int term1, int term2); // Fibonacci with tail recursion
int fib2(int n); // Fibonacci
int fib3(int term1, int term2);   
int target = 30; // Used to modify target calculation

int main(void) {
	printf("Fibonacci Recursion solution 1:\n");
	for (int i = 0; i <= 20; i++) {
		printf("%d\n", fib(i, 0, 1));  
	}

	printf("Fibonacci Recursion solution 2:\n");
	
	for (int j = target; j >= 0; j--) { // Reversed for fun  
		printf("%d\n", fib2(j));   
	}

	for (int j = target; j >= 0; j--) { // Reversed for fun  
		printf("%d\n", fib3(j));
	}
	
}

int fib(int target, int term1, int term2) { // Tail recursion-- uses less memory!
	if (target == 0) { // If target term reaches zero, return first term
		return term1; 
	}
	else {
		fib(target - 1, term2, term1 + term2);
	}
}

int fib2(int n) { 
	if (n <= 1) {
		return n;  
	}	
	 else {
		return fib2(n-1) + fib2(n-2);  
	} 
}

int fib3(int term1, int term2) { // Tail recursion-- uses less memory!
	if (target == 0) { // If target term reaches zero, return first term
		return term1;
	}
	else {
		fib3(term2, term1 + term2);
	}
}
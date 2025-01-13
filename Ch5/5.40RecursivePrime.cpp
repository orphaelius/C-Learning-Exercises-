#include <stdio.h>

// Recursive Prime // 

int isPrime(int num, int divisor); 
int num = 0;
int divisor = 2;

int main(void) { 
	printf("Enter any positive number greater than 1 and I will determine if that number is prime:\n");
	scanf("%d", &num);

	if (num < 2) {
		printf("That is not a valid parameter.\n");		
	}	
	
	else {
		isPrime(num, divisor);  
	} 
	
}

int isPrime(int num, int divisor) {  
	
	if (divisor == num) {
		printf("The number %d is prime", num);
		return num;
	}

	if (num % divisor == 0) {
		printf("The number %d is not prime", num);
		return num;  
	}

	return isPrime(num, divisor + 1);
	
}


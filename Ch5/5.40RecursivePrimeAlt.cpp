#include <stdio.h>

// Recursive Prime // 

int isPrime(int num, int i);
int num = 0;
int i = 0; 
  
int main(void) {
	printf("Enter any positive number greater than 1 and I will determine if that number is prime:\n");
	scanf("%d", &num);

	int ind = isPrime(num, num - 1);

	if (ind == 1) {
		printf("The number %d is prime", num);
	}
	if (ind == 0) {
		printf("The number %d not prime", num);
	}

}

int isPrime(int num, int i) { 

	if (i == 1) {		
		return 1;
	} 

	if (num % i == 0) { 		
		return 0;
	}

	return isPrime(num, i - 1);  
}


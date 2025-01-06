#include <stdio.h>

// Even or Odd //

int evenOrOdd(int num);

int num = 0;
int tempNum; 
int main(void) {	
	printf("This program takes whole number values as input and determines if they are even or odd.\n");
	while (1) {

		printf("Enter any whole number, or enter '-3' to end the program.\n");
		scanf("%d", &num);

		if (num == -3) {
			break;
		}

		if (evenOrOdd(num) == -1) {
			printf("%d is an odd number.\n", num);
			
		}

		else if (evenOrOdd(num) == -2) {
			printf("This is not within the parameters. Please enter a \n");
			
		}
		else {
			printf("%d is an even number.\n", num);
			
		} 
	}	
}

int evenOrOdd(int num) {
	tempNum = num;  

	if (tempNum <= 0) {
		return -2;
	}
	if ((tempNum % 2) == 0) {		
		return num;  
	} 
	if ((tempNum % 2) == 1) {
		return -1;
	}
}
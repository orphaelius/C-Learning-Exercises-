#include <stdio.h>
#include <math.h>

// Lowest Common Multiple //

/* The lowest common multiple of two integers is the smallest positive
integer that is a multiple of both numbers. Write a function lcm that
returns the lowest common multiple of two numbers. */

int lcm(int num1, int num2); // Function prototype
int num1 = 0; // Both for taking user input
int num2 = 0;

int main(void) { // Main function
	printf("Enter two numbers and I will find the least common multiple of each:\n");
	scanf("%d%d", &num1, &num2);

	printf("LCM of %d and %d is: %d", num1, num2, lcm(num1, num2)); // Calls function/displays solution
}


int lcm(int num1, int num2) { // LCM function
	
	int multiple = 0; // Solution for lcm
	int max = 0; // Finds min/max of input numbers
	int min = 0;

	if (num1 >= num2){ // If num1 is greatest, assign to max, etc
		max = num1;
		min = num2;

		if (num1 % num2 == 0) { // Checks if num2 is a multiple of num1
			return num1; // Returns num1 if so as lcm
		}

	} else { // Else max is num2
			max = num2; 
			min = num1; 
			if (num2 % num1 == 0) { 
				return num2; 
			}  
	}

	for (int i = 1; i <= max; i++) { // Otherwise loop to find lcm 
		if ((max * i) % min == 0) {
			multiple = max * i;
			break;
		}
	}

	return multiple; // Return lcm
			
	



}
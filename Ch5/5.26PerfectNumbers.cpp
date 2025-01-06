#include <stdio.h>

// Perfect Numbers //

/* an integer number is said to be a perfect number
if its factors, including 1 (but not the number itself),
sum to the number. for example, 6 is a perfect number because
6 = 1 + 2 + 3; write a function isPerfect that determines
whether parameter number is a perfect number. use this function
in a program that determines and prints all te perfect numbers
between 1 and 1000. print the factors of each perfect number to
confirm that the number is indeed perfect. challenge the
power of your computer by testing numbers much larger than
1000. */

int isPerfect(int num); // Function prototype

int main(void) { // Main function

	for (int num = 1; num <= 1000; num++) { // Loops through numbers up to and including 1000
		if (isPerfect(num)) { // Calls isPerfect function
			printf("%d is a perfect number.\n", num);
		}
	}
}

int isPerfect(int num) { // isPerfect Function
	int sum = 0; // Sets sum to 0 
	for (int i = 1; i <= num / 2; i++) { // Loops through num in main function
		if (num % i == 0) { // If that num is divisible by counter, adds to sum
			sum += i;
		}
	}
	return sum == num; // Returns to main function if sum adds up to current num
}


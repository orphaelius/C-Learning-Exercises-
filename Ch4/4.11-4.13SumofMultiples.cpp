#include <stdio.h>
#include <math.h>

// 4.11 Calculating the Sum of Multiples // 
 
			   // && //
			   
       // 4.12 Prime Numbers //

               // && //

  // 4.13 Natural Numbers Arithmetic //


int main(void) {

	// 4.11 //
	for (int counter = 1; counter <= 100; counter++) {
		if (counter % 7 == 0) {
			printf("%d is a multiple of 7.\n", counter);
		}
	}
	printf("4.11 has ended...\n\n");	

	// 4.12 //
	int num = 2; // prime number begins at the number 2
	int i = 2; 
	int prime = 0; // prime variable, used for true/false

	// main loop. increments counter (num) from 2 (prime beginning) to 100
	for (num = 2; num <= 100; num++) {

		// resets prime
		prime = 1;

		// nested for loop, counter starts at 2, only need to check numbers between 2 and i*i == current num
		for (i = 2; i * i <= num; i++) {

			// if counter (num) divided by i has a remainder of zero, prime is false, break loop 
			if (num % i == 0) { 
				prime = 0; 
				break;
			}	
			//increment i			
		}

		if (prime == 1) { // if prime is 1, current counter (num) is prime
			printf("The number %d is prime.\n", num);
		}			
	}
	printf("4.12 has ended.\n\n");

	// 4.13 //

	/* 4.13 write a program that prints the sum, the sum of the
	* squares, and the sum of the cubes of all natural numbers
	* from 1 to a number input by the user
	*/

	int input_num = 0;
	int sum = 0;
	int squares = 0;
	int squares_sum = 0;
	int cubes = 0;
	int cubes_sum = 0;

	printf("Enter any number below 20 and I will print the sum, the sum of squares, and the sum of cubes of all numbers from 1 until that number: \n");
	scanf("%d", &input_num);

	for (int n = 1; n <= input_num; n++) {
		sum += n;	
		squares = pow(n, 2);
		squares_sum += squares;
		cubes = pow(n, 3);
		cubes_sum += cubes; 
	}
	printf("the sum of the numbers 1 through %d is: %d\n", input_num, sum); 
	printf("the sum of the squares of the numbers 1 through %d is: %d\n", input_num, squares_sum);
	printf("the sum of the cubes of the numbers 1 through %d is: %d\n", input_num, cubes_sum); 
	printf("4.13 has ended...\n");
}





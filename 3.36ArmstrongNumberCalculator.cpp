#include <stdio.h> 

// Armstrong Numbers //

/*
* armstrong numbers are numbers that are equal to the sum of their digits raised to power of the number of digits in them. the number 153,
* for example, equals 1^3 + 5^3 + 3^3. thus, it is an armstrong number. write a program to display all three-digit armstrong numbers.
*
* pseudocode
* oh boy
*
* initialize variables
* [starting_num] - initialize starting number. 
* [last_digit] - extract last digit, used to multiply it by power of 3
* [sum] - stores consecutive values, final sum of each digit to the power of 3
* [counter_num] - used to move to the next number in a numerically ordered series. starting_sum will be  used to reference at the end of each
* loop, counter_sum will be used each consecutive iteration to perform the next sum calculation
*
* print initial message to screen 
*
* first while loop
* while initial number is less than final number in series
* initialize counter number
* 
*	second while loop to run through each number* 
*	last_digit = num % 10 // extract the last digit for calculations
*	sum = last_digit * last_digit * last_digit
*	counter num = counter num / 10; // turns last digit into decimal value, thus discarding it (num is an integer value)
*	
* if sum equals the starting number in the loop, which is incremented by 1 each iteration, print "armstrong number"* 
*
* end program
*/

int main(void) {
	int starting_num = 100; // initialize starting number	
	int sum; // variable to store sum of digits
	int last_digit;  // variable, extracts last digit and will be multiplying by itself 3x	
	
	printf("This program loops from the number 100 through the number 999 and determines which numbers are Armstrong Numbers.\n\n");

	while (starting_num <= 999) {
		int counter_num = starting_num; // separate number for making new calcs in each subsequent iteration
		sum = 0; // resets sum to 0

		while (counter_num != 0) { // all 3-digit numbers  
			 
			last_digit = counter_num % 10; // extract last digit off number to make calculations 			  
			sum += last_digit * last_digit * last_digit; // store last dig pow plus next last digit pow etc
			counter_num /= 10; // remove last digit from the number, turn into decimal thus discarding it 	
			//starting_num++;
		}

		if (sum == starting_num) { 
			printf("%d is an Armstrong Number.\n", starting_num);  
		}
		starting_num++; 
	}

	return 0;
}
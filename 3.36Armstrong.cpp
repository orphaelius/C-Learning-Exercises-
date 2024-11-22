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
* [num] - input value
* [last digit] - extract last digit, used to multiply it by power of 3
* [sum] - stores values, final sum of each digit to the power of 3
* [base] - how to make this ^3?
*
* print initial prompt message
* store [num]
*
* while loop
* while [num]
* last_digit = num % 10 // extract the last digit for calculations
* base = last_digit * last_digit * last_digit
* num = num / 10; // turns last digit into decimal value, thus discarding it (num is an integer value)
* sum = last_digit * base
*
* !! needs if statement to determine if sum is the same as the num, otherwise discard !!
*
* print final sum
*
* end program
*/

int main(void) {
	int starting_num = 0; // initialize starting number
	int last_dig_pow = 0; // starts base to use as power
	int sum = 0; // variable to store sum of digits
	int last_digit = 0;  // variable, extracts last digit and will be multiplying by itself 3x	

	printf("Enter any 3 digits and I will return the sum of each individual digit to the power of 3: \n");
	scanf("%d", &starting_num);
	int num = starting_num;

	while (starting_num != 0) { // end when all digits are divided out
		
		//if (sum >= 1000) { !! added element to break if sum goes beyond 3 digits
		//	break;
		//}

		last_digit = starting_num % 10; // extract last digit off number to make calculations 			  
		sum += last_digit * last_digit * last_digit; // store last dig pow plus next last digit pow etc
		starting_num /= 10; // remove last digit from the number, turn into decimal thus discarding it 	
		//starting_num++; !! added for incrementation
	}

	if (sum == num) { 
		printf("%d is an Armstrong Number.\n", num);
	}
	else {
		printf("%d is not an Armstrong Number.\n", num);  
	}

	return 0;

}
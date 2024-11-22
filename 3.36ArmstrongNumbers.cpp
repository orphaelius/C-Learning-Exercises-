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
	int num = 100; // initialize starting number
	int last_digit = 1; // variable, extracts last digit and will be multiplying by itself 3x
	int sum = 0; // variable to store sum of digits
	

	//printf("Enter any 3 digits and I will return the sum of each individual digit to the power of 3: \n");
	//scanf("%d", &num);

	while (num <= 999) { // all 3-digit numbers !! modify to be between 100 and 1000, exclusive !!
		int last_dig_pow = 0; // starts base to use as power
		//int armstrong;

		if (sum >= 2187) {
			break;
		}		
		
		last_digit = num % 10; // extract last digit off number to make calculations
		num = num / 10; // remove last digit from the number, turn into decimal thus discarding it 
		last_dig_pow = last_digit * last_digit * last_digit; //	current last dig pow is the last digit^3	  
		sum += last_dig_pow; // store last dig pow plus next last digit pow etc
		 
		if (num == sum) {
			printf("%d is an Armstrong Number.\n", sum);
		}		
		num++; 
		printf("%d\n", last_dig_pow);  
		
	}	
	
	
	else {
		printf("%d is not an Armstrong Number\n", sum);
	}
	printf("The sum is: %d", sum);
	
	return 0;


}
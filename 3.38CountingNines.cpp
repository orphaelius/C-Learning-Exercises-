#include <stdio.h>

// Counting Nines //

/*
* write a program that reads an integer of 5 digits or fewer and determines and prints how many digits in the integer are 9s.
* 
* a) initialize function
* 
* b) initialize variables
* num for input
* temp_num for cycling through
* last digit for removing digits
* 
* print prompt for user input
* scan for input, store in num
* 
* c) loops
* if num > 99999
* break;
* 
*
* return
*/

int main(void) {
	int num = 0; 
	int last_digit = 0;
	int sum = 0;
	
	printf("Enter any 5-digit number and I will determine how many 9s are in that number: \n"); // prompt
	scanf("%d", &num); // store input into num 
	
			 	

	while (num != 0) { // inner loop, if current temp num is not 0, do the following:

		if (num > 99999) {
			break;
		}

		last_digit = num % 10; // extract last digit	

		if (last_digit == 9) { // if last digit is a 9, tell me
			sum += 1;								
		}

		num /= 10; // remove last digit 		
		
	}		

	printf("there are %d 9s in this number.", sum); 		

}










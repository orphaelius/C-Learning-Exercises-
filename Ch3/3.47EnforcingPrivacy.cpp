#include <stdio.h>

// Encrypting and Decrypting //

/*
* company wants all data transmitted as 4 digit integers
* 
* application 1:
* 1) reads a 4 digit integer input 
* 2) encrypt as follows:
*	a) replace each digit with the result of adding 7 to the digit, getting the remainder after dividing the new value by 10.
*	b) swap the first digit with the third
*	c) swap the second digit with the fourth
*	d) print the encrypted integer
* 
* application 2:
* 1) inputs an encrypted four-digit integer and decrypts it by reversing the encryption scheme to form the original number
*/

int main(void) {

	int input_num1 = 0;
	int input_num2 = 0;
	int counter = 0;
	int counter2 = 0;
		
	printf("Enter a 4 digit number to encrypt: \n");
	scanf("%d", &input_num1);	

	while (counter < 1) {

		if (input_num1 > 9999 || input_num1 < 999) {
			break;
		}

		// separates each digit 
		int dig_four = input_num1 % 10;
		int dig_three = (input_num1 % 100) / 10;
		int dig_two = (input_num1 % 1000) / 100;
		int dig_one = (input_num1 / 1000);

		// makes calculations
		int temp_dig_four = (dig_four + 7) % 10;
		int temp_dig_three = (dig_three + 7) % 10;
		int temp_dig_two = (dig_two + 7) % 10;
		int temp_dig_one = (dig_one + 7) % 10;

		// swaps digits
		int encr_dig_one = temp_dig_three;
		int encr_dig_two = temp_dig_four;
		int encr_dig_three = temp_dig_one;
		int encr_dig_four = temp_dig_two; 

		// prints encrypted input
		printf("The encrypted 4 digit number is: %d%d%d%d\n\n", encr_dig_one, encr_dig_two, encr_dig_three, encr_dig_four);
				 
		counter++;
	}

	printf("Input your encrypted 4 digit number and I will decrypt it: \n");
	scanf("%d", &input_num2);

	while (counter2 < 1) {

		if (input_num2 > 9999 || input_num2 < 999) {
			break;
		}

		// separates each digit 
		int encr_dig_four2 = input_num2 % 10;
		int encr_dig_three2 = (input_num2 % 100) / 10; 
		int encr_dig_two2 = (input_num2 % 1000) / 100; 
		int encr_dig_one2 = (input_num2 / 1000); 

		// makes calculations
		int temp_dig_four2 = (encr_dig_four2 - 7 + 10) % 10; 
		int temp_dig_three2 = (encr_dig_three2 - 7 + 10) % 10;  
		int temp_dig_two2 = (encr_dig_two2 - 7 + 10) % 10;  
		int temp_dig_one2 = (encr_dig_one2 - 7 + 10) % 10;  
		 
		// swaps digits
		int decr_dig_one = temp_dig_three2; 
		int decr_dig_two = temp_dig_four2; 
		int decr_dig_three = temp_dig_one2; 
		int decr_dig_four = temp_dig_two2; 

		// prints decrypted input
		printf("The decrypted digit is: %d%d%d%d\n\n", decr_dig_one, decr_dig_two, decr_dig_three, decr_dig_four);  

		counter2++;
	}








	return 0;
}

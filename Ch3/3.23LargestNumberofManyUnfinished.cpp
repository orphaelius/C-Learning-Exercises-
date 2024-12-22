#include <stdio.h>

// write a pseudocode program then a program that uses scanf to input a series of 10 non-negative numbers and determines
// and prints the two largest of the series of numbers. 

// pseudocode:
/*
initialize main function

initialize variables for program:
num1
largest
second_largest
counter

request initial input non-negative integers, add sentinel value message, -1
printf message

while statement to run through each number input
scan for input, if -1 escape program
add counter, increment to 10
calculate which number is largest so far, print each iteration of largest number
use something like largest vs new_largest to check each updated largest number

execute program when 10 is reached

print final results 

*/
int main(void) {
	int num1 = 0;
	int largest = 0;
	int second_largest = 0;
	int counter = 0;
	
	printf("Enter ten different numbers and I will determine the 2 with the largest values: (enter -1 to escape): \n\n");

	while (counter < 10) {		
		scanf("%d", &num1);				
		if (num1 == -1) {
			break;
		}		

		if (num1 > largest) {	
			second_largest = largest;
			largest = num1;  
			printf("The  largest number in the series is: %d.\nThe second largest is: %d\n\n", largest, second_largest);								
		}	
		else {
			second_largest = largest; 
			
			printf("The  largest number in the series is: %d.\nThe second largest is: %d\n\n", largest, second_largest);
		}
						
		counter++; 
		
	} 
	
} // stuck on creating logic that ensures the second largest and largest don't end up repeating

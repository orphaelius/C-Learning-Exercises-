#include <stdio.h>
#include <math.h>

// Sum and Average of Integers //

/*
* write a program to sum a sequence of integers and calculate their average. assume that the first integer read with scanf specifies the number 
* of values to be entered. your program should read only one value each time scanf is executed. a typical input sequence might be:
*	7 687 234 315 489 536 456 367
* where the '7' indicates that the subsequent 7 values are to be summed.
*/

/*
* initialize function
* intialize variables
* 
* prompt
* store value
* 
* while count <= input num
* do
* 
* sum += input_num
* 
* average = sum / input_num
* 
* print output

*/

int main(void) {
	int start_num = 0;
	int input_numbers = 0;
	int sum = 0;
	int average = 0;

	printf("Enter a single digit positive number to begin the program: \n");
	scanf("%d", &start_num);  

	for (int counter = 1; counter <= start_num; counter++) {
		printf("Excellent... feed me more: \n");
		scanf("%d", &input_numbers);
		sum += input_numbers;
	}

	puts("");
	average = sum / start_num;
	printf("The average of these numbers is: %d\n", average);

}
#include <stdio.h>
#include <math.h>

// intro exercises for Ch. 4 //

/*
* a) write a program to sum the odd integers between 1 and 99 using a for statement. use the integer variables 'sum' and 'count'
* 
* b) print the value 333.546372 in a field width of 15 characters with precisions of 1, 2, 3, 4, and 5. left-align the output.
* what are the five values that print?
* 
* c) calculate the value of 2.5 raised to the power of 3 using the 'pow' function. print the result with a precision of 2 in a field width of 
* 10 positions.
* 
* d) print the integers from 1 to 20 using a while loop and the counter variable 'x.' print only 5 integers per line (hint, % 5). when this
* is 0, print a newline character, otherwise pint a tab character
* 
* 4.7: print sequential values

*/


int main(void) {

	// a) //
	int sum = 0;	
	for (int count = 1; count <= 99; count++) {

		if (count % 2 == 1) {
			sum += count;
		}
	}
	printf("Sum of all odd integers between 1 and 99 is: %d\n\n", sum);

	// b) //
	double value = 333.546372;
	printf("%15s %.1f\n","", value); 
	printf("%15s %.2f\n", "", value);
	printf("%15s %.3f\n", "", value);
	printf("%15s %.5f\n", "", value);
	printf("%15s %.5f\n\n", "", value); 

	// c) //
	double val2 = 2.5;
	double power = pow(2.5, 3);
	printf("%10.2f\n\n", power);


	// d)  //
	int x = 1;
	while (x <= 20) {
		printf("%d", x);

		if (x % 5 == 0) {
			puts("");
		}
		else {
			printf("\t");
		}		
		x++;
	}

	puts(" ");

	// 4.7 //

	for (int count = 1; count <= 13; count += 2) {
		printf("%d ", count);
	}
	puts(" "); 

	for (int count = 2; count <= 17; count += 3) {
		printf("%d ", count);
	}
	puts(" "); 

	for (int count = 30; count >= -30; count -= 10) {
		printf("%d ", count);
	}
	puts(" "); 

	for (int count = 15; count <= 55; count += 8) {
		printf("%d ", count);
	}
	puts(" "); 








}

#include <stdio.h>

// Write single C statements to perform the following:

/*
a) input integer variable x with scanf. Use the conversion specification %d
b) input integer variable y with scanf. use the converstion specification %d

c) set integer variable i to 1
d) set integer variable power to 1

e) multiply integer variable power by x and assign the result to power

f) increment variable i by 1

g) test i to see if it's less than or equal to y in the condition of a while statement

h) output integer variable power with printf
*/

// 3.27
// modify the program to validate its user inputs. for each input, if the value is other than 1 or 2, keep looping until the user enters a correct value


int main(void) {

	int x = 0;
	int counter = 0;
	int power = 1;
	
	//int y = 0;
		
	printf("Please enter your code (1 or 2) or enter -1 to exit: \n");
	
	//int i = 1;
	//int power = x;	
	
	while (counter < 10) { 
		
		scanf("%d", &x);

		 

		if (x == -1) {
			break;
		}

		if (x > 2) {
			printf("That is not a valid code. Please enter your code: \n");
		}

		if (x == 1) {
			printf("You entered %d. \n", x);
			break;
		}
		if (x == 2) {
			printf("You entered %d.\n", x);
			break;
		}
		counter++;
		
	}
	
}
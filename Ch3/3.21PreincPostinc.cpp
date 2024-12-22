#include <stdio.h>

// write a program that demonstrates the difference between preincrementing and postincrementing using the operator ++

int main(void) {

	// initialize pre and post variables
	int pre = 0;
	int post = 0;
	
	printf("Preincrement value starts at 0. Preincrementing adds value before being used in the expression.\n");
	printf("Postincrement value starts at 0. Postincrementing uses initial value before incrementing.\n");

	while (pre < 5) {
		printf("The current value for pre is: %d\n", pre);
		int num1 = ++pre; 
		printf("The updated value is: %d\n", num1); 
	}	

	while (post < 5) {
		printf("The current value for post is: %d\n", post);
		int num2 = post++;
		printf("The updated value is: %d\n", num2);  
	}
	
}

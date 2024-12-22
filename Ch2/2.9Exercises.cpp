#include <stdio.h>

int main(void) {

	// a) print the message "have a nice day."
	printf("Have a nice day.\n");

	// assign the sum of variables b and c to variable a
	int b = 33;
	int c = 29;
	int a = b + c;

	if (a > b) {
		c = a % b;
		printf("%d\n", c);
	}

	// input three integer values from the keyboard, and place them in int variables p, q, ad r
	int p = 0;
	int q = 0;
	int r = 0;

	// added additional code to prompt user and check correctness
	printf("Please enter three integers: ");
	scanf("%d %d %d", &p, &q, &r);

	int total = p + q + r;
	printf("The sum of your variables is: %d\n", total);

	// end program

}


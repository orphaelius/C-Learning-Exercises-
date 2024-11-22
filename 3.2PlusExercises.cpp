#include <stdio.h>

// write four different c statements that each add 1 to integer variable x

int main(void) {
	int x = 0; // for 3.2, print four statements that each add 1 to integer x
	int y = 10; // for 3.3, a) and b)
	int count = 32; // for 3.3 c)
	int divisor = 32;
	int num1 = 3;
	

	// 3.2
	printf("%d\n", x);
	printf("%d\n", x += 1);
	printf("%d\n", x + 1);
	printf("%d\n", ++x);
	printf("%d\n", x++);

	// 3.3 a) b)
	printf("%d\n", y *= 2);
	printf("%d\n", y = y * 2);

	// 3.3 c)
	if (count > 10) {
		printf("Count is greater than 10.\n");
	}

	// 3.3 d)
	// calculate remainder after quotient is divided by divisor and assign the result to quotient. write two different ways.
	// quotient / divisor = remainder
	// assign result to quotient
	int quotient = num1 / divisor;

}
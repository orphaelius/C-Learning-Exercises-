#include <stdio.h>
#include <stdlib.h> 

// Modified Recursive Sum //'

int recursiveSum(int a, int b);

int main(void) {
	printf("%s", "Enter two positive integers:\n");
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);

	printf("The result is %d\n", recursiveSum(a, b));
}

int recursiveSum(int a, int b) { // Recursively sums a
	b = abs(b);
	printf("b is %d\n", b);

	if (1 == b) { // Until b is 1
		return a;
	}

	else {
		return a + recursiveSum(a, b - 1);
		printf("b is %d\n", b);
	}

}
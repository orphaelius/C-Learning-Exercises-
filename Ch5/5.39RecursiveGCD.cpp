#include <stdio.h>

// Recursive Greatest Common Divisor //

int gcd(int x, int y);
int x = 0;
int y = 0;

int main(void) {
	printf("Enter two variables, x and y, and I will return the GCD:\n");
	scanf("%d%d", &x, &y);

	if (x < 0 || y < 0) {
		printf("These are not valid parameters.\n");
	}
	else {
		printf("GCD is: %d\n", gcd(x, y)); 
	}
}

int gcd(int x, int y) {
	
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);  
	}		
}


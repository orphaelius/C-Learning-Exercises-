#include <stdio.h>

// Modified Diamond //

/* modify the previous program to read an odd number between
1 and 19 to specify the number of rows in the diamond, then
print the diamond of appropriate size. */\


int main(void) {
	int num = 0;

	printf("Enter an odd number between 1 and 19 and I will print a diamond of that many rows: \n");
	scanf("%d", &num);


	int rows = (num / 2) + 1;	

	// Top Half //
	for (int counter = 1; counter <= rows; counter++) {

		// Top Left Quadrant	
		for (int space = 1; space <= rows - counter; space++) {
			printf(" ");
		}

		for (int asterisk = 1; asterisk <= counter; asterisk++) {
			printf("*");
		}

		// Top Right Quadrant		
		for (int asterisk = 1; asterisk <= counter; asterisk++) {
			printf("*");
		}
		puts("");
	}

	// Bottom Half //
	for (int counter = 1; counter <= rows; counter++) {
		
		// Bottom Left Quadrant		
		for (int space = 1; space <= counter; space++) {
			printf(" ");
		}

		for (int asterisk = rows - 1; asterisk >= counter; asterisk--) {
			printf("*");
		}

		// Bottom Right Quadrant		
		for (int asterisk = rows - 1; asterisk >= counter; asterisk--) {
			printf("*");
		}
		puts("");
	}
}
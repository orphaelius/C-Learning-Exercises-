#include <stdio.h>

// Modify 3.32 so that it prints a hollow square.

/* 
line 1 = length of square
* line 2 = ast tab ast, etc until:
* last line = length of square
*/

int main(void) {
	int square_len = 0;
	int counter_one = 1;
	int counter_two = 1;
	int counter_three = 1;

	printf("Enter any integer greater than 1 and less than 20 and I will display a hollow box of that length: \n");
	scanf("%d", &square_len);

	if (square_len <= 1 || square_len >= 20) {
		printf("Nice try, Jeff!");
	}

	if (square_len > 1 && square_len < 20) {
		
		while (counter_one <= square_len) {
			printf("*");				
			counter_one++; 
		}
		
		printf("\n");		
		
		int modify_len = square_len - 2;
		while (counter_two <= modify_len) {
			// square_len = square_len - 1; +1 for triangle exercise?
			printf("*%*c*", modify_len, ' ');
			counter_two++;
			printf("\n");
		}

		while (counter_three <= square_len) {
			printf("*");
			counter_three++;
		}


	}

}
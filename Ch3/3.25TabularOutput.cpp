#include <stdio.h>

int main(void) {
	
	int n = 0;
	int counter = 0;
	int begin = 0;

	printf("%s", "Enter the number 1 to begin, -1 to abort: \n");
	scanf("%d", &begin);

	while (counter < 5) {		

		if (begin == -1) {
			break;
		}

		n = n + 7; 
		int n_three = n + 3; 
		int n_six = n + 6;
		int n_mult = n * 9;
		printf("%d\t %d\t %d\t %d\n", n, n_three, n_six, n_mult);
		

		
		counter++; 
		
		

	}
}

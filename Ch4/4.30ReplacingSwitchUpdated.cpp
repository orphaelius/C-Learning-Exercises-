#include <stdio.h>

// Replacing Switch with If... Else //

/* rewrite figure 4.5 by replacing the switch with a
nested if... else statement. be careful to deal with
the default case properly. next, rewrite this new version
by replacing the nested if... else statement with a series
of if statements. here, too, be careful to deal with the
default case properly. this exercise demonstrates that switch
is a convenience and that any switch statement can be written
with only snigle-selection statements.*/

int main(void) {

	// counts for each grade letter
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;


	puts("Enter the letter grades: ");
	puts("Enter the EOF character to end input.");

	// initializes grade variable
	int grade = 0;

	while ((grade = getchar()) != EOF) {

		if ((grade == 'A' || grade == 'a')) {
			++aCount;
		}

		if (((grade == 'B' || grade == 'b'))) {
			++bCount;
		}


		if ((grade == 'C' || grade == 'c')) {
			++cCount;
		}

		if ((grade == 'D' || grade == 'd')) {
			++dCount;
		}

		if ((grade == 'F' || grade == 'f')) {
			++fCount;
		}
		else {
			if ((grade == '\n' || grade == '\t' || grade == ' ')) {
				printf("Enter a new grade: ");
			}
		}
		

		


	}
	printf("there are %d a's, %d b's, %d c's, %d d's, and %d f's.", aCount, bCount, cCount, dCount, fCount);

}

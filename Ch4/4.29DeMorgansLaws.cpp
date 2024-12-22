#include <stdio.h>
#include <math.h>

// De Morgan's Laws //

/* we discussed the logical operators &&, ||, and !. de morgan's laws
help express logical expressions more conveniently. these laws state
that the expression !(conditional1 && conditional2) is logically 
equivalent to the expression (!condition1 || !condition2). also, the
expression !(condition1 || condition2) is logically equivalent to the
expression (!condition1 && !condition2). use de morgan's laws to write
equivalent expressions for each of the following, and then write a 
program to show that both the original expression and the new expression
in each case are equivalent:
	a) !(x < 5) && !(y >= 7)
	b) !(a == b) || !(g != 5)
	c) !((x <= 8) && (y > 4))
	d) !((i > 4) || (j <= 6)) */


// My solutions:
// a) (x >= 5) && (y < 7)
// b) (a != b) || (g == 5)
// c) ((x > 8) || (y <= 4))
// d) ((i <= 4) || (j > 6))


// have mercy on me for this code. my inspiration is brevity 
// given the nature of this assignment.
int main(void) {

	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;	

	int aCount2 = 0;
	int bCount2 = 0;
	int cCount2 = 0;
	int dCount2 = 0;	

	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;
	int g = 0;
	int i = 0;
	int j = 0;

	int x2 = 0;
	int y2 = 0;
	int a2 = 0;
	int b2 = 0;
	int g2 = 0;
	int i2 = 0;
	int j2 = 0;
	
	// loop, implements my solutions
	for (int counter = 0; counter < 10; counter++) {

		for (int counter2 = 0; counter2 < 10; counter2++) {
			if ((x >= 5) && (y < 7)) {
				aCount++;
			}
			if ((a != b) || (g == 5)) {
				bCount++;
			}
			if ((x > 8) || (y <= 4)) {
				cCount++;
			}
			if ((i <= 4) && (j > 6)) {
				dCount++;
			}
		}	

		x++;     
		y++;   
		a++;
		b++;
		g++;
		i++;
		j++;
	}

	// print results to compare with second loop
	printf("a) count is %d, b) count is %d, c) count is %d, d) count is %d\n\n", aCount, bCount, cCount, dCount);

	// loop, implements author's given problems
	for (int counter = 0; counter < 10; counter++) {

		for (int counter3 = 0; counter3 < 10; counter3++) {
			if (!(x2 < 5) && !(y2 >= 7)) {
				aCount2++;
			}

			if (!(a2 == b2) || !(g2 != 5)) {
				bCount2++;
			}

			if (!((x2 <= 8) && (y2 > 4))) {
				cCount2++;
			}

			if (!((i2 > 4) || (j2 <= 6))) {
				dCount2++;
			}
		}

		x2++;
		y2++;
		a2++;
		b2++;
		g2++;
		i2++;
		j2++;
	}

	// compares results
	printf("a) count is %d, b) count is %d, c) count is %d, d) cound is %d", aCount2, bCount2, cCount2, dCount2);	
}



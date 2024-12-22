#include <stdio.h>
#include <math.h>

// Pythagorean Triples //

/* a right triangle can have sides that are all integers.
the set of three integer values for a right triangle's sides
is a Pythagorean triple. these three sides must satisfy the
relationship that the sum of the sides' squares is equal to
the hypotenuse's square. find all Pythagorean triples for
side1, side2, and the hypotenuse, all no larger than 500.
use a triple-nested for loop that tries all possibilities.
this is an example of "brute force" computing. it's not
aesthetically pleasing to many people, but there are many
reasons why this technique is important. first, with
computing power increasing at such a phenomenal pace,
solutions that would have taken years or even centuries of
computer time to produce with the technology of just a few
years ago can now be produced in hours, minutes, secnods,
or even less. second, there are large numbers of interesting
problems for which there's no known algoritmic approach other
than sheer brute force. */

/* a^2 + b^2 = c^2 */

int main(void) {
	// variable for each side of a triangle
	int side1 = 1;
	int side2 = 1;
	int side3 = 5;

	// smallest possible value for hypotenuse
	int hypotenuse = 25;

	// main loop, iterates 22 times to stay below 500
	for (double i = 1; i < 22; i++) {

		// side1, squared, increments at each cycle
		side1 = pow(i, 2);
		side2 = pow(side2, 2);
		printf("%.0f %.0f %.0f\n", sqrt(side1), sqrt(side2), sqrt(hypotenuse));

		// checks if a^ +b^ = c^2 and prints if true
		if (side1 + side2 == hypotenuse) {
			printf("%.0f %.0f %.0f is a Pythagorean Triplet!\n", sqrt(side1), sqrt(side2), sqrt(hypotenuse));
		}

		// side 2, squared, increments at each cycle
		for (double j = 1; j < 22; j++) {
			side1 = pow(i, 2);
			side2 = pow(j, 2);
			hypotenuse = pow(side3, 2);
			printf("%.0f %.0f %.0f\n", sqrt(side1), sqrt(side2), sqrt(hypotenuse));

			// checks if a^ +b^ = c^2 and prints if true
			if (side1 + side2 == hypotenuse) {
				printf("%.0f %.0f %.0f is a Pythagorean Triplet!\n", sqrt(side1), sqrt(side2), sqrt(hypotenuse));
			}
			puts("");

			// hypotenuse, squared, increments at each cycle
			for (double k = 5; k < 28; k++) {
				side1 = pow(i, 2);
				side2 = pow(j, 2);
				hypotenuse = pow(k, 2);
				printf("%.0f %.0f %.0f\n", sqrt(side1), sqrt(side2), sqrt(hypotenuse));

				// checks if a^ +b^ = c^2 and prints if true
				if (side1 + side2 == hypotenuse) {
					printf("%.0f %.0f %.0f is a Pythagorean Triplet!\n", sqrt(side1), sqrt(side2), sqrt(hypotenuse));
				}

			}
		}
	}
}

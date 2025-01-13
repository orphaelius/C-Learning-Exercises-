#include <stdio.h>

// Towers of Hanoi //

/* I watched "A Complete Recursive Visualization" by Reducible on YouTube to prepare for this
problem (citation at bottom of program). */

int hanoiFunction(int n, int start, int end); // Prototypes
int printMessage(int start, int end);

int n = 0; // User input for initializing total disks
int start = 0; // For starting peg
int end = 0; // For ending peg

int main(void) { // Main function

	printf("Enter the amount of disks:\n");
	scanf("%d", &n);
	printf("Enter the starting peg [1, 2, or 3]:\n");
	scanf("%d", &start);
	printf("Enter the ending peg [1, 2, or 3]:\n");
	scanf("%d", &end);

	hanoiFunction(n, start, end); // Function call

}

int hanoiFunction(int n, int start, int end) { // Hanoi recursive function
	
	if (n == 1) { // If one disk is left or user enters only 1 disk, print message

		printMessage(start, end); 

	}

	else { // Runs recursion

		int other = 6 - (start + end); // Other is dynamically set to the difference of sums
		hanoiFunction(n - 1, start, other); // First call moves n - 1 disk from start peg to the other peg using the third as the temp peg
		printMessage(start, end); // Move nth disk directly from start peg to end peg. Print message.
		hanoiFunction(n - 1, other, end); // Second call moves n - 1 disk from other peg to end peg using the start peg as the temp peg

	}

	return 0;

}

int printMessage(int start, int end) { // Message function

	printf("move disk %d -> %d\n", start, end);
	return 0;
}



/* Reducible, A Complete Recursive Visualization, https://youtu.be/rf6uf3jNjbo?si=nn2FRYWZ2_QeQgBD, May 26, 2020 */
#include <stdio.h>
#include <math.h>

// Towers of Hanoi //

/* I watched "A Complete Recursive Visualization" by Reducible on YouTube to prepare for this
problem (citation at bottom of program). */

/* 
* 
* 1 disk is moved at a time
* goal is to move all disks from one peg to a second peg
* no larger disk may be placed above a smaller disk
* 
 peg 1- stack of (n amount) disks
 peg 2- for moving/restacking
 peg 3- temporary holding peg

 using recursion, moving n disks can be viewed as moving 
 only n-1 disks

 a) move n - 1 disks from peg 1 to peg 2, using peg 3 as temp holding area
 b) move the last disk (largest) from peg 1 to peg 3
 c) move n - 1 disks from peg 2 to peg 3, using peg 1 as temp holding area

 process ends when the last task is n = 1 disk (base case)

 function takes 4 parameters:
 a) number of disks to be moved
 b) peg on which disks are initially threaded
 c) peg to which the stack of disks is to be moved
 d) peg to be used as temp holding peg

 print precise instructions it will take to move the disks from the starting
 peg to the destination peg, ie :

 1 -> 3
 1 -> 2
 3 -> 2


*/

/*
hanoi(n, start, end)
assumptions:
1 <= start <= 3
1 <= end <= 3
start != end
n >= 1

pm(start, end) = print(start, ->, end) [print move]

recursive problem solving:
let f(n) be recursive function
1) show f(1) works (base case)
2) assume f(n-1) works
3) show f(n) works using f(n-1)

rods include start and end, define other rod as other = 6 - (start + end)
*/



int hanoiFunction(int n, int start, int end); // Hanoi function prototype
int messageDisplay(int start, int end); // Prints pattern of each consecutive move

int n = 0; // For user input
int start = 0; // Starting rod 
int end = 0; // Ending rod 
//int other = 2;

int main(void) { // Main function

	printf("Enter the number of disks:\n");
	scanf("%d", &n);
	printf("Enter the initial starting peg [1, 2, or 3]:\n");
	scanf("%d", &start); 
	printf("Enter the ending peg [1, 2, or 3]:\n");
	scanf("%d", &end);

	if (start > 3 || end > 3) { // Ensures input is valid
		printf("Invalid entry.\n");
	}
	else {
		hanoiFunction(n, start, end); // Calls hanoi function 
	} 
}

int hanoiFunction(int n, int start, int end) { // Hanoi Function

	if (n == 1) { // Base case, handles moving a single disk

		messageDisplay(start, end);

	}

	else { // If user enters any greater number or recursion finally reaches base case

		int other = 6 - (start + end); // Dynamically finds the third peg
		hanoiFunction(n - 1, start, other); // First call moves n - 1 disk from start peg to the other peg using the third as the temp peg
		messageDisplay(start, end); // Move nth disk directly from start peg to end peg. Print message.
		hanoiFunction(n - 1, other, end); // Second call moves n - 1 disk from other peg to end peg using the start peg as the temp peg
		
	}
	return 0;
}

int messageDisplay(int start, int end) {

	printf("move disk from peg %d -> peg %d\n", start, end);
	return 0;

}























/* Reducible, A Complete Recursive Visualization, https://youtu.be/rf6uf3jNjbo?si=nn2FRYWZ2_QeQgBD, May 26, 2020 */
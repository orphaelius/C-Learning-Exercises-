#include <stdio.h>

// write a program that uses looping to print [a] table of values. use the tab escape sequence, \t, in the printf statement 
// to separate the columns with tabs

/*
* column 1 is simply n looped 10 times
* column 2 is n squared looped 10 times
* column 3 is n cubed looped 10 times
* column 4 is n quartic looped 10 times
* 
* initialize function
* 
* initialize variables:
* n
* n^2
* n^3
* n^4
* counter
* start_var
* 
* print message, describing program. press 1 to start function, -1 to end
* scanf start variable and sentinel variable
* 
* while counter < 10
* if -1 , break
* 
* print the following, use columns and tabs
* printn		n^2		n^3		n^4		and so forth for each statement below
* n++
* print2
* print3
* print4
* print5
* print6
* print7
* print8
* print9
* print10
* 
* 
* 
* counter ++
* 
* 

*/

int main(void) {

	int counter = 0;
	
	int start_var = 0;

	printf("%s", "Enter 1 to initialize program or enter -1 to abort: \n");
	scanf("%d", &start_var);

	while (counter < 10) {
		if (start_var == -1) {
			break;
		}				

		int n = 1;
		int n_square = n * n;
		int n_cube = n * n * n;
		int n_quart = n * n * n * n;
		printf("%d\t %d\t %d\t %d\n", n, n_square, n_cube, n_quart); 
		n++;
		counter++;		
	}
	
}

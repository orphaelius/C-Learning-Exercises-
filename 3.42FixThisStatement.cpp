#include <stdio.h>

// What's Wrong? //

/*
* rewrite the following statement to accomplish what the programmer was probably trying to do:
* 
* printf("%d", --(x * y))
* 
*/

int main(void) {
	int x = 10;
	int y = 10;
	int product = 0; 

	while (x != 0) {   
		product = x * y;			
		printf("%d\n", product);  
		--x;		
	}
	
	return 0;
}


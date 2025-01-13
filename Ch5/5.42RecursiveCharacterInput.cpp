#include <stdio.h>

int main(void){ // Recursive character input. Takes character input until EOF is entered, then prints in reverse order. 
	int c = '\O'; 

	if ((c = getchar()) != EOF) { 
		main();
		if (c != '\n') {
			printf("%c", c);
		}
		
	}
}
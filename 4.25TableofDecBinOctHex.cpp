#include <stdio.h>
#include <math.h>

// Table of Decimal, Binary, Octal, and Hexadecimal Equivalents //

/* write a program that prints a table of the binary, octal, and
 hexidecimal equivalents of the decimal numbers 1- 256. hint:
 you can display an integer as an octal or hexadecimal value
 with the conversion specifications %o and %X respectively */

int main(void) {

	int bin[256] = {};
	

	printf("%s %20s %20s %20s\n", "Decimal Value", "Hexidecimal Value", "Octal Value", "Binary Value"); 

	for (int i = 0; i < 256; i++) {
		//num = i;
		printf("%12d %21X %21o\n", i, i, i);  		

	}

	for (int i = 0; i < 256; i++) {
		
		if (i % 2 == 0) {
			bin[i] = 0; 

		}
		else {
			bin[i] = 1;
		}
		
		i /= 2;

		printf("%d\n", bin[i]);  
	}


}
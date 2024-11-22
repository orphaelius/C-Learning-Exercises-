#include <stdio.h>

int main(void) {
	int y = 7;
	int x = 5;


	if (x == 5) {
		if (y == 8) {

			puts("@@@@@");	// x = 5 and y = 8	
		}

		else {
			puts("#####"); //odd one, used if x = 7 with $ and &
		}

		puts("$$$$$"); // x = 5 and y = 8

		puts("&&&&&");// x = 5 and y = 8

	}
}
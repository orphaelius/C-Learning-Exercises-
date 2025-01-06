#include <stdio.h>

// Rectangle of Asterisks et al //

/* write a function tha tdisplays a solid rectangle 
of asterisks whose sides are specified in the integer 
parameters of side1 and side2. */

void asteriskRectangle(int side1, int side2, char fillCharacter);

int side1 = 0; // height of rect
int side2 = 0;
char fillCharacter;  

int main(void) {
	printf("This program prints a square rectangle from a single input character and user-determined height and width.\n");
	
	
	printf("Enter the height of your rectangle, any number below 100: \n");
	scanf("%d", &side1);

	printf("Great, now enter the width of your rectangle, any number below 100: \n");
	scanf("%d", &side2);

	printf("Almost there! Now enter any single character to form the rectangle: \n");
	scanf(" %c", &fillCharacter); 

	asteriskRectangle(side1, side2, fillCharacter);  
}

void asteriskRectangle(int side1, int side2, char fillCharacter) {
	int height = side1;
	int width = side2;
	
	if (height > 100 || width > 100) {
		printf("Those are invalid dimensions...\n");
		return;
	}

	for (int i = 1; i <= height; i++) {
		
		for (int j = 1; j <= width; j++) {
			printf(" %c", fillCharacter);   
		}
		puts("");
	}

}




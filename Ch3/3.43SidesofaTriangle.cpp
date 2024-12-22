#include <stdio.h>

// Sides of a Triangle //
   // 3.43 && 3.44 //



/* 
* 3.43 write a program that reads three nonzero integer values and determines and prints whether they could represent the sides of a triangle
* a triangle is a shape for which one of the following inequality theorems must be true:
* a + b > c
* a + c > b
* b + c > a
* * 
* 
* 3.44 write a program that reads three nonzero integers and determines and prints whether they could be the sides of a right triangle
* 3.44 a right triangle is a shape whose hypotenuse^2 is equal to its base^2 + height^2
*/ 


int main(void) {
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;	

	// begin general triangle //
	printf("Enter any three nonzero integers and I will determine if they could represent the sides of a triangle: \n");
	scanf("%d %d %d", &num1, &num2, &num3);


	if ((num1 + num2 > num3) && (num1 + num3 > num2) && (num2 + num3 > num1)) {
		printf("These could be the sides of a triangle.\n\n");
	}	
	else {
		printf("These could not be the sides of a triangle...\n");
	}
	puts("");
	// end general triangle //





	// begin right traingle //
	int right1 = 0;
	int right2 = 0;
	int right3 = 0;

	int hypotenuse = 0;

	printf("Now enter three more integers and I will determine if they could represent the sides of a right triangle: \n");
	scanf("%d %d %d", &right1, &right2, &right3);	

	// finds hypotenuse //
	hypotenuse = right1;

	if (right2 > hypotenuse){ 
		hypotenuse = right2; 
	}
	if (right3 > hypotenuse) {  
		hypotenuse = right3;
	}

	// square the ints //
	int rightsq1 = right1 * right1;
	int rightsq2 = right2 * right2;
	int rightsq3 = right3 * right3;

	if ((rightsq1 + rightsq2) == (hypotenuse * hypotenuse)) {
		printf("These numbers make a right triangle.\n");
	}
	if ((rightsq1 + rightsq3) == (hypotenuse * hypotenuse)) {
		printf("These numbers make a right triangle.\n");
	}
	if ((rightsq2 + rightsq3) == (hypotenuse * hypotenuse)) {
		printf("These numbers make a right triangle.\n");
	}
	else {
		printf("These numbers do not make a right triangle.\n");
	}
	// end right triangle //
	
	return 0; 

}


#include <stdio.h>
#include <math.h>


// Project: Drawing Shapes with Characters //

/* produce a program that graphs a wide range of shapes. no
other parameters given with regards to approach or total
amount of shapes.*/


void squarePattern(int height, char fillChar);
void rectanglePattern(int height, int width, char fillChar);
void rightTrianglePattern(int rows, char fillChar);
void diamondPattern(int rowAmount, char fillChar);
void parallelogramPattern(int rows, char fillChar);
void circlePattern(int radius, char fillChar);
void ellipsePattern(int width, char fillChar);
void pyramidPattern(int height, char fillChar);
void starPattern(int starLength, char fillChar);

char caseSelection;
char fillChar;
int height = 0;
int width = 0;
int hypotenuse = 0;
int rows = 0;
int radius = 0;
int vertex = 0;
int starLength = 0;

const char* functionLibrary[] = { "Square Pattern", "Rectangle Pattern", "Right Triangle Pattern", "Diamond Pattern", "Parallelogram Pattern", "Circle Pattern",
"Ellipse Pattern" ,"Star Pattern", "Pyramid Pattern" }; // User options for selecting various patterns
const char* caseLetters[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I" }; // Available switch/Case expressions
int functionLibraryLength = sizeof(functionLibrary) / sizeof(functionLibrary[0]); // Size of library array (for printing table)
int caseLetterLength = sizeof(caseLetters) / sizeof(caseLetters[0]); // Size of case letter array (for printing table)


int main(void) {
	printf("This program graphs various patterns from user input. Select from the options below, or EOF to quit: \n");
	for (int i = 0; i < functionLibraryLength; i++) {
		printf("%-23s [%s]\n", caseLetters[i], functionLibrary[i]);
	}
	while ((caseSelection = getchar()) != EOF) {

		switch (caseSelection) {

		case 'A': // Square Pattern
		case 'a':
			printf("Enter the height of the square:\n");
			scanf("%d", &height);
			getchar();

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				squarePattern(height, fillChar);
			}
			break;

		case 'B': // Rectangle Pattern
		case 'b':
			printf("Enter the height of the rectangle:\n");
			scanf("%d", &height);

			printf("Enter the width of the rectangle:\n");
			scanf("%d", &width);
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				rectanglePattern(height, width, fillChar);
			}
			break;

		case 'C': // Right Triangle Pattern
		case 'c':
			printf("Enter the amount of rows for your right triangle:\n");
			scanf("%d", &rows); // could I add a way to change the direction of the triangle?********
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				rightTrianglePattern(rows, fillChar);
			}
			break;

		case 'D': // Diamond Pattern
		case 'd':
			printf("Enter the amount of rows for your diamond:\n");
			scanf("%d", &rows);
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				diamondPattern(rows, fillChar);
			}
			break;

		case 'E': // Parallelogram Pattern
		case 'e':
			printf("Enter the amount of rows for your parallelogram:\n");
			scanf("%d", &rows);
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				parallelogramPattern(rows, fillChar);
			}
			break;

		case 'F': // Circle (? ish) Pattern
		case 'f':
			printf("Enter the radius of your circle:\n");
			scanf("%d", &radius);
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				circlePattern(radius, fillChar);
			}
			break;

		case 'G': // Ellipse Pattern
		case 'g':
			printf("Enter the radius of your ellipse:\n");
			scanf("%d", &width);
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				ellipsePattern(width, fillChar);
			}
			break;

		case 'H': // Star Pattern
		case 'h':
			printf("Enter the length of your star:\n");
			scanf("%d", &starLength); 
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				starPattern(starLength, fillChar); 
			}
			break;

		case 'I': // Pyramid Pattern
		case 'i':
			printf("Enter the height of your pyramid:\n");
			scanf("%d", &width);
			getchar(); //

			printf("Great, now enter your desired character to print:\n");
			fillChar = getchar();

			if (getchar() != '\n') { // Checks for additional characters/ensures user inputs only a single char
				printf("Error: Please enter only a single character.\n");
				while (getchar() != '\n'); // Clear remaining characters in the buffer
			}
			else {
				pyramidPattern(width, fillChar);
			}
			break;


			//default:

		}
		puts("\n");
		printf("Enter a new selection from the table below:\n");
		for (int i = 0; i < functionLibraryLength; i++) {
			printf("%-23s [%s]\n", caseLetters[i], functionLibrary[i]);
		}
	}
}


// List of Functions //

void squarePattern(int height, char fillChar) { // Square Pattern Function
	if (height <= 0 || height > 100) {
		printf("These are not valid conditions. Try again.\n");
		return; // need to ensure user enters only a single character... how?
	}

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= height; j++) {
			printf("%c ", fillChar);
		}
		puts(" ");
	}
}

void rectanglePattern(int height, int width, char fillChar) { // Rectangle Pattern Function
	if (height <= 0 || height > 100 || width <= 0 || width > 100) {
		printf("These are not valid conditions. Try again.\n");
		return; // need to ensure user enters only a single character... how?
	}

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			printf("%c ", fillChar);
		}
		puts(" ");
	}
}

void rightTrianglePattern(int rows, char fillChar) { // Right Triangle Function
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= i; j++) {
			if (j <= i) {
				printf("%c", fillChar);
			}
		}
		puts("");
	}
}

void diamondPattern(int rows, char fillChar) { // Diamond Pattern Function

	for (int i = 1; i <= rows; i++) { // Top Half

		for (int space = 1; space <= rows - i; space++) { // Top Left Quadrant
			printf(" ");
		}

		for (int fill = 1; fill <= i; fill++) {
			printf("%c", fillChar);
		}

		for (int fill = 1; fill <= i; fill++) { // Top Right Quadrant 
			printf("%c", fillChar);
		}
		puts("");
	}

	for (int i = 1; i <= rows; i++) { // Bottom Half

		for (int space = 1; space <= i; space++) { // Bottom Left Quadrant	
			printf(" ");
		}

		for (int fill = rows; fill >= i; fill--) {
			printf("%c", fillChar);
		}

		for (int fill = rows; fill >= i; fill--) { // Bottom Right Quadrant  
			printf("%c", fillChar);
		}
		puts("");
	}
}

void parallelogramPattern(int rows, char fillChar) { // Parallelogram Pattern Function 
	for (int i = 1; i <= rows; i++) {

		for (int space = 1; space <= rows - i; space++) { // Prints triangle pattern of "spaces"
			printf(" ");
		}
		for (int fill = 1; fill <= i; fill++) { // Prints Triangle pattern to the left of main body
			printf("%c", fillChar);
		}
		for (int width = 1; width <= rows; width++) { // Prints main body/square pattern
			printf("%c", fillChar);
		}
		for (int fill = rows; fill >= i; fill--) { // Prints right side triangle
			printf("%c", fillChar);
		}
		puts("");
	}
}

void circlePattern(int radius, char fillChar) { // Circle Pattern Function
	// equation of a cartesian circle: (x-a)^2 + (y-b)^2 = r^2
	for (int i = radius; i >= -radius; i--) { // Vertical
		for (int j = -radius; j <= radius; j++) { // Horizontal
			if (i * i + j * j < radius * radius) { // If the distance from the center is less than radius, print fillChar input
				printf("%c", fillChar);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

/* Hollow circle is cool!
* int height = width / 2;
	for (int i = width; i >= -width; i--) { // Vertical
		for (int j = -height; j <= height; j++) { // Horizontal
			if (i * i + j * j > height * height) { // If the distance from the center is less than radius, print fillChar input
				printf("%c", fillChar);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
*/
/*
void ellipsisPattern(int width, char fillChar) { // ellipse Pattern Function
	// equation of a cartesian ellipse: (x-h)^2/a^2 + (y-k)^2/b^2 = 1

	int height = width / 2;
	for (int i = height; i >= -height; i--) { // Vertical
		for (int j = -height; j <= height; j++) { // Horizontal
			if (i * i / height * height + j * j / width * width < width * width) { // If the distance from the center is less than radius, print fillChar input
				printf("%c", fillChar);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
*/

void ellipsePattern(int radius, char fillChar) { // nope, see above
	int k = 50;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (sqrt((i - (k) / 2) * (i - (k) / 2) + (j - (k) / 2) * (j - (k) / 2)) <= radius)
				printf("%c", fillChar); //meets criteria print * 
			else
				printf(" "); //blank space
		}
		printf("\n");
	}
}

// Following a video from Ullash Tech Valley on YouTube, https://www.youtube.com/watch?v=pG0O_4Cg15E,
// I've used the algorithm for this function. 

void starPattern(int starLength, char fillChar) {
	float angle = 0;
	float PI = 3.1459265358979323846;
	int center = starLength / 2;

	for (int j = 0; j < starLength; j++) {
		for (int i = 0; i < starLength; i++) {
			// calc angle from center
			angle = atan2(j - center, i - center);

			//create conditions for 5 pointed star using angles:
			if (fabs(angle) < 0.4 || fabs(angle - PI / 5) < 0.2 || fabs(angle + PI / 5) < 0.2) {
				printf("%c", fillChar);
			}
			else {
				printf(" "); 
			}
		}
		printf("\n"); 
	}
}

void pyramidPattern(int height, char fillChar) { // Pyramid Pattern Function
	for (int i = 1; i <= height; i++) { // Top Half 

		for (int space = 1; space <= height - i; space++) { // Top Left Quadrant
			printf(" ");
		}

		for (int fill = 1; fill <= i; fill++) {
			printf("%c", fillChar);
		}

		for (int fill = 1; fill <= i; fill++) { // Top Right Quadrant 
			printf("%c", fillChar);
		}
		puts("");
	}

}
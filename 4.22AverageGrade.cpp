#include <stdio.h>
#include <math.h>

// Average Grade //

/* modify figure 4.5 (in textbook) so that it calculates the average grade of class */

int main(void) {

	// counts for each grade letter
	int aCount = 0; 
	int bCount = 0; 
	int cCount = 0; 
	int dCount = 0; 
	int fCount = 0; 	

	// calculates totals for each grade (A total = 4 * aCount)
	int total_grade_a = 0;
	int total_grade_b = 0;
	int total_grade_c = 0;
	int total_grade_d = 0;
	int total_grade_f = 0;

	// total of all grades
	int total_grade_counts = 0;

	// used to calculate average grade value (between 4 (A) and 0 (F))
	double average = 0.0;

	puts("Enter the letter grades: ");
	puts("Enter the EOF character to end input.");

	// initializes grade variable
	int grade = 0;

	while ((grade = getchar()) != EOF) {

		switch (grade) {
		case 'A':
		case 'a':
			++aCount;
			break;

		case 'B':
		case 'b':
			++bCount;
			break;

		case 'C':
		case 'c':
			++cCount;
			break;

		case 'D':
		case 'd':
			++dCount;
			break;

		case 'F':
		case 'f':
			++fCount;
			break;

		case '\n':
		case '\t':
		case ' ':
			break;

		default:
			printf("%s", "Incorrect letter grade entered...");
			puts(" Enter a new letter grade: ");
			break;
		}
	}

	total_grade_a = aCount * 4;
	total_grade_b = bCount * 3; 
	total_grade_c = cCount * 2;
	total_grade_d = dCount * 1;
	total_grade_f = fCount * 0;

	total_grade_counts = aCount + bCount + cCount + dCount + fCount;	

	average = (total_grade_a + total_grade_b + total_grade_c + total_grade_d + total_grade_f) / total_grade_counts; 
	
	if (average >= 4) {
		printf("The average, %.2f, is an A.", average); 
	}

	if (average < 4 && average >= 3) {
		printf("The average, %.2f, is an B.", average);
	}

	if (average < 3 && average >= 2) {
		printf("The average, %.2f, is an C.", average);
	}

	if (average < 2 && average >= 1) {
		printf("The average, %.2f, is an D.", average);
	}

	if (average < 1) {
		printf("The average, %.2f, is an F.", average);
	}
	
}

// the text did not detail what sort of grade average was needed to complete the assignment,
// so i used a weighted system (0 - 4 points) to make it easier and understandable.
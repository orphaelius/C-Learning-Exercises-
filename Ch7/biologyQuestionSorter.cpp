#include <stdio.h>
#include <stdlib.h>

#define UPPERB 60

// Function Prototypes //
void displayDesc(void);
void postedQuestions(int* questionsPtr, int* qNum);
int getqNum(int* qNum);
void printResults(int questions[UPPERB]);
void bubbleSort(int questions[UPPERB]);
void sendToFile(FILE* outfile, int questions[UPPERB]);

/*
modify to take input from the discussion file, then 
remove answered questions for me, outputting the 
available list to a new file for me to print.

*/

int main(void) {	
	int questions[UPPERB] = { 0 };
	int* questionsPtr = questions;
	int qNum = 0;	
	FILE* infile;
	FILE* outfile;
	outfile = fopen("questionNumbers.txt", "w");

	displayDesc();
	postedQuestions(questionsPtr, &qNum);	
	bubbleSort(questions);
	//printResults(questions);
	infile = fopen("questionNumbers.txt", "r");
	sendToFile(outfile, questions);

	if (infile == NULL) {
		printf("No file found...\n");
	}

	//fclose(infile); 

}

void displayDesc(void) {
	printf("%s %s %s", "This program takes random question numbers,",
		"bubble sorts the values in ascending order,",
		"and then sends that data to an output file for easy printing.");
	puts("");
	puts("");
} // End displayDesc()


void postedQuestions(int* questionsPtr, int* qNum) {
	int i = 0;
	printf("Enter the question number or enter -1 to exit: ");
	while ((*qNum = getqNum(qNum)) != -1) {		
		*(questionsPtr + i) = *qNum;		
		i++;
		printf("Enter the question number or enter -1 to exit: ");		
	}
} // End postedQuestions()

int getqNum(int* qNum) {
	scanf("%d", qNum);
	return *qNum;
} // End getqnum

void bubbleSort(int questions[UPPERB]) {
	for (size_t i = 0; i < UPPERB; ++i) {
		for (size_t j = 0; j < UPPERB - 1; ++j) {
			if (questions[j] > questions[j + 1]) {
				int hold = questions[j];
				questions[j] = questions[j + 1];
				questions[j + 1] = hold;
			}
		}
	}
}

void sendToFile(FILE* outfile, int questions[UPPERB]) {
	outfile = fopen("questionNumbers.txt", "w");
	fprintf(outfile, "Question Number\n");
	for (size_t i = 0; i < 15; ++i) {
		fprintf(outfile, "%c", '-');
	}
	puts("");
	
	for (size_t i = 0; i < UPPERB; ++i) {
		if (questions[i] != 0) {
			fprintf(outfile, "\n%15d", questions[i]);
		}
	}

	fclose(outfile);
} // End sendToFile()

void printResults(int questions[UPPERB]) {
	for (size_t i = 0; i < UPPERB; ++i) {
		if (questions[i] != 0) {
			printf("%d ", questions[i]); 
		}
		
	}
} // End printResults()

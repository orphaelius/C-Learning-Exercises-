#include <stdio.h>
#include <stdlib.h>

// Computer-Assisted Instruction //

/* Write a program that will help an elementary school student
learn multiplication. Use the rand function to produce two
positive one-digit integers. The program should then prompt the
user with a question, such as 'how much is 6 times 7?'

The student then inputs the answer. Next, the program checks the
student's answer. If it's correct, display 'Very good!' and ask
another multiplication question. If the answer is incorrect, 
display the message 'Incorrect, please try again.' and let the 
student try the same question repeatedly until the student finally
gets it right. A seperate function should be used to generate each
new question. The function should be called once when the application
begins execution and each time the user answers the question 
correctly. */

/* I added several checks to ensure user input was valid after noticing
entering edge parameters would cause an infinite loop. Additionally, I 
added a functionality that allows a user to stop the program at any time.
QOL, perhaps, though practice for my own development nonetheless. */



int multiplication(int playerGuess, int num1, int num2); 
int num1 = 0;
int num2 = 0;
char trigger; 

int main(void) {

	printf("================= Learning Multiplication =================\n");

	printf("Please enter 'S' to begin:\n");
	scanf(" %c", &trigger);

	while (trigger == 'S' || trigger == 's') {

		int playerGuess = 0; // Variable to store player's guess 
		num1 = rand() % 9 + 1; // Randomizes number between 1 and 9
		num2 = rand() % 9 + 1;

		printf("What is %d times %d?\n", num1, num2);		
		scanf("%d", &playerGuess);

		multiplication(playerGuess, num1, num2); // Multiplication function call

		printf("Enter 'S' to continue or 'Q' to quit:\n");
		scanf(" %c", &trigger);

		if (trigger == 'Q' || trigger == 'q') {
			printf("Exiting game...\n");
			break;
		}
	}
}

int multiplication(int playerGuess, int num1, int num2) { // Function to determine if player's guess matches product of 2 random single-digit numbers

	char correctAnswer[4] = { "Very Good!", "Excellent!", "Nice work!", "Keep up the good work!" };
	char incorrectAnswer[4] = { "Incorrect. Please try again.", "Wrong. Try once more.", "Don't give up!", "No. Keep trying." };	
	

	while (num1 * num2 != playerGuess) { // Loops until player guesses correct answer or ends program		
		//char *correctRandomResponse = correctAnswer[randomIndex];
		char *incorrectRandomResponse = incorrectAnswer[randomIndex];

		printf("%c\n", incorrectAnswer[randomIndex]);   

		int validInput = 0;

		while (!validInput) {

			if (scanf("%d", &playerGuess) == 1) {
				validInput = 1;  // Checks if an integer is entered
			}			
				
		while (getchar() != '\n'); // Clear input buffer to avoid an infinite loop of invalid input.
			
		}
	}

	if (num1 * num2 == playerGuess) { // If product equals player guess, return to main function
		int randomIndex = rand() % 4;  
		printf("%s\n", correctAnswer[randomIndex]);  
	}

	return 0;
}

int randomIndex(void) { 
	srand(time(NULL));
	int randomIndex = rand() % 4;   
	return randomIndex;
}





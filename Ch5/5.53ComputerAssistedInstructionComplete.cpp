#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/* The programming evolution becomes inherently piecemeal as each exercise
in the book after this adds a new element or feature to the program. It
could invariably use some cleaning and restructuring, though it functions
as intended otherwise. */

/* After finishing the exercises as described in the book, I combed through 
and restructured the code to remove ~300 repetitive/unecessary lines. */

int addition(int num1, int num2); // Addition prototype
int subtraction(int num1, int num2); // Subtraction prototype
int multiplication(int num1, int num2); // Multiplication prototype
int testCase(int num1, int num2); // Random problem prototype
int randomNum1(void); // Generates random number
int randomNum2(void);
int randomIndexFunction(void); // Generates random index to display message string
int correctAnswerFunction(void); // Displays correct answer string
int incorrectAnswerFunction(void); // Displays incorrect answer string
int studentAssessment(void); // Calculates percentage of correct answers

int num1 = 0;
int num2 = 0;
int trigger = 0; // Trigger for case label selection
int totalGuesses = 0; // Global variable for player guesses
int correctGuesses = 0; // Global variable to track correct guesses

int main(void) {

	printf("===========================================================\n");
	printf("=================== Learning Arithmetic ===================\n");
	printf("===========================================================\n");

	printf("Please enter '1' for addition, '2' for subtraction, '3' for multiplication, '4' for random, or '-1' to exit:\n");
	scanf(" %d", &trigger);

	while (trigger != EOF) {

		switch (trigger) {
		case 1:
			addition(num1, num2);
			printf("Please enter '1' for addition, '2' for subtraction, '3' for multiplication, '4' to randomize, or '-1' to exit:\n");
			scanf(" %d", &trigger);

			if (trigger == -1) {
				printf("Exiting game...\n");
				break;
			}
			break;

		case 2:
			subtraction(num1, num2);
			printf("Please enter '1' for addition, '2' for subtraction, '3' for multiplication, '4' to randomize, or '-1' to exit:\n");
			scanf(" %d", &trigger);

			if (trigger == -1) {
				printf("Exiting game...\n");
				break;
			}
			break;

		case 3:
			multiplication(num1, num2);
			printf("Please enter '1' for addition, '2' for subtraction, '3' for multiplication, '4' to randomize, or '-1' to exit:\n");
			scanf(" %d", &trigger);

			if (trigger == -1) {
				printf("Exiting game...\n");
				break;
			}
			break;

		case 4:

			int chooseForMe = rand() % 3;  

			if (chooseForMe == 0) {
				addition(num1, num2);
				break;
			}

			if (chooseForMe == 1) {
				addition(num1, num2);
				break;
			}

			if (chooseForMe == 2) {
				addition(num1, num2);
				break;
			}			
			printf("Please enter '1' for addition, '2' for subtraction, '3' for multiplication, '4' to randomize, or '-1' to exit:\n");
			scanf(" %d", &trigger);

			if (trigger == -1) {
				printf("Exiting game...\n");
				break;
			}
		}
	}
}

int multiplication(int num1, int num2) { // Function to determine if player's guess matches product of 2 random single-digit numbers   	

	int randomIndex = randomIndexFunction(); // Randomizer to call array strings at a random index location 
	int playerGuess = 0; // Variable to store player's guess 
	num1 = randomNum1(); // Randomizes numbers
	num2 = randomNum2();

	printf("What is %d times %d?\n", num1, num2);
	scanf("%d", &playerGuess);

	while (num1 * num2 != playerGuess) { // Loops until player guesses correct answer or ends program	
	
		totalGuesses++;

		incorrectAnswerFunction();

		if (totalGuesses == 10) {
			break;
		}

		int validInput = 0;

		while (!validInput) {

			if (scanf("%d", &playerGuess) == 1) {
				validInput = 1;  // Checks if an integer is entered
			}

			while (getchar() != '\n'); // Clear input buffer to avoid an infinite loop of invalid input.
		}
	}

	if (num1 * num2 == playerGuess) { // If product equals player guess, return to main function
		correctGuesses++;
		totalGuesses++;

		correctAnswerFunction();
	}

	if (totalGuesses == 10) {
		studentAssessment();

	}
	return 0;
}

int addition(int num1, int num2) { // Function to determine if player's guess matches product of 2 random single-digit numbers   	

	int randomIndex = randomIndexFunction(); // Randomizer to call array strings at a random index location 
	int playerGuess = 0; // Variable to store player's guess 
	num1 = randomNum1(); // Randomizes numbers
	num2 = randomNum2();

	printf("What is %d plus %d?\n", num1, num2);
	scanf("%d", &playerGuess);

	while (num1 + num2 != playerGuess) { // Loops until player guesses correct answer or ends program	
		
		totalGuesses++;

		incorrectAnswerFunction();

		if (totalGuesses == 10) {
			break;
		}

		int validInput = 0;

		while (!validInput) {

			if (scanf("%d", &playerGuess) == 1) {
				validInput = 1;  // Checks if an integer is entered
			}

			while (getchar() != '\n'); // Clear input buffer to avoid an infinite loop of invalid input.
		}
	}

	if (num1 + num2 == playerGuess) { // If product equals player guess, return to main function
		correctGuesses++;
		totalGuesses++;

		correctAnswerFunction();
	}

	if (totalGuesses == 10) {
		studentAssessment();

	}
	return 0;
}

int subtraction(int num1, int num2) { // Function to determine if player's guess matches product of 2 random single-digit numbers   	

	int randomIndex = randomIndexFunction(); // Randomizer to call array strings at a random index location 
	int playerGuess = 0; // Variable to store player's guess 
	num1 = randomNum1(); // Randomizes numbers
	num2 = randomNum2();

	printf("What is %d minus %d?\n", num1, num2);
	scanf("%d", &playerGuess);

	while (num1 - num2 != playerGuess) { // Loops until player guesses correct answer or ends program	
		
		totalGuesses++;

		incorrectAnswerFunction(); 

		if (totalGuesses == 10) {
			break;
		}

		int validInput = 0;

		while (!validInput) {

			if (scanf("%d", &playerGuess) == 1) {
				validInput = 1;  // Checks if an integer is entered
			}

			while (getchar() != '\n'); // Clear input buffer to avoid an infinite loop of invalid input.
		}
	}

	if (num1 - num2 == playerGuess) { // If product equals player guess, return to main function
		correctGuesses++;
		totalGuesses++;

		correctAnswerFunction();
	}

	if (totalGuesses == 10) {
		studentAssessment();

	}
	return 0;
}

int randomNum1(void) {
	num1 = rand() % 100 + 1;
	return num1;
}

int randomNum2(void) {
	num2 = rand() % 100 + 1;
	return num2;
}

int randomIndexFunction(void) {
	int randomIndex = rand() % 4; // Randomizer to call array strings at a random index location 
	return randomIndex;
}

int correctAnswerFunction(void) {
	const char* correctAnswer[4] = { "Very Good!", "Excellent!", "Nice work!", "Keep up the good work!" };
	int randomIndex = rand() % 4;

	switch (randomIndex) {

	case 0:
		printf("%s\n", correctAnswer[0]);
		break;
	case 1:
		printf("%s\n", correctAnswer[1]);
		break;
	case 2:
		printf("%s\n", correctAnswer[2]);
		break;
	case 3:
		printf("%s\n", correctAnswer[3]);
		break;
	}
	return 0;  
}

int incorrectAnswerFunction(void) {
	const char* incorrectAnswer[4] = { "Incorrect. Please try again.", "Wrong. Try once more.", "Don't give up!", "No. Keep trying." }; 
	int randomIndex = randomIndexFunction();

	switch (randomIndex) {

	case 0:
		printf("%s\n", incorrectAnswer[0]);
		break;
	case 1:
		printf("%s\n", incorrectAnswer[1]);
		break;
	case 2:
		printf("%s\n", incorrectAnswer[2]);
		break;
	case 3:
		printf("%s\n", incorrectAnswer[3]);
		break;
	}
	return 0;
}

int studentAssessment(void) {
	double tempPercentageCorrect = ((double)correctGuesses / totalGuesses) * 100;
	printf("You guessed %.0f%% correctly.\n", tempPercentageCorrect);

	if (tempPercentageCorrect < 75) {
		printf("Please ask your teacher for extra help.\n");
	}

	if (tempPercentageCorrect > 75) {
		printf("Congratulations, you are ready to go to the next level!\n");
	}

	return 0;
}


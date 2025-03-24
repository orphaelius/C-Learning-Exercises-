/*******************************************************************************

					 // Card Games 7.17- 7.21 //

	This program is a merger of 5 exercises in the text that evolve a simple
	shuffling program to a fully functional poker game. The parameters
	of the game have changed repeatedly as these exercises go on, building
	conceptually in difficulty and scope.

	The final program is a -mostly- full poker game that allows a player to
	manually swap cards. The dealer automatically exchanges cards depending
	on the dealer's original hand. It then compares the final hands and displays
	which of the two contenders has won that round.

	NEED TO ADD: additional winning hand types, comparison checks for when
	player and dealer both have a hand of pairs, etc, to determine which hand
	is of higher value

	Written by: Orphaelius

	Date: 03/17/2025

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


// Preprocessor definitions
#define SUITS 4 // Total suits
#define FACES 13 // Total face values
#define HAND 5 //  Cards dealt per hand
#define HEADERWID 47 // Used to print header decoration
#define MENUOPT 7 // Menu options
#define MENUCHAR 90 // Max char limit for menu strings
#define PADDING 5 // Adds space padding to the diamond header

// Global structure and arrays to reduce needless/repetitive passing
typedef struct { // Structure for card
	const char* face;
	const char* suit;
} Card;

const char* suits[SUITS] = // Array storing suit strings
{ "Hearts", "Diamonds", "Clubs", "Spades" };
const char* faces[FACES] = // Array storing face strings
{ "Deuce", "Three", "Four", "Five", "Six",
  "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace", };

// Used to convert the face strings to integer values to determine straight
int playerIntValues[HAND] = { 0 };
int dealerIntValues[HAND] = { 0 };

const char* rank[] = // Array storing ranks; used to determine player hand, ------------------------- currently UNUSED
{ "Pair", "Two Pairs", "Three of a Kind",
  "Four of a Kind", "Flush", "Straight" };

// Function Prototypes //
void initializeDeck(Card deck[SUITS * FACES]); // Initializes deck
void shuffleDeck(Card deck[SUITS * FACES]); // Shuffles deck
// Deals hands to players
void fillPlayerHand(Card playerHand[HAND], Card deck[SUITS * FACES], 
	int* deckIndex);
// Displays contents of hands to console
void printHand(Card player1Hand[HAND], Card dealerHand[HAND], int reveal);

// Checks for pair, three, four of a kind
int determineCombinations(Card playerHand[HAND]);
int determineFlush(Card playerHand[HAND]); // Checks for flush
int determineStraight(int playerIntHand[HAND]); // Checks for straight

// Series of functions to convert cards to int values and bubble sort 
int getFaceValues(const char* face);
void bubbleSortHand(int playerIntHand[HAND]);
void convertPlayerHandToInts(Card playerHand[HAND], int handValues[HAND]);

void playerSwapCard(int swapIndices[HAND]);

// DEALER FUNCTIONS //
void autonomousDealer(Card deck[HAND], Card dealerHand[HAND], 
	int dealerIntValues[HAND], int* deckIndex);
void replaceCards(Card playerHand[HAND], int swapIndices[HAND], Card deck[], 
	int* deckIndex);
void dealerSwapCards(Card dealerHand[HAND], int dealerIntValues[HAND], 
	int swapIndices[HAND]);

// Calls group of functions to determine a player's score based on return values;
// Displays score to console after;
int compareHands(Card player1Hand[HAND], Card dealerHand[HAND]);
int highestCard(int playerIntHand[HAND], int dealerIntHand[HAND]);
void displayWinner(int winner, Card player1Hand[HAND], Card dealerHand[HAND]);

// Other prototypes
int getSwitchKey(int* switchKey); // Gets switch key
void showMenu(char menu[MENUOPT][MENUCHAR]); // Shows menu
void diamondsHeader(); 

/*******************************************************************************
	Function: main()
	Description: Initializes a deck of cards and then gives a user the autonomy
	to deal, or check hand, etc
	Parameters: ---
	Return: ---
*******************************************************************************/
int main(void) {

	srand(time(NULL));
	Card deck[SUITS * FACES] = { 0 };
	Card player1Hand[HAND] = { 0 };
	Card dealerHand[HAND] = { 0 };
	// Used exclusively to debug functions
	//int debuggingHand[HAND] = { 1, 2, 3, 4, 5 }; 
	int swapIndices[HAND] = { 0 }; // Allows a player to exchange cards 
	int totalPlayerSwaps = 0;
	int reveal = 0;
	int winningHand = 0;
	int deckIndex = 0;
	int switchKey = 0;
	char gameContinue = ' '; // Continues game loop depending on user input
	char menu[MENUOPT][MENUCHAR] =
	{ "------------------- M E N U -------------------",
	  "-----------------------------------------------",  
	  "Enter 1 to select a card to replace",
	  "Enter 2 to show hands",
	  "Enter 9 compare hand to dealer hand",
	  "Enter -1 to rage quit and saunter out of the \ncasino, partially blind",
	  "-----------------------------------------------" };
	
	diamondsHeader();

	// Initializes/fills the deck
	initializeDeck(deck);
	printf("%40s", "Dealer is shuffling the deck...\n");
	Sleep(2000);
	shuffleDeck(deck); // Shuffles deck
	printf("%44s", "Dealer is dealing player hands...\n\n\n");
	Sleep(2000);
	// Fills player and dealer hands with 5 shuffled cards
	fillPlayerHand(player1Hand, deck, &deckIndex);
	fillPlayerHand(dealerHand, deck, &deckIndex);

	// Displays initial hands to console
	printHand(player1Hand, dealerHand, reveal);
	showMenu(menu);
	// Runs primary function that automatically swaps cards in a dealer's hand
	// if dealer doesn't have a straight or a flush
	autonomousDealer(deck, dealerHand, dealerIntValues, &deckIndex);	
	
	while ((switchKey = getSwitchKey(&switchKey)) != -1) {

		switch (switchKey) {

		case 1:			
			if (totalPlayerSwaps == 2) {
				printf("You've reached the maximum swap attempts. Select another option.\n");
				break;
			}			
			playerSwapCard(swapIndices);
			replaceCards(player1Hand, swapIndices, deck, &deckIndex);
			printf("Dealer is passing new cards...\n");
			Sleep(2000);
			(totalPlayerSwaps)++; 
			break;
		case 2:
			printf("print updated hands\n");
			printHand(player1Hand, dealerHand, reveal); 
			break;

		case 9:
			printf("Contenders show their hands... \n");
			Sleep(2000);
			reveal = 1;
			printHand(player1Hand, dealerHand, reveal);
			// Runs both hands to determine winner based on a point system
			compareHands(player1Hand, dealerHand);		
			// Display winner to console
			displayWinner(winningHand, player1Hand, dealerHand);
			break;

		}

		if (switchKey == 9) {
			printf("Ending game\n");
			break;
		}

		showMenu(menu);
	} 

	return 0;
} // End main()

/*******************************************************************************
	Function: initializeDeck()
	Description: Nested for loop initalizes each element of the deck array and
	fills each SUIT with the respective FACE values before iterating to the next
	SUIT. This is a more efficient way to handle the Dietel example, relying on
	a simple structure and fewer loops to acheive the same end result.
	Parameters: deck Card structure
	Return: ---
*******************************************************************************/
void initializeDeck(Card deck[SUITS * FACES]) {
	int cardIndex = 0;
	for (int suit = 0; suit < SUITS; ++suit) {
		for (int face = 0; face < FACES; ++face) {
			deck[cardIndex].face = faces[face];
			deck[cardIndex].suit = suits[suit];
			cardIndex++;
		}
	}
} // End initializeDeck()

/*******************************************************************************
	Function: shuffleDeck()
	Description: Shuffles the deck by iterating through the deck, swapping each
	card with a randomly selected index
	Parameters: deck Card structure
	Return: ---
*******************************************************************************/
void shuffleDeck(Card deck[SUITS * FACES]) {
	// Shuffling algorithm, swaps every card once for a card at a random index
	for (size_t i = SUITS * FACES - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		Card temp = deck[i]; // Necessary to not overwrite the current element
		deck[i] = deck[j];
		deck[j] = temp;
	}
} // End shuffle()

/*******************************************************************************
	Function: fillPlayerHand()
	Description: Fills a hand with the next top series of card from an already
	shuffled deck of cards. Points to deckIndex, which keeps track of the index
	of the card deck so that cards dealt are not repeated.
	Parameters: deck Card structure, Card playerHand structure, points to
	deckIndex
	Return: ---
*******************************************************************************/
void fillPlayerHand(Card playerHand[HAND], Card deck[SUITS * FACES], 
	int* deckIndex) {

	for (size_t i = 0; i < HAND; ++i) {
		// Player's hand is the top 5 cards of an already shuffled deck
		playerHand[i] = deck[*deckIndex];		
		(*deckIndex)++;
	}
} // End fillPlayerHand()

/*******************************************************************************
	Function: printHand()
	Description: Displays both player's hand and dealer's hand to console
	Parameters: playerHand Card structure, dealer Card structure
	Return: ---
*******************************************************************************/
void printHand(Card player1Hand[HAND], Card dealerHand[HAND], int reveal) {	

	if (reveal == 0) {
		printf("----------------- P O K E R -------------------\n");
		printf("%s%36s", "Player Hand", "Dealer Hand\n");
		for (int i = 0; i < HEADERWID; ++i) {
			printf("%c", '-');
		}
		puts("");
		for (int i = 0; i < HAND; ++i) {
			printf("%-2s of %-20s %8s of %s\n", player1Hand[i].face,
				player1Hand[i].suit, "[###]", "[###]");
		}
		printf("\n\n\n");
	}
	else {
		printf("----------------- P O K E R -------------------\n");
		printf("%s%36s", "Player Hand", "Dealer Hand\n");
		for (int i = 0; i < HEADERWID; ++i) {
			printf("%c", '-');
		}
		puts("");
		for (int i = 0; i < HAND; ++i) {
			printf("%-2s of %-20s %8s of %s\n", player1Hand[i].face,
				player1Hand[i].suit, dealerHand[i].face, dealerHand[i].suit);
		}
		printf("\n\n\n");
	}
} // End printHand()

/*******************************************************************************
	Function: determineCombinations()
	Description: Iterates through playerHand structure to determine if a hand
	holds a pair, two pairs, three of a kind, or four of a kind, and then uses
	return values as a way to determine the significance of these combinations
	Parameters: playerHand Card structure
	Return: Point system integer values to compare hand significance between
	players
*******************************************************************************/
int determineCombinations(Card playerHand[HAND]) {
	int faceCounts[FACES] = { 0 };
	int pairs = 0;
	int twoPairs = 0;
	int threeOfaKind = 0;
	int fourOfaKind = 0;

	for (size_t i = 0; i < HAND; ++i) {
		for (size_t j = 0; j < FACES; ++j) {
			if (strcmp(playerHand[i].face, faces[j]) == 0) {
				faceCounts[j]++;				
				break;
			}
		}
	}

	for (size_t i = 0; i < FACES; ++i) {
		if (faceCounts[i] == 2) pairs++;
		if (faceCounts[i] == 3) threeOfaKind = 1;
		if (faceCounts[i] == 4) fourOfaKind = 1;   
	}

	if (fourOfaKind == 1) return 4;
	else if (threeOfaKind == 1) return 3;
	else if (pairs == 2) return 2;
	else if (pairs == 1) return 1;
	else return 0;

} // End determineCombinations()

/*******************************************************************************
	Function: determineFlush()
	Description: Determines if player's hand contains a flush; uses strcmp to
	iterate through two arrays character-by-character and determine if there are
	matching strings.
	Parameters: playerHand Card structure
	Return: 0 if hand holds no flush, 5 if hand holds flush
*******************************************************************************/
int determineFlush(Card playerHand[HAND]) {
	int suitCounts[HAND] = { 0 };
	int flush = 0;
	for (size_t i = 0; i < HAND; ++i) {
		for (size_t j = 0; j < SUITS; ++j) {
			if (strcmp(playerHand[i].suit, suits[j]) == 0) {				 
				suitCounts[j]++;				
				break;
			}
		}
	}

	for (size_t i = 0; i < SUITS; ++i) {
		if (suitCounts[i] == 5) {
			printf("Flush!!\n");
			return 5;
		}
	}

	return 0;

} // End determineFlush()

/*******************************************************************************
	Function: determineStraight()
	Description: Determines if a player's hand is a straight or not. Loops
		through an int-converted hand and checks each card for numerically
		consecutive values in order of i, i + 1, etc
	Parameters: Player's int-converted hand
	Return: Returns the highest card value in a consecutive series IF the player
		is holding a straight, otherwise returns 0;
*******************************************************************************/
int determineStraight(int playerIntHand[HAND]) {
	// Counts total cards in consecutive numerical order; starts at 1
	// assuming the initial card is part of the series
	int straightCount = 1;

	for (size_t i = 0; i < HAND - 1; ++i) {
		if (playerIntHand[i] == playerIntHand[i + 1] - 1) {
			straightCount++;
		}
	}

	if (straightCount == 5) {
		return playerIntHand[4]; // returns highest card in straight
	}
	else {
		return 0; // returns highest element if there is a straight, else returns 0
	}
} // End determineStraight()

/*******************************************************************************
	Function: getFaceValues()
	Description: determines the integer 'value' of a card face
	Parameters: points to const char face
	Return: card value, or -1 if something is awry
*******************************************************************************/
int getFaceValues(const char* face) {
	for (int i = 0; i < FACES; ++i) {
		if (strcmp(face, faces[i]) == 0) {
			return i + 2;
		}
	}
	return -1;
} // End getFaceValues()

/*******************************************************************************
	Function: convertPlayerHandToInts()
	Description: converts the cards a player holds to integer values; used to
		pass into a bubble sort function that will be used to check if a hand
		is a straight or not
	Parameters: playerHand Card structure, handValues array
	Return: ---
*******************************************************************************/
void convertPlayerHandToInts(Card playerHand[HAND], int handValues[HAND]) {
	for (int i = 0; i < HAND; ++i) {
		handValues[i] = getFaceValues(playerHand[i].face);
	}
} // End convertPlayerHandToInts()

/*******************************************************************************
	Function: bubbleSortHand()
	Description: Bubble sorts a player's int hand
	Parameters: A player's int-converted hand
	Return: ---
*******************************************************************************/
void bubbleSortHand(int playerIntHand[HAND]) {
	for (size_t i = 0; i < HAND - 1; ++i) {
		for (size_t j = 0; j < HAND - i - 1; ++j) {
			if (playerIntHand[j] > playerIntHand[j + 1]) {
				int temp = playerIntHand[j];
				playerIntHand[j] = playerIntHand[j + 1];
				playerIntHand[j + 1] = temp;
			}
		}
	}
} // End bubbleSortHand()

/*******************************************************************************
	Function: autonomousDealer()
	Description: Main dealer card-swapping function; converts dealer's hand to
	integer values, sorts them numerically, runs loop to determine which
	cards dealer will swap (strategically based on value of current hand). Allows
	dealer to swap cards two times.
	Parameters: deck and dealer Card structures
	Return: ---
*******************************************************************************/
void autonomousDealer(Card deck[HAND], Card dealerHand[HAND], 
	int dealerIntValues[HAND], int* deckIndex) {
	// Converts hand strings to integer values and sorts them in numerically 
	// ascending order, used to determine if straight
	convertPlayerHandToInts(dealerHand, dealerIntValues);
	bubbleSortHand(dealerIntValues);

	// Array to determine which cards the dealer will swap
	int dealerSwapIndices[HAND] = { 0 }; 
	int straightCount = 1;
	int suitCounts[HAND] = { 0 };
	int flush = 0;
	int dealerScore = 0;
	int iterations = 0;

	while (iterations < 2) {
		dealerSwapCards(dealerHand, dealerIntValues, dealerSwapIndices);

		int swapCount = 0;
		for (size_t i = 0; i < HAND; ++i) {
			if (dealerSwapIndices[i] == 1) swapCount++;
		}

		if (swapCount == 0) break;

		replaceCards(dealerHand, dealerSwapIndices, deck, deckIndex);
		iterations++;
		// printf("Dealer swaps a card...\n");
	}
} // End autonomousDealer()

/*******************************************************************************
	Function: replaceCards()
	Description: Main function to replace a contender's cards at a specific index
	Parameters: deck and player Card structures, swapIndices array, points to
	deckIndex to ensure that each swapped card is a new card-- moves through the 
	deck by index
	Return: ---
*******************************************************************************/
void replaceCards(Card playerHand[HAND], int swapIndices[HAND], Card deck[], 
	int* deckIndex) {
	for (size_t i = 0; i < HAND; ++i) {
		if (swapIndices[i] == 1) {
			playerHand[i] = deck[*deckIndex];
			(*deckIndex)++;
		}
	}
} // End replaceCards()

/*******************************************************************************
	Function: dealerSwapCards()
	Description: Algorithmically determines which cards dealer should swap based
	on their current hand. It swaps no cards if dealer holds a flush or straight.
	It waterfalls from greatest hand (fewest swaps) to weakest hand (most swaps),
	and loops through this twice.
	Parameters: dealer Card structure, dealerIntVal array, swapIndices array
	Return: ---
*******************************************************************************/
void dealerSwapCards(Card dealerHand[HAND], int dealerIntValues[HAND], 
	int dealerSwapIndices[HAND]) {
	int faceCounts[FACES] = { 0 };
	int pairs = 0;
	int twoPairs = 0;
	int threeOfaKind = 0;
	int fourOfaKind = 0;

	// Increments total counts/occurrences for each card value at [i]
	for (size_t i = 0; i < HAND; ++i) {
		faceCounts[dealerIntValues[i] - 2]++;
	}

	for (size_t i = 0; i < FACES; ++i) {
		if (faceCounts[i] == 2) pairs++;
		if (faceCounts[i] == 3) threeOfaKind = 1;
		if (faceCounts[i] == 4) fourOfaKind = 1;
	}
	if (pairs == 2) twoPairs = 1;

	for (size_t i = 0; i < HAND; ++i) dealerSwapIndices[i] = 0; // reset swapIndices 

	// Determine which cards should be swapped 
	if (fourOfaKind) {
		for (size_t i = 0; i < HAND; ++i) {
			if (faceCounts[dealerIntValues[i]] == 1) {
				dealerSwapIndices[i] = 1;
			}
		}
	}
	else if (threeOfaKind) {
		int toSwap = 2;
		for (size_t i = 0; i < HAND && toSwap > 0; ++i) {
			if (faceCounts[dealerIntValues[i]] == 1) {
				dealerSwapIndices[i] = 1;
				toSwap--;
			}
		}
	}
	else if (twoPairs) {
		for (size_t i = 0; i < HAND; ++i) {
			if (faceCounts[dealerIntValues[i]] == 1) {
				dealerSwapIndices[i] = 1;
			}
		}
	}
	else if (pairs == 1) {
		int toSwap = 3;
		for (size_t i = 0; i < HAND; ++i) {
			if (faceCounts[dealerIntValues[i]] == 1) {
				dealerSwapIndices[i] = 1;
				toSwap--;
			}
		}
	}
	else {
		int highestIndex = 0;
		for (size_t i = 1; i < HAND; ++i) {
			if (dealerIntValues[i] > dealerIntValues[highestIndex]) {
				highestIndex = i;
			}
		}

		for (size_t i = 0; i < HAND; ++i) {
			if (i != highestIndex) {
				dealerSwapIndices[i] = 1;
			}
		}
	}
} // End dealerSwapCards

/*******************************************************************************
	Function: playerSwapCard()
	Description: This function allows a player to dynamically select cards to 
	exchange. After entering cards to replace, the replaceCard() function is
	subsequently called, passing the updated swapIncides array.
	Parameters: swapIndices array
	Return: ---
*******************************************************************************/
void playerSwapCard(int swapIndices[HAND]) { 
	
	printf("%s %s\n%s", 
		"Enter the card number(s) (1-5) that you would like to replace,", 
		"followed by a space.", "Enter (0) when you are finished.\n");
	printf("Cards to swap: ");
	for (size_t i = 0; i < HAND; ++i) { // Resets elements (to 0)
		swapIndices[i] = 0;
	}

	int replaceCard = 0;
	while (1) { // Loops to replace cards at input positions (-1 to pass the index)
		scanf("%d", &replaceCard);

		if (replaceCard == 0) break; // End loop if player enters 0

		// Ensures player inputs only proper values
		if (replaceCard >= 1 && replaceCard <= 5) {
			// If player enters a specific card number to replace, swap element at 
			// that location is turned to 'true'
			swapIndices[replaceCard - 1] = 1; 
		}
		else {
			printf("%s%s", 
				"Invalid entry... please enter a real card position", 
				"or enter(0) to end.\n");
			printf("Cards to swap: ");
		}
	}
} // End playerSwapCard()

/*******************************************************************************
	Function: compareHands()
	Description: Compares player and dealer hands to each other; Each contender
	has a summing variable (score) that is used to tally their scores. These
	variables are passed through consecutive 'types of hands' functions that
	determine what kind of hands the player and dealer have and what these hands
	are worth.
	Parameters: player and dealer Card structures
	Return: 0 if draw, 1 if player 1 has better hand, 2 if player 2 has better
		hand
*******************************************************************************/
int compareHands(Card player1Hand[HAND], Card dealerHand[HAND]) {
	int player1Score = 0;
	int dealerScore = 0;

	player1Score += determineCombinations(player1Hand);
	player1Score += determineFlush(player1Hand);
	convertPlayerHandToInts(player1Hand, playerIntValues);
	bubbleSortHand(playerIntValues);
	player1Score += determineStraight(playerIntValues);

	dealerScore += determineCombinations(dealerHand);
	dealerScore += determineFlush(dealerHand);
	convertPlayerHandToInts(dealerHand, dealerIntValues);
	bubbleSortHand(dealerIntValues);
	dealerScore += determineStraight(dealerIntValues);

	if (player1Score == dealerScore) {
		return 0; // Draw
	}
	if (player1Score == 0 && dealerScore == 0) {
		return 0; // Draw
	}
	else if (player1Score > dealerScore) {
		return 1; // Player wins
	}
	else {
		return 2; // Dealer wins
	}
} // End compareHands()

/*******************************************************************************
	Function: displayWinner()
	Description: Displays winner (or draw) to console
	Parameters: player and dealer Card structures
	Return: ---
*******************************************************************************/
void displayWinner(int winningHand, Card player1Hand[HAND], Card dealerHand[HAND]) {
	// compareHands takes contender hands as arguments and, using a point
	// system, determines which hand is of greater value, then returns which
	// contender has won the round (0 for draw, 1 for player 1, 2 for dealer)
	winningHand = compareHands(player1Hand, dealerHand);

	if (winningHand == 0) {
		printf("It's a draw!\n");
		winningHand = highestCard(playerIntValues, dealerIntValues);
		if (winningHand == 1) {
			printf("Player wins hand!\n");
		}
		else if (winningHand == 2) {
			printf("Dealer wins hand!\n");
		}
		else {
			printf("Error checking hands...\n");
		}
	}
	else if (winningHand == 1) {
		printf("Player 1 wins round!\n");
	}
	else {
		printf("Dealer wins round!\n");
	}
} // End displayWinner()

/*******************************************************************************
	Function: getSwitchKey()
	Description: Passes switch key back into main body loop
	Parameters: Points to switchKey, allowing for perpetual update of value to
	navigate the main game loop accordingly
	Return: switchKey
*******************************************************************************/
int getSwitchKey(int* switchKey) {
	scanf("%d", switchKey);
	return *switchKey;
} // End getSwitchKey()

/*******************************************************************************
	Function: showMenu()
	Description: Displays menu options to console
	Parameters: menu array
	Return: ---
*******************************************************************************/
void showMenu(char menu[MENUOPT][MENUCHAR]) {
	for (size_t i = 0; i < MENUOPT; ++i) {
		for (size_t j = 0; j < MENUCHAR; ++j) {
			printf("%c", menu[i][j]);
		}
		puts("");
	}
} // End showMenu()

/*******************************************************************************
	Function: highestCard()
	Description: Determines which player has the highest card of a hand if the
	hands have similar combinations
	Parameters: player and dealer integer hand arrays
	Return: winningHand
*******************************************************************************/
int highestCard(int playerIntHand[HAND], int dealerIntHand[HAND]) {
	
	int playerHighCard = playerIntHand[4];
	int dealerHighCard = dealerIntHand[4];

	printf("Player high card: %d, dealer high card: %d\n", playerHighCard, dealerHighCard);

	if (playerHighCard > dealerHighCard) {
		return 1;
	}
	else {
		return 2;
	}
	return -1; // Error 
} // End highestCard()

/*******************************************************************************
	Function: diamondsHeader()
	Description: Prints diamond pattern and game name at program initialization
	Parameters: ---
	Return: ---
*******************************************************************************/
void diamondsHeader() {
	int size = 5;
	int width = size * 2 - 1;  // Width of one diamond
	
	printf("===============================================\n");
	printf("---------------- POKER GAME -------------------\n");
	printf("===============================================\n");
	printf("\n\n\n");	

	// Upper half
	for (int i = 0; i < size; ++i) {
		printf("%*s", PADDING, "");

		for (int d = 0; d < 3; ++d) {  // Print 3 diamonds
			for (int j = 0; j < width; ++j) {
				if (j >= size - 1 - i && j <= size - 1 + i)
					printf("*");
				else
					printf(" ");
			}
			printf("   ");  // Spacing between diamonds
		}
		printf("\n");
	}

	// Bottom half
	for (int i = size - 2; i >= 0; --i) {
		printf("%*s", PADDING, "");

		for (int d = 0; d < 3; ++d) {  // Print 3 diamonds
			for (int j = 0; j < width; ++j) {
				if (j >= size - 1 - i && j <= size - 1 + i)
					printf("*");
				else
					printf(" ");
			}
			printf("   ");  // Spacing between diamonds
		}
		printf("\n");
	}	
	 printf("\n\n\n");
} // End diamonHeader()





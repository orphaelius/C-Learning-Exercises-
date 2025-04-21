#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ELEMENTS 10
#define CHARMAX 30
#define SENTENCE 200

/*
- use random number gen to create sentences
- four arrays of pointers to char called article, noun, verb, and preposition
- create a sentence by selecting a word at random from each array
- order: article, noun, verb, preposition, article, noun
- as each word is picked, concatenate it to the previous words
- final sentence should start with a capital letter and end with a period
- generate 20 sentences
*/

void concatStrings(char articles[][CHARMAX], char nouns[][CHARMAX],
	char verbs[][CHARMAX], char prepositions[][CHARMAX]);

int main(void) {
	srand(time(NULL));
	char articles[ELEMENTS][CHARMAX] = { "the", "a", "some", "many", "some", "any", "one","an", "all", "multitudes"};
	char nouns[ELEMENTS][CHARMAX] = { "dog", "wife", "town", "husband", "avocado tree", "dinnerware", "Shakespeare's Complete Works","truck", "shoes", "bean bag"};
	char verbs[ELEMENTS][CHARMAX] = { "ran", "burned", "skipped", "slung", "screamed", "jumped", "drove","courted", "ate", "requested"};
	char prepositions[ELEMENTS][CHARMAX] = { "below", "on", "above", "around", "beneath", "beside", "between","from", "off", "inside"};

	for (size_t roll = 0; roll < 20; ++roll) {
		concatStrings(articles, nouns, verbs, prepositions);
	}
} // End main()

void concatStrings(char articles[][CHARMAX], char nouns[][CHARMAX], 
	char verbs[][CHARMAX], char prepositions[][CHARMAX]) {
	char sentence[SENTENCE] = { "" };
	int articlesRoll = 0;
	int nounsRoll = 0;
	int verbsRoll = 0;
	int prepsRoll = 0;

	articlesRoll = rand() % 10;
	strcat(sentence, articles[articlesRoll]);
	sentence[0] = toupper(sentence[0]); 
	strcat(sentence, " ");

	nounsRoll = rand() % 10;
	strcat(sentence, nouns[nounsRoll]);
	strcat(sentence, " ");

	verbsRoll = rand() % 10;
	strcat(sentence, verbs[verbsRoll]);
	strcat(sentence, " ");

	prepsRoll = rand() % 10;
	strcat(sentence, prepositions[prepsRoll]);
	strcat(sentence, " ");

	articlesRoll = rand() % 10;
	strcat(sentence, articles[articlesRoll]);
	strcat(sentence, " ");

	nounsRoll = rand() % 10;
	strcat(sentence, nouns[nounsRoll]);
	strcat(sentence, ".");

	printf("%s\n", sentence);
} // End concatStrings()

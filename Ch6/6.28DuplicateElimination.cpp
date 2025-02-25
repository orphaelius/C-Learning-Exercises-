/*******************************************************************************

                              // Duplicate Values //

    This program creates an array of size [20] of random values. Afterwards,
    it sorts the array using bubble sort, finds any duplicate values, replaces
    those duplicates with 0s, and then prints the final array without duplicate
    values.

    Written by: Orphaelius

    Date: 02/16/2025

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 20
#define UPPERB 20 // Maximum value for random number
#define LOWERB 1 // Minimum value for random number

// FUNCTION PROTOTYPES //
void displayDescription(void);
int randomGen(void); // Generations a random value
void createArray(int array[ELEMENTS]); // Creates initial array of random values
void bubbleSort(int array[ELEMENTS]); // Bubble sort
// Finds duplicate values in original array
int findDuplicates(int array[ELEMENTS], int* duplicateValCount);
// Replaces duplicate values with 0s
void deleteDuplicates(int randArray[ELEMENTS], int finalArray[ELEMENTS]);
void printStandArray(int array[ELEMENTS]); // Print normal array
void printNonDupArray(int array[ELEMENTS]); // Print array without 0s

/*******************************************************************************
    Function: main()
    Description: Takes user input, process, prints output..
    Parameters: ---
    Return: ---
*******************************************************************************/
int main(void) {
    srand(time(NULL)); // Hit us with that sweet 1970 Unix epoch initialization 
    int randArray[ELEMENTS] = { 0 }; // Initial array for 20 random values
   
    // Counter for number of duplicate values
    // Used to determine size of final array
    int duplicateValCount = 0;  
    const int tempIndex = duplicateValCount; // CAN I USE AS ARRAY SIZE?
    //int searchArray[tempIndex] = { 0 }; // FIGURE THIS SHIT OUT 
    size_t elements = duplicateValCount; // NECESSARY?  
    int finalArray[ELEMENTS] = { 0 };    

    displayDescription(); 
    createArray(randArray); // Produces array with random values
    printStandArray(randArray); // Prints random array
    bubbleSort(randArray); // Sorts random array
    printStandArray(randArray); // Prints the sorted random array

    findDuplicates(randArray, &duplicateValCount); // Finds duplicate values     
    // Replaces duplicate values with 0
    deleteDuplicates(randArray, finalArray); 
    printf("The final array is:\n");
    bubbleSort(finalArray); // Sorts final array   
    printNonDupArray(finalArray); // Print without 0s

    return 0;
} // End main()

/*******************************************************************************
    Function: displayDescription()
    Description: Displays program intentions.
    Parameters: ---
    Return: ---
*******************************************************************************/
void displayDescription(void) {
    printf("%s%s%s%s",
        "This program generates a 20-element array of random values,",
        " sorts those values, determines if there are any duplicate values,",
        " and then stores non-duplicate values in an array of the smallest",
        " possible size, subsequently printing the latter array.\n");
} // End displayDescription()

/*******************************************************************************
    Function: createArray()
    Description: Creates an array of random values
    Parameters: Any array
    Return: ---
*******************************************************************************/
void createArray(int array[ELEMENTS]) {
    for (size_t i = 0; i < ELEMENTS; ++i) {
        array[i] = randomGen();
    }
} // End createArray()

/*******************************************************************************
    Function: randomGen()
    Description: Produces a random value between 1 and 20
    Parameters: ---
    Return: randNum (random value)
*******************************************************************************/
int randomGen(void) {
    int randNum = 0;
    randNum = rand() % (UPPERB - LOWERB + 1) + LOWERB;
    return randNum;
} // End randomGen()

/*******************************************************************************
    Function: bubbleSort()
    Description: Sorts array into alphabetical order
    Parameters: Any array
    Return: ---
*******************************************************************************/
void bubbleSort(int array[ELEMENTS]) {
    int tempElements = ELEMENTS - 1;
    int tempPos = 0;

    for (int i = 0; i < ELEMENTS; ++i) {
        for (int j = 0; j < tempElements; ++j) {

            if (array[j] > array[j + 1]) {
                tempPos = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tempPos;
            }
        }
    }
} // End bubbleSort()

/*******************************************************************************
    Function: findDuplicate()
    Description: Counter for any duplicate values
    Parameters: Any array, points to duplicateValCount
    Return: *duplicateValCount
*******************************************************************************/
int findDuplicates(int array[ELEMENTS], int* duplicateValCount) {
    for (int i = 0; i < ELEMENTS; ++i) {
        if (array[i] == array[i + 1]) {
            (*duplicateValCount)++;
        }
    }
    return *duplicateValCount;
} // End findDuplicates()

/*******************************************************************************
    Function: deleteDuplicates()
    Description: "Deletes" duplicate values by replacing any such duplicates
    with 0s. 
    Parameters: Two arrays
    Return: ---
*******************************************************************************/
void deleteDuplicates(int randArray[ELEMENTS], int finalArray[ELEMENTS]) {
    for (int i = 0; i < ELEMENTS; ++i) {
        finalArray[i] = randArray[i];
        if (randArray[i] == randArray[i + 1]) {
            finalArray[i] = 0;
        }

    }
} // End deleteDuplicates()

/*******************************************************************************
    Function: printStandArray()
    Description: Used to print an array with no additional operations
    Parameters: Any array
    Return: ---
*******************************************************************************/
void printStandArray(int array[ELEMENTS]) {
    for (size_t i = 0; i < ELEMENTS; ++i) {
        printf("%d\n", array[i]);
    }
    puts("");
} // End printStandArray()

/*******************************************************************************
    Function: printNonDupArray()
    Description: Prints an array and skips over any value that == 0
    Parameters: Any array
    Return: ---
*******************************************************************************/
void printNonDupArray(int array[ELEMENTS]) {
    for (size_t i = 0; i < ELEMENTS; ++i) {
        if (array[i] != 0) {
            printf("%d\n", array[i]); 
        }        
    }
    puts("");
} // End printNonDupArray()

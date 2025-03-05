/*******************************************************************************

                     // Passing Functions into Functions //

    This program is an example in the text, though I took liberty to implement
    functional decomposition, subsequently creating new functions for sport.
    I also opted to use a switch statement as well for user selection, so that a 
    user could navigate between function options and opt to remain in a loop until 
    physically opting out.     

    Written by: Orphaelius

    Date: 02/24/2025

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

// Function Prototypes //
void bubbleSort(int work[], size_t size, int(*compare)(int a, int b));
int ascendingSort(int a, int b);
int descendingSort(int a, int b);
void randomizeArray(int array[SIZE]); 
int getKey(int* key);
void displayInstructions();
void printArray(int array[SIZE]);

/*******************************************************************************
    Function: main()
    Description: Takes user input, process, prints output..
    Parameters: ---
    Return: ---
*******************************************************************************/
int main(void) {
    int randomArray[SIZE] = { 0 };
    int key = 0;

    displayInstructions();
    printf("Enter your choice: ");
    
    while ((key = getKey(&key)) != -1) { 

        switch (key) {
        case 1:
            randomizeArray(randomArray);
            printf("Here is the random array:\n");
            printArray(randomArray);
            break;

        case 2:
            printf("Sorting in ascending order...\n");
            bubbleSort(randomArray, SIZE, ascendingSort);
            printf("Final array: \n");
            printArray(randomArray);
            break;

        case 3:
            printf("Sorting in descending order...\n");
            bubbleSort(randomArray, SIZE, descendingSort);
            printf("Final array: \n");
            printArray(randomArray);
            break;

        default:
            printf("How did you get here...\n");
        }
        displayInstructions();  
        printf("Enter your choice: ");

    }
    
    return 0;
} // End main()

/*******************************************************************************
    Function: displayInstructions()
    Description: It does that^
    Parameters: ---
    Return: ---
*******************************************************************************/
void displayInstructions() {
    printf("%s %s %s %s", "Enter (1) to randomize an array of 30 elements.\n",
        "Afterwards, enter (2) to sort the elements in ascending order or", 
        "(3) to sort the elements in descending order.\n", 
        "Enter (-1) to exit the program.\n\n");
    
} // End displayInstructions()

/*******************************************************************************
    Function: randomizeArray()
    Description: uses srand() to randomize an array of SIZE elements
    Parameters: any one-dimensional array
    Return: ---
*******************************************************************************/
void randomizeArray(int array[SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) { 
        array[i] = rand() % 99 + 1; 
    }
} // End randomizeArray()

int getKey(int* key) {
    scanf("%d", key);
    return *key;
} // end getKey()

/*******************************************************************************
    Function: bubbleSort()
    Description: Uses a pointer to a function to bubble sort a passed array.
    Parameters: one-dimensional array, size of array, and points to a function
    (*compare) that essentially organizes the array
    Return: ---
*******************************************************************************/
void bubbleSort(int work[], size_t size, int(*compare)(int a, int b)) {
    void swap(int* element1Ptr, int* element2Ptr); // Prototype within bubbleSort()!

    // Loop to control passs
    for (int pass = 1; pass < size; ++pass) {
        // Loop to control number of comparisons per pass
        for (size_t count = 0; count < size - 1; ++count) {
            // If adjacent elements are out of order, swap them!
            if ((*compare)(work[count], work[count + 1])) {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
} // End bubbleSort()

/*******************************************************************************
    Function: swap()
    Description: Swaps elements in an array
    Parameters: pointers to those elements
    Return: ---
*******************************************************************************/
void swap(int* element1Ptr, int* element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold; 
} // End swap()

/*******************************************************************************
    Function: ascendingSort()
    Description: Sorts a one-dimensional array in ascending order
    Parameters: two elements
    Return: elements swapped
*******************************************************************************/
int ascendingSort(int a, int b) {
    return b < a; // Should swap if b is less than a (wow)
} // End ascendingSort()

/*******************************************************************************
    Function: descendingSort()
    Description: Sorts a one-dimensional array in ascending order
    Parameters: two elements
    Return: elements swapped
*******************************************************************************/
int descendingSort(int a, int b) {
    return b > a; // Should return if b is greater than a
} // End descendingSort()

// Prints array
void printArray(int array[SIZE]) {
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    puts("");
} // End printArray()
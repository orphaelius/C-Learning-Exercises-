// Intersection of Sets //

/* This program uses one-dimensional arrays to read in two
* sets of numbers, each with 10 numbers, and displays the
* unique elements common to both sets of numbers.
*
*		Written by: Orphaelius
*		Date: February 1, 2025
*/

#include <stdio.h>
#define SIZE 3

// Function prototypes
void fillArray(int arr[], size_t size);
int commonElements(int arr1[], int arr2[], int commonArr[], size_t size);
void printArray(int arr[], size_t size);

int main(void) {	
	size_t size = SIZE; // Variable to represent SIZE
	int arr1[SIZE] = { 0 }; // Array 1
	int arr2[SIZE] = { 0 }; // Array 2
	int commonArr[SIZE * 2] = { 0 }; // Common Array to store common elements

	printf("Fill the first array:\n");
	fillArray(arr1, size); // Function call to fill first array

	printf("Fill the second array:\n");
	fillArray(arr2, size); // Function call to fill second array

	int commonCount = commonElements(arr1, arr2, commonArr, size); // commonCount is a dynamic "size" of commonArr
	printf("The common elements from both arrays are:\n");	
	printArray(commonArr, commonCount); // Print the common elements

	return 0;

} // End main function

void fillArray(int arr[], size_t size) { // Fill array function. Takes user input, fills array.
	for (size_t i = 0; i < size; ++i) {
		printf("Enter element %zu: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

int commonElements(int arr1[], int arr2[], int commonArr[], size_t size) { // Determines common elements
	int commonCount = 0; // Dynamically calculates elements in array
	
	for (size_t i = 0; i < size; ++i) { // Outer loop to cycle through arr1
		int isCommon = 0; // Essentially a flag!

		// Inner loop to cycle through second array
		// Checks each iterative element of arr2 against the current [i] element of arr1
		for (size_t j = 0; j < size; ++j) { 
			if (arr2[j] == arr1[i]) {
				isCommon = 1;
				break; // If it is a common element, break and enter statement below
			}
		}

		// Add common element to commonArr, add 1 to commonCount (to increase size of commonArr)
		if (isCommon) {
			commonArr[commonCount++] = arr2[i]; 
		}
	}
	return commonCount; // Returns total elements for commonArr (determines "size" of array)
}

void printArray(int arr[], size_t size) { // Prints an array.
	for (size_t i = 0; i < size; ++i) {
		printf("%d\n", arr[i]);
	}
}
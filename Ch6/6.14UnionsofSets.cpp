// 6.14 Union of Sets //

/*
Use a one-dimensional array to solve the following problem.
Read in two sets of numbers, each having 10 numbers. After
reading all values, display all the unique elements in the
collection of both sets of numbers. Use the smallest possible 
array to solve this problem
*/

#include <stdio.h>
#define ARBLEN 10

// Function prototypes
int fillArray(int arr[], size_t size); 
int uniqueElements(int arr1[], int arr2[], int uniqueArr[], size_t size); 
int printElements(int arr1[], int arr2[], size_t size);

int main(void) {
	int arr1[ARBLEN] = { 0 }; // First array
	int arr2[ARBLEN] = { 0 }; // Second array
	int uniqueArr[ARBLEN * 2] = { 0 }; // Final array to store unique values
	size_t size = ARBLEN; 

	printf("Fill the first array:\n"); // Fill arr1
	fillArray(arr1, size);	  

	printf("Fill the second array:\n"); // Fill arr2
	fillArray(arr2, size);	 

	int uniqueCount = uniqueElements(arr1, arr2, uniqueArr, size); // 

	printf("The unique elements from both arrays are:\n");
	printElements(uniqueArr, uniqueCount);  

	return 0;
	
}

// Function to fill an array
int fillArray(int arr[], size_t size) { 
	for (size_t i = 0; i < size; ++i) {
		printf("Enter element %zu: ", i +1);
		scanf("%d", &arr[i]); 
	}

	return 0;
}

int uniqueElements(int arr1[], int arr2[], int uniqueArr[], size_t size) {
	int uniqueCount = 0;

	// Copies arr1 elements
	for (size_t i = 0; i < size; ++i) {
		uniqueArr[uniqueCount++] = arr1[i]; 
	}

	for (size_t i = 0; i < size; ++i) {
		int isUnique = 1;
		for (size_t j = 0; j < size; ++j) {
			if (arr2[i] == arr1[j]) {
				isUnique = 0;
				break;
			}
		}

		if (isUnique) {
			uniqueArr[uniqueCount++] = arr2[i];
		}
	}

	/*
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			if (arr1[i] == arr2[j]) {
				arr2[j] = 0;
				arr1[i] = 0;
			}
	}
	*/

	return uniqueCount; 
} 

int printElements(int arr[], size_t size) { 
	for (int i = 0; i < size; ++i) { // Print any non-zero elements
		 
		if (arr[i] != 0) {
			printf("%16d\n", arr[i]); 
		}
	}

	return 0;
}
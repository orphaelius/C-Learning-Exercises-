// Selection Sort //

#include <stdio.h>
#define SIZE 10
int arr[SIZE] = { 13, 34, 1, 24, 65, 75, 12, 44, 56, 99 };
int bubbleSort(int arr[]);

int main(void) {

	int smallestVal = arr[0];

	for (size_t pass = 1; pass < SIZE; ++pass) { // Find smallest value
		for (size_t i = 0; i < SIZE; ++i) {
			 
			if (arr[i] < smallestVal) {			 	
				arr[i] = arr[0];
				smallestVal = arr[i]; 
			}
			
		}
	}
	/*
	for (size_t pass = 1; pass < SIZE; ++pass) { // Find smallest value
		for (size_t i = 0; i < SIZE - 1; ++i) {
			if (arr[i] < smallestVal) { 				 
				smallestVal = arr[i];				
			}			
		}		
	}
	*/
	
	//printf("%d smallest\n", smallestVal);

	for (size_t i = 0; i < SIZE; ++i) {
		printf("%d\n", arr[i]);
	}
}



int bubbleSort(int arr[]) {
	// bubble sorting
	for (size_t pass = 1; pass < SIZE; ++pass) {

		for (size_t i = 0; i < SIZE - 1; ++i) {
			int largerVal = 0;
			if (arr[i] > arr[i + 1]) {
				largerVal = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = largerVal;
			}
		}

	}

	return 0;
}
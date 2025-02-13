#include <stdio.h>
#define SIZEL 100
#define SIZEB 15

/*
// Linear search of an array //

// function prototype
int linearSearch(const int array[], int key, size_t size);

// function main begins program execution
int main(void) {
	int a[SIZEL] = { 0 }; // create array 'a' and intitialize the contents to 0

	// create data
	for (size_t x = 0; x < SIZEL; ++x) {
		a[x] = 2 * x; 
	}

	printf("Enter integer search key: ");
	int searchKey = 0; // key value to locate in array a
	scanf("%d", &searchKey);

	// attempt to locate searchKey in array a
	int subscript = linearSearch(a, searchKey, SIZEL);

	// display results
	if (subscript != -1) {
		printf("Found value at subscript %d\n", subscript);
	}
	else {
		puts("Value not found.");
	}
}

/* compare key to every element of array until the location is found 
or until the end of array is reached; return subscript of element if
key is found or -1 if key is not found. 
int linearSearch(const int array[], int key, size_t size) {
	// loop through array
	for (size_t n = 0; n < SIZEL; ++n) {
		if (array[n] == key) {
			return n;
		}
	}
	return -1;
}

*/





// Binary search of a SORTED array //

int binarySearch(const int b[], int key, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

int main(void) {
	int a[SIZEB] = { 0 };

	// create data
	for (size_t i = 0; i < SIZEB; ++i) {
		a[i] = 2 * i;
	}

	printf("%s", "Enter a number between 0 and 28: ");
	int key = 0;
	scanf("%d", &key);

	printHeader();

	// search for key in array a
	int result = binarySearch(a, key, 0, SIZEB - 1);

	// display results
	if (result != -1) {
		printf("\n%d found at subscript %d\n", key, result);
	}
	else {
		printf("\n%d not found\n", key);
	}
}

// function to perform binary search of an array
int binarySearch(const int b[], int key, size_t low, size_t high) {
	// loop until low subscript is greater than high subscript
	while (low <= high) {
		size_t middle = (low + high) / 2;

		// display subarray used in this loop iteration
		printRow(b, low, middle, high);

		// if key matches, return middle subscript
		if (key == b[middle]) {
			return middle;
		} 
		else if (key < b[middle]) { // if key < b[middle], adjust high
			high = middle - 1; // next iteration searches high end of array
		}
		else { // key > b[middle], so adjust low
			low = middle + 1; // the next iteration searches high end of array
		}
	}

	return -1;
}

// print a header for the output
void printHeader(void) {

	puts("\nSubscripts:");

	// output column head
	for (int i = 0; i < SIZEB; ++i) {
		printf("%3d ", i);
	}

	puts(""); // start new line of output

	// output line of - characters
	for (int i = 1; i <= 4 * SIZEB; ++i) {
		printf("%s", "-");
	}

	puts(""); // start new line of output
}

// print one row of output showing the current
// part of the array being processed
void printRow(const int b[], size_t low, size_t mid, size_t high) {

	// loop through entire array
	for (size_t i = 0; i < SIZEB; ++i) {

		// displays spaces if outside current subarray range
		if (i < low || i > high) {
			printf("%s", "   ");
		}

		else if (i == mid) { // display middle element
			printf("%3d*", b[i]); // mark middle value
		}
		else {
			printf("%3d ", b[i]); // display other elements in subarray normally
		}
	}

	puts("");
}
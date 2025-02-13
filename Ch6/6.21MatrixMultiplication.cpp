// Matrix Multiplication //

/* This program multiplies 2 two-dimensional
   matrices and stores the result in a third
   matrix 
   
   Written by: Orphaelius
   Date: 02/25 */

#include <stdio.h>
#define ROWS 3
#define COLUMNS 3

int fillMatrix(int matrix[ROWS][COLUMNS]); 
int matrixMultiplication(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], 
						 int resultMatrix[ROWS][COLUMNS]);
void printMatrix(int matrix[ROWS][COLUMNS]); 

int main(void) {
	int firstMatrix[ROWS][COLUMNS] = { 0 };
	int secondMatrix[ROWS][COLUMNS] = { 0 };
	int resultMatrix[ROWS][COLUMNS] = { 0 };	

	printf("Fill your first matrix: \n");
	fillMatrix(firstMatrix); 

	printf("Fill your second matrix: \n");
	fillMatrix(secondMatrix); 

	matrixMultiplication(firstMatrix, secondMatrix, resultMatrix); 

	printf("The result matrix is:\n");
	printMatrix(resultMatrix); 

}

int fillMatrix(int matrix[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; ++i) {
		
		for (int j = 0; j < COLUMNS; ++j) {
			printf("Element at Row %d, Column %d: ", i, j);
			scanf("%d", &matrix[i][j]); 
		}
	}

	return matrix[ROWS][COLUMNS]; 
}

int matrixMultiplication(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], 
						 int resultMatrix[ROWS][COLUMNS]) {

	for (int i = 0; i < ROWS; ++i) {

		for (int j = 0; j < COLUMNS; ++j) {
			resultMatrix[i][j] = 0; 
			for (int m = 0; m < ROWS; ++m) {
				// use m to multiply row and column incrementally, then add that to each row/column for resultMatrix
				// then increment
				resultMatrix[i][j] = resultMatrix[i][j] + (matrix1[i][m] * matrix2[m][j]);
			}
		}
	}

	return resultMatrix[ROWS][COLUMNS];

}

void printMatrix(int matrix[ROWS][COLUMNS]) {
	// would be cool to add a header tabular feature, row 0, etc and print in a neat box
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}
}

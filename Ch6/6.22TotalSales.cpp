// Total Sales //

/* This program uses arrays to track, store, manipulate, and output
   sales data for a 2D array of salespeople and products.

   Written by: Orphaelius
   Date: 02/07/25 */


#include <stdio.h>
#define SALESPERSON 4
#define PRODUCTS 5
#define EOF -1 

void displayDescrip(void);
void printArray(int array[SALESPERSON][PRODUCTS]);
int printSlipsMessage(int slips);
int switchMessage(void);
int printMonthlyDataMessage(int array[SALESPERSON][PRODUCTS]);
int inputLoop(int slipsTracker[SALESPERSON], int sales[SALESPERSON][PRODUCTS],
	int salesSummary[SALESPERSON][PRODUCTS], int* switchKey);
int selectSalesperson(int);
int selectProductNumber(int);
int enterSalesTotal(int);
void addToSalesSummary(int slipsTracker[SALESPERSON], int salesSummary[SALESPERSON][PRODUCTS]);
int trackSlipsRemaining(int slipsTracker[SALESPERSON], int salespersonID);
int getSlipIndex(int indexForSlip);

int main(void) {
	// Initial 2D sales array
	// Rows = salespeople, columns = product IDs
	int sales[SALESPERSON][PRODUCTS] = { { 0, 0, 0, 0, 0 },
										 { 0, 0, 0, 0, 0 },
										 { 0, 0, 0, 0, 0 },
										 { 0, 0, 0, 0, 0 } };

	// Keeps track of cumulative sales data for each 
	// salesperson ("monthly")
	int salesSummary[SALESPERSON][PRODUCTS] = { { 0, 0, 0, 0, 0 },
												{ 0, 0, 0, 0, 0 },
												{ 0, 0, 0, 0, 0 },
												{ 0, 0, 0, 0, 0 } };

	// Each salesperson starts with 5 slips each	
	int slipsTracker[SALESPERSON] = { 5, 5, 5, 5 };
	int switchKey = 0;

	displayDescrip(); // Displays program description
	
	while ((switchKey = switchMessage()) != -1) { // Primary loop 
		
		switch (switchKey) {
		case 0:
			addToSalesSummary(slipsTracker, salesSummary);
			break;

		case 1:
			printMonthlyDataMessage(salesSummary);
			//printArray(salesSummary);
			break;

		case '\n':
			break;

		case '\t':
			break;

		default:
			break;
		}
	}

} // END MAIN

void displayDescrip(void) { // Prints intro description
	puts("This program collects sales data for 4 salespeople.");
	puts("You may enter data for up to 5 slips per salesperson.");
} 

int switchMessage(void) { // Iterates message in SWITCH statement, returns SWITCHKEY
	int switchKey = 0;
	printf("Enter (0) to input sales data, (1) to view monthly sales report, or (-1) to exit: ");
	scanf("%d", &switchKey);
	return switchKey;
}

// Takes user input to determine salesperson ID
int selectSalesperson(int) {
	int salespersonID = 0; 
	printf("Enter the salesperson ID (1-4): ");
	scanf("%d", &salespersonID); 	
	salespersonID--;
	return salespersonID;  
}

// Takes user input to determine product ID
int selectProductNumber(int) {
	int productID = 0;
	printf("Enter the product ID (1-5): ");
	scanf("%d", &productID); 
	productID--;
	return productID;  
}

// Takes user input for total sales of a specific salesperson and product 
int enterSalesTotal(int) {
	int salesTotal = 0;
	printf("Enter the total sales for this product: ");
	scanf("%d", &salesTotal);
	return salesTotal;
}

// Meat of program, really. Takes all values from user input and keeps track
// of sales data per salesperson. This is a cumulative value per each
// salesperson. Determines if a the max slips have been entered per
// salesperson. 
void addToSalesSummary(int slipsTracker[SALESPERSON], int salesSummary[SALESPERSON][PRODUCTS]) {

	int salespersonID = 0;
	int productID = 0;
	int salesTotal = 0;

	salespersonID = selectSalesperson(salespersonID);
	productID = selectProductNumber(productID);
	salesTotal = enterSalesTotal(salesTotal);

	if (trackSlipsRemaining(slipsTracker, salespersonID) > 0) {
		salesSummary[salespersonID][productID] += salesTotal;
	}	
}

// Function to track slips remaining per each salesperson
int trackSlipsRemaining(int slipsTracker[SALESPERSON], int salespersonID) {

	if (slipsTracker[salespersonID] > 0) {
		slipsTracker[salespersonID]--;
	}
	else {
		printf("This salesperson has reached their limit.\n");
	}

	return slipsTracker[salespersonID];
}


int printMonthlyDataMessage(int array[SALESPERSON][PRODUCTS]) {
	printf("\n%68s", "----- MONTHLY REPORT -----\n\n");

	for (int i = 0; i < SALESPERSON; i++) {
		printf("Salesperson %d ", i + 1);

	}
	puts("");	

	for (int i = 0; i < PRODUCTS; ++i) {
		printf("Prod ID %d", i + 1);
		for (int j = 0; j < SALESPERSON; ++j) {
			printf("%15d", array[j][i]);
		}
		puts("");
	}
	puts("");
	return 0;
}

void printArray(int array[SALESPERSON][PRODUCTS]) {
	for (int i = 0; i < SALESPERSON; ++i) {
		printf("Salesperson %d: ", i + 1);
		for (int j = 0; j < PRODUCTS; ++j) {
			printf("%d ", array[i][j]);
		}
		puts("");
	}
}
#include <stdio.h>
#include <math.h>

// Calculating Sales //

/* an online retailer sells five different products (prices printed in book 
displayed below):
*				product number		retail price
*				1					2.98
*				2					4.50
*				3					9.98
*				4					4.49
*				5					6.87
* 
* write a program that reads a series of pairs of numbers as follows:
*	a) product number
*	b) quantity sold for one day
* 
* the program should use the switch statement to help determine the
* retail pice for each product. your program should calculate and 
* display the total retail value of all products sold last week.
*/

int main(void) {

	// variables for storing the total counts of each product
	int product_count1 = 0;
	int product_count2 = 0;
	int product_count3 = 0;
	int product_count4 = 0;
	int product_count5 = 0;

	// variables for summing total counts of each product by their price
	double sum_prod1 = 0.0;
	double sum_prod2 = 0.0;
	double sum_prod3 = 0.0;
	double sum_prod4 = 0.0;
	double sum_prod5 = 0.0;

	// variable for taking user input (of product codes)
	int product_code = 0;

	printf("This program calculates the total sum of sales for each product in a system.\n");
	printf("Enter the product code of a sold item, press EOF character to end input: \n");

	// while loop, used to iterate through each switch case until EOF character is initialized
	while ((product_code = getchar()) != EOF) { 

		switch (product_code) {
			case '1': 
				++product_count1;
				break; 

			case '2':
				++product_count2;
				break;

			case '3':
				++product_count3;
				break;

			case '4':
				++product_count4;
				break;

			case '5':
				++product_count5;
				break; 

			case '\n':
			case '\t':
			case ' ':
				break;

			default:
				printf("%s", "That is not a valid product code...");
				printf(" Enter your product code: \n");
				break;
		}

		// increases sum aka total sales for each product code entered multiplied by its cost
		sum_prod1 = product_count1 * 2.98;
		sum_prod2 = product_count2 * 4.50;
		sum_prod3 = product_count3 * 9.98;
		sum_prod4 = product_count4 * 4.49;
		sum_prod5 = product_count5 * 6.87;

	}

	// header for printing the sales in columns
	printf("Product 1 %10s Product 2 %10s Product 3 %10s Product 4 %10s Product 5\n\n\n", "", "", "", "");

	// not sure how to modify spacing to accommodate using extra spaces in values yet! 
	printf("%.2f %15s %.2f %15s %.2f %15s %.2f %15s %.2f", sum_prod1, "", sum_prod2, "", sum_prod3, "", sum_prod4, "", sum_prod5);

}

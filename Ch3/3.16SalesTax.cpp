#include <stdio.h>

/*
Sales Tax

Sales tax is collected from buyers and remitted to the government. A retailer must file a monthly sales tax report that lists the sales for the month and 
the amount of sales tax collected, at both the county and state levels. Develop a program that will input the total collections for a month, 
calculate the sales tax on the collections, and display the county and state taxes. Assume that the states have a 4% sales tax and 
counties have a 5% sales tax. 

sample input/output dialog:
enter total amount collected (-1 to quit): (enter value, ie 45698)
enter name of month: january
total collections: $45698.00
sales: $41,906.42
county sales tax: $2095.32
state sales tax: $1676.26

*/

// initialize function
// initialize variables total_amount_collected, month, sales, county_tax, and state_tax
// display input message, include sentinel value, scan for user input, store user input
int main(void) {

	int total_revenue = 0;
	char month[10];
	int sales = 0;
	int county_tax = 0;
	int state_tax = 0;

	printf("%s", "Please enter the current month: \n");
	scanf("%10s", &month);

	printf("%s", "Please enter the total revenue for the month: \n");
	scanf("%d", &total_revenue);

	printf("%s", "Please enter the total taxable sales for the month: \n");
	scanf("%d", &sales);

	// processing 
	county_tax = sales * .05;
	state_tax = sales * .04;
	
	// termination
	printf("Name of month: %s\n", month);
	printf("Total revenue: %d\n", total_revenue);
	printf("Total sales: %d\n", sales);
	printf("Total County Sales Tax owed: %d\n", county_tax);
	printf("Total State Sales Tax owed: %d\n", state_tax);
		
	}
	

	




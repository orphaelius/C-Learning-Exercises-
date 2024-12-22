#include <stdio.h>

/* a large chemical company pays its sales people on a commission basis. The salespeople receive $200 per week plus 9% of their gross sales
* for that week. for example, a salesperson who sells $5,000 worth of chemicals in a week received $200 plus 9% of $5,000, or a total of $650.
* develop a program that will use scanf to input each salesperson's gross sales for last week and calculate and display that salesperson's earnings. 
* process one salsperson's figures at a time.
*/
 

int main(void) {
	// initialize variables
	int weekly_pay = 200;
	float gross_sales = 0;
	float commission = 0;
	float total_pay = 0;

	// display message/ask for input, take input, store input
	// create while loop, add sentinel value of -1
	// display total pay for salesperson
	// iterate until sentinel value is entered
	printf("%s", "Enter your total gross sales for last week and I will calculate your total pay (enter '-1' to exit): \n");
	
	while (gross_sales != -1) {
		scanf("%f", &gross_sales);
		commission = gross_sales * .09;
		total_pay = weekly_pay + commission;		

		if (gross_sales == -1) {
			break;
		}
		printf("Your total pay for this week is %f.\n", total_pay);
		printf("%s", "Enter your total gross sales for last week and I will calculate your total pay (enter '-1' to exit): \n");		
	}	
	return 0;		
}

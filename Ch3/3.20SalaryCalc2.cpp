#include <stdio.h>

/* Develop a program that will determine the gross pay for each of several employees. The company pays 'straight time' for the first
* 40 hours worked by each employee and pays 'time-and-a-half' for all hours worked in excess of 40 hours. you're given a list of the company's
* employees, the numbers of hours each worked last week, and each employee's hourly rate. Your program should use scanf to input this information
* for each employee and determine and display the employee's gross pay. 
*/


int main(void) {

	// initialize variables: hours worked, full time hour count, base hourly pay, overtime hours worked, overtime pay, total pay
	float normal_pay = 0; // base hourly * 40 (add to loop?)
	float base_hourly = 0; // need input from user
	int hours_worked =  0; // need input from user	

	int overtime_hours = 0; // hours_worked - 40
	float overtime_pay; // if > 40, 40 - overtime hours, base hourly * 1.5

	float total_pay = 0; // overtime pay + normal pay

	char employee_name[14]; // added for fun

	// display initial promp/ask for input, take input, store input
	// create while loop, add sentinel value of -1
	// calculate overtime pay
	// calculate total pay (full time pay + overtime pay)
	// display message of pay details
	// iterate until sentinel value is entered
	// if hours worked > 40, calculate overtime, else print hours worked * hourly pay
	printf("%s", "Enter the number of hours worked (enter '-1' to exit): \n");

	// while statement to cycle input, data, calcs, and display
	while (1) {

		// initial input of hours worked
		scanf("%d", &hours_worked); 

		if (hours_worked == -1) { // break statement, use sentinel value to break
			break;
		}
		
		// prompt and take more input
		printf("Enter the hourly rate of the employee: \n");
		scanf("%f", &base_hourly);
		printf("Enter the employee's name: \n");
		scanf("%s", employee_name);

		// if statement for overtime calculations
		if (hours_worked > 40) {
			normal_pay = 40 * base_hourly; 
			overtime_hours = hours_worked - 40;
			overtime_pay = (base_hourly * 1.5) * overtime_hours; 
			total_pay = overtime_pay + normal_pay;
			printf("%s worked: %d hours\n", employee_name, hours_worked); 
			printf("The hourly rate for %s is: $%.2f\n", employee_name, base_hourly);
			printf("%s's total pay for this pay period is: $%.2f\n", employee_name, total_pay);
		}

		// else statement for normal pay
		else {
			normal_pay = hours_worked * base_hourly;
			printf("%s did not work any overtime. Their pay for this period is: $%.2f\n", employee_name, normal_pay); 
		}		

		// re-iterate prompt message to user
		printf("%s", "Enter the number of hours worked: (enter '-1' to exit): \n");

	}
	return 0;
}

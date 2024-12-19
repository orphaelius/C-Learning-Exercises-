#include <stdio.h>
#include <math.h>

// Calculating Weekly Pay //

/* a company pays its employees as managers (who receive a fixed
weekly salary), hourly workers (who receive a fixed hourly wage
for up to the first 40 hours they work and 1.5 times for overtime
hours worked), commission workers (who receive 250 plus 5.7% of 
their gross weekly sales), or piece-workers (who receive a fixed 
amount of money for each of the items they produce- each pieceworker
in this company works on only one type of item). write a program
to compute each employee's weekly pay. you do not know the number
of employees in advance. each type of employee has a pay code: 
managers are paycode 1, hourly have paycode 2, commission have 
paycode 3, and pieceworkers have paycode 4. use a switch to compute
each employee's pay based on the paycode. within the switch, prompt 
the user to enter the appropriate facts your program needs to 
calculate each employee's pay based on that employee's paycode.*/

int main(void) {

	double managerSalary = 0.0; // enter manager's weekly salary

	double hourlyWage = 0.0; // enter hourly wages
	double hoursWorked = 0.0;	 
	
	double overtimeHours = 0.0; // for code2   
	double overtimePay = 0.0;

	double pieceWage = 0.0; // enter amount piece worker gets per single piece
	double piecesProduced = 0.0; // enter how many ^ produced
	
	double totalSales = 0.0; // commission sales, multiply by 5.7% for code3
	double commissionBase = 250.0; // for code3

	double tempWeeklyPay = 0.0; //  	
		
	puts("This program determines weekly pay for employee's via their respective paycodes.");
	puts("The employee paycodes are 1 for manager, 2 for hourly, 3 for commission, and 4 for pieceworker.");
	printf("You may re-enter paycodes until you choose to exit the program.\n\n");
	puts("Enter the employee's pay code: ");
	puts("Enter the EOF character to exit.");
	
	int paycode = 0; // switch variable

	while ((paycode = getchar()) != EOF) {				
		
		switch (paycode) {			

		case '1':
			puts("Enter the manager's salary: ");
			scanf("%lf", &managerSalary);
			printf("This manager's weekly pay is: %.2f\n", managerSalary);
			break;

		case '2':
			puts("First enter the employee's hourly wage: ");
			scanf("%lf", &hourlyWage);
			puts("Now enter the employee's total weekly hours worked: ");
			scanf("%lf", &hoursWorked);
			if (hoursWorked > 40) {
				overtimeHours = hoursWorked - 40;
				overtimePay = 1.5 * overtimeHours;
				tempWeeklyPay = overtimePay + (40 * hourlyWage);
			}
			else {
				tempWeeklyPay = hourlyWage * hoursWorked;
			}			
			printf("This hourly employee's pay for the week is: %.2f\n", tempWeeklyPay);
			break;

		case '3':
			puts("Enter the amount of items this employee produced this week: ");
			scanf("%lf", &piecesProduced);
			puts("Now enter the pay per item produced: ");
			scanf("%lf", &pieceWage);

			tempWeeklyPay = piecesProduced * pieceWage;
			printf("This pieceworker's pay for the week is: %.2f\n", tempWeeklyPay);
			break;

		case '4':
			puts("Enter the total weekly sales for this employee: ");
			scanf("%lf", &totalSales);
			tempWeeklyPay = commissionBase + (totalSales * .057);
			printf("This commission worker's pay for the week is: %.2f\n", tempWeeklyPay);
			break;

		case '\n':
		case '\t':
		case ' ':
			break;

		default:
			printf("%s", "Incorrect paycode has been entered.\n"); 
			printf("Enter a new paycode: \n");  
			break;
		}
		
	}

	return 0;
}
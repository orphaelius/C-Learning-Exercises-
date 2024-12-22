#include <stdio.h>

// Car Rental Service //

/* a car rental service charges a minimum fee of $25
to rent a car for 8 hours and charges an additinoal $5 
per hour after 8 hours. the maximum charge per day is 
$50, exclusive of service tax. the company charges an 
additional $0.50 per hour as service tax. assume that
no car is rented for more than 72 hours at a time. if 
a car is rented for more than 24 hours, then rent is 
calculated on a per-day basis.

write a program that calculates and prints the rental 
charges for each of the three customers who rented cars 
from this agency yesterday. you should enter the hours 
for which the car has been rented for each customer. 
your program should print the results in a tabular 
format and should calculate and print the total of 
yesterday's receipts. the program should use the 
function 'calculateCharges' to determine the charges
for each customer. your outputs should appear as follows:

Car		Hours		Charge
1		12			56.00
2		34			117.00
3		48			124.00
TOTAL	94			297.00 */
 
float calculateCharges(int hours); // $5 * hours > 8 && * hours < 24

int hours = 0; // For input value and function argument
int cars = 3; // Total quantity of cars. modular to add or subtract if necessary.

int main(void) { 

	printf("%s %10s %10s\n\n", "Vehicle", "Hours", "Charge"); // Prints header for tabular output

	for (int i = 1; i <= cars; i++) { // Loops through user input/printing results 
		printf("Please enter the hours for Car %d: \n", i); 
		scanf("%d", &hours);
		printf("Car %-8d %-9d $%f\n\n", i, hours, calculateCharges(hours)); 		
	}	
}

float calculateCharges(int hours) { // function to calculate charges

	float byTheHourCharge; // For any rental under 24 hours
	float serviceCharge = hours * 0.5; // Calculates service charge per rental
	float tempHours; // Calculates hourly charge for rentals over 8 hours and below 24 hours
	int totalCharge = 0; // Sums total charges, used as return 

	if (hours <= 8) { // For any rental less than or equal to minimum amount
		totalCharge = serviceCharge + 25;
		return totalCharge;    
	}

	if (hours > 8 && hours < 24) { // For any rental below full day and above min
		tempHours = hours - 8;
		byTheHourCharge = (tempHours * 5);    
		totalCharge = byTheHourCharge + serviceCharge + 25; 
		return totalCharge;
	}

	if (hours >= 24 && hours < 48) { 
		totalCharge = serviceCharge + 50; 
		return totalCharge;
	}

	if (hours >= 48 && hours < 72) {
		totalCharge = serviceCharge + 100;
		return totalCharge;
	}

	if (hours == 72) {
		totalCharge = serviceCharge + 150;
		return totalCharge;
	}

	if (hours <= 0 || hours > 72) { // Edge cases
		printf("Incorrect information entered...\n");
		return 0;
	}
}





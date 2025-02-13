#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SALARIES 30
#define RANGES 9

// Sales Commissions //

void salaryCounts(int weeklySalaries, int salaryRangeCounts[]);

int main(void) {
	// Array to hold salary ranges
	const char *salaryRanges[] = { "200-299", "300-399", "400-499", 
								   "500-599", "600-699", "700-799", 
								   "800-899", "900-999", "1000+"};

	// Arry to store range counts
	int salaryRangeCounts[RANGES] = { 0 };    


	// int salaryRangesLength = sizeof(salaryRanges) / sizeof(salaryRanges[0]); // Array length for loops
	int weeklySalaries[SALARIES ] = { 0 }; // Array to store randomized weekly salaries of 30 salespeople 
	int salespersonCommission = 0; // Determines weekly commission for salesperson
	
	srand(time(NULL));  

	for (size_t i = 0; i < SALARIES; ++i) {
		// Limits rand(). Controlling after majority of max salaries were above 1000
		// This control llows for a more even distribution. 
		salespersonCommission = rand() % 10000; 

		// Uses random number from above to calculate commission for that salesperson
		weeklySalaries[i] = (salespersonCommission * .09) + 200; 

		salaryCounts(weeklySalaries[i], salaryRangeCounts); 

	}
	
	printf("%s%40s\n", "Salary Range", "Total Salespeople In This Range"); // Print header

	// Print Salary Ranges in tabular output
	for (size_t i = 0; i < RANGES; ++i) {       
		printf("%12s%40d\n", salaryRanges[i], salaryRangeCounts[i]); 
	}
	
	return 0;

} // End main
 
// Pushed counting mechanism to a seperate function to clear space
void salaryCounts(int weeklySalaries, int salaryRangeCounts[]) {
	if (weeklySalaries < 300) {
		salaryRangeCounts[0]++;
	}
	else if (weeklySalaries < 400) {
		salaryRangeCounts[1]++;
	}
	else if (weeklySalaries < 500) {
		salaryRangeCounts[2]++;
	}
	else if (weeklySalaries < 600) {
		salaryRangeCounts[3]++;
	}
	else if (weeklySalaries < 700) {
		salaryRangeCounts[4]++;
	}
	else if (weeklySalaries < 800) {
		salaryRangeCounts[5]++;
	}
	else if (weeklySalaries < 900) {
		salaryRangeCounts[6]++;
	}
	else if (weeklySalaries < 1000) {
		salaryRangeCounts[7]++;
	}
	else {
		salaryRangeCounts[8]++;
	}
}


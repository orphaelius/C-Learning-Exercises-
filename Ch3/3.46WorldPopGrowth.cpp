#include <stdio.h>
#include <math.h>


// World Population Growth //



// *** project assignment *** //

/* research world population growths
* investigate various viewpoints
* get estimates for current world population and growth rate
* write a program that calculates the world population each year for the next 100 years, assuming that growth rate will remain constant 
* print the results in a table.
* first column should dislay the year from 1 to 100
* second column should display te anticipated world population at the end of that year
* the third column should display the numerical increase in the world population that will occur in that year
* using the results, determine the years in which the population would become double or eventually quadruple what it is today
*/

/* pseudocode
* 
* use two models? compare?
* p(t) = p e ^r t, where p equals starting population, r equals rate, and t equals time
* 
* initialize function
* 
* initialize variables 
* 
* outer loop/main loop 
* prints table 1
* print year n 1 through 100
* 
* nested loop 1 
* prints table 2
* print anticipated world population growth at the end of n year
* 
* nested loop 2
* prints table 3
* display the numerical increase in the world population during current n year
* 
* lower outer loop
* pop growth algorithm 
* 
* outside loop
* calculate which years the population is 2x or 4x
* print ^
* 
*/

int main(void) {
	double population_start = 8.2; // (in billions,add to statements)
	double population_updated = 1.0; 
	double e = 2.71828;
	double rate = 0.0087; 
	double e_power_r = 1.008737;
	double time = 0; 
	int counter = 1;
	//int counter2 = 1; 
	int counter3 = 1;
	double sum = 0.0;
	double exponent = 1;
	double temp_sum = 0;
	double power = 0;
	
	// p(t) = p e ^r t, where p equals starting population, r equals rate, and t equals time
	// 8,200,000,000

	printf("Years\t\t\t\t Estimated World Population (in billions) \t Numerical Increase\n\n");

	while (counter <= 3) {				

		// loop to print columns
		while (time <= 10) {			
			  
			printf("%lf\t\t\t\t    %lf\t\t\t\t\t\t %lf\n", time, population_updated, time);   

			time++;

			//population_updated = population_start * (e_power_r * time); 
			//sum += population_updated; 
		}

		while (counter3 <= 10) {
			// needs to be 2.71828 to the power of .0087 times time, which increments
			exponent = rate * counter3;
			power = pow(e, rate);
			//temp_sum =
			//sum += temp_sum;
			//e_power_r = time * 1.008737; 
			printf("rate is %lf\n", exponent);
			printf("current helllollalskdfjlkj power value is %lf\n", power);   
			counter3++; 
			
		}	
		
		counter++; 
		
	}
	
	return 0;

}

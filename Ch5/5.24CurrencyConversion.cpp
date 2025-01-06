#include <stdio.h>

// Current Conversion //

/* implement the following double functions:
a) function toYen takes an amount in USD and
returns the yen equivalent
b) function toEuro " "
c) use these functions to write a program that
prints charts showing the yen and euro equivalents
for a range of usd. print the outputs in a neat
tabular format. use the exchange rates:
1 usd = 118.87 yen
1 usd = 0.92 euro */

float toYen(float usd); 
float toEuro(float usd);
float conversionTable(float usd);
float usd = 0; 
char label; 

int main(void) {
	printf("This program converts USD to Yen and Euro or prints a table of common conversions.\n");
	printf("Enter 'A' to convert to Yen, 'B' to convert to Euro, or 'C' to view the conversion table:\n");

	while ((label = getchar()) != EOF) {

		switch (label) {

		case 'A': // Yen
		case 'a':
			printf("Enter any USD amount below 2 billion dollars and I will convert it to Yen:\n");
			scanf("%fl", &usd); 
			toYen(usd);
			break;

		case 'B': // Euro
		case 'b':
			printf("Enter any USD amount below 2 billion dollars and I will convert it to Euro:\n"); 
			scanf("%fl", &usd);
			toEuro(usd); 
			break;
		
		case 'C': // Conversion Table
		case 'c':
			conversionTable(usd);
			break;	
		}
	}	
}

float toYen(float usd) { // Yen conversion function
	float yen = usd * 118.87;
	printf("%f is %.2f Yen.\n", usd, yen);
	return 0;
}

float toEuro(float usd) { // Euro conversion function
	float euro = usd * 0.92;
	printf("%f is %.2f Euro.\n", usd, euro);  
	return 0;
}

float conversionTable(float usd) { // Tabular output 
	
	printf("%-20s %-20s %s\n", "USD", "Yen", "Euro");
	for (int i = 10; i <= 100; i += 10) { // Tens
		float yen = i * 118.87; 
		float euro = i * 0.92;
		printf("%-20.2d %-20.2f %-20.2f\n", i, yen, euro);     
	}
	for (int i = 100; i <= 1000; i += 100) { // Hundreds
		float yen = i * 118.87;
		float euro = i * 0.92;
		printf("%-20.2d %-20.2f %-20.2f\n", i, yen, euro);
	}

	for (int i = 1000; i <= 100000; i += 1000) { // Thousands
		float yen = i * 118.87;
		float euro = i * 0.92;
		printf("%-20.2d %-20.2f %-20.2f\n", i, yen, euro);
	}	
	return 0;
}

	

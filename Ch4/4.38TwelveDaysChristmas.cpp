#include <stdio.h>

// "The Twelve Days of Christmas" Song //

/* write a program that uses iteration and switch statements
to print the song "The Twelve Days of Christmas." one switch
statement should be used to print the day (first day of...)
and a separate switch statement should be used to print the
remainder of each verse */

/* The Song:
* 
* On the first day of Christmas,
my true love gave to me
A partridge in a pear tree.

On the second day of Christmas,
my true love gave to me
Two turtle doves,
And a partridge in a pear tree.

On the third day of Christmas,
my true love gave to me
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the fourth day of Christmas,
my true love gave to me
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the fifth day of Christmas,
my true love gave to me
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the sixth day of Christmas,
my true love gave to me
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the seventh day of Christmas,
my true love gave to me
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the eighth day of Christmas,
my true love gave to me
Eight maids a-milking,
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the ninth day of Christmas,
my true love gave to me
Nine ladies dancing,
Eight maids a-milking,
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the tenth day of Christmas,
my true love gave to me
Ten lords a-leaping,
Nine ladies dancing,
Eight maids a-milking,
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the eleventh day of Christmas,
my true love gave to me
Eleven pipers piping,
Ten lords a-leaping,
Nine ladies dancing,
Eight maids a-milking,
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree.

On the twelfth day of Christmas,
my true love gave to me
Twelve drummers drumming,
Eleven pipers piping,
Ten lords a-leaping,
Nine ladies dancing,
Eight maids a-milking,
Seven swans a-swimming,
Six geese a-laying,
Five golden rings,
Four calling birds,
Three French hens,
Two turtle doves,
And a partridge in a pear tree!

*/


int main(void) {
	
	for (int day = 1; day <= 12; day++) { // loops through 12 "days"

		switch (day) { // prints initial verse for each day

		case 1:
			printf("On the first day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 2:
			printf("On the second day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 3:
			printf("On the third day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 4:
			printf("On the fourth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 5:
			printf("On the fifth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 6:
			printf("On the sixth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 7:
			printf("On the sevnth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 8:
			printf("On the eighth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 9:
			printf("On the ninth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 10:
			printf("On the tenth day of Christmas,\n");
			printf("My true love gave to me\n");   
			break;

		case 11:
			printf("On the eleventh day of Christmas,\n");
			printf("My true love gave to me\n");
			break;

		case 12:
			printf("On the twelfth day of Christmas,\n");
			printf("My true love gave to me\n");
			break;
		
		case ' ':
			break;

		default:			
			break;		
		}

		for (int verse = 1; verse <= day; verse++) { // loops through verse for each day 

			switch (verse) {

			case 1:
				printf("A partridge in a pear tree\n");
				break;

			case 2:
				printf("Two turtle doves\n");
				break;

			case 3:
				printf("Three French hens\n");
				break;

			case 4:
				printf("Four calling birds\n");
				break;

			case 5:
				printf("Five golden rings\n");
				break;

			case 6:
				printf("Six geese a-laying\n");
				break;

			case 7:
				printf("Seven swans a-swimming\n");
				break;

			case 8:
				printf("Eight maids a-milking\n");
				break;

			case 9:
				printf("Nine ladies dancing\n");
				break;

			case 10:
				printf("Ten lords a-leaping\n");
				break;

			case 11:
				printf("Eleven pipers piping\n");
				break;

			case 12:
				printf("Twelve drummers drumming\n");
				break;
		
			case ' ':
				break;

			default:				
				break;				
			}			
		}
		printf("\n"); // prints new line after each complete incremented iteration
	}
}

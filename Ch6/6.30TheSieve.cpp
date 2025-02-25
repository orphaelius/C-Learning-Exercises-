/*******************************************************************************

                       // The Sieve of Eratosthenes //

    The Sieve of Eratosthenes is an algorithm for iteratively determining 
    prime values by marking composites. It's formation is attributed to the 
    ancient Greek mathematician. This program performs as such, in that it
    iterates through an array and marks necessary subscripts as 'not prime.'

    Written by: Jon-Austin

    Date: 02/24/2025

*******************************************************************************/

#include <stdio.h>
#include <math.h>

#define DIVISOR 10 // Used to break array into rows/columns
#define SIZE 1000 // Size of array

// Function Prototypes //
void displayDescription(void);
void makeArray(int primes[SIZE]);
int isPrime(int subscript); // Obsolute
void theSieve(int primes[SIZE + 1]);
void printNormalArray(int primes[SIZE]);
void printTrue(int primes[SIZE]); 

/*******************************************************************************
    Function: main()
    Description: Takes user input, process, prints output..
    Parameters: ---
    Return: ---
*******************************************************************************/
int main(void) {
    int primes[SIZE + 1];
    displayDescription(); // Nothing hidden here..

    makeArray(primes); // Initializes array to all true values (1s)
    
    theSieve(primes); // Bring in the Big Sieve
    // Print array as normal to show proof of Mr. Sieve's work
    printNormalArray(primes); 
    // Only print subscripts whose values are 1 (aka all prime numbers up to [size]
    printTrue(primes);  

    return 0;
}

/*******************************************************************************
    Function: displayDescription()
    Description: Displays program intentions
    Parameters: ---
    Return: ---
*******************************************************************************/
void displayDescription() {
    printf("%s%s%s%s%s", "This program initializes an array to 1s (true)",
        " and runs through each subscript to determine which subscripts",
        " are prime.", " It then prints a final array of only prime",
        " values.\n");
    puts("");
    puts("");
} // End displayDescription()

/*******************************************************************************
    Function: makeArray()
    Description: Initializes each index in array to 1, essentially assuming all
        values are 'true' to start
    Parameters: primes array
    Return: ---
*******************************************************************************/
void makeArray(int array[SIZE]) {
    for (size_t i = 0; i <= SIZE; ++i) {
        array[i] = 1; // Sets all values to 1 (for 'true')
    }
} // End makeArray()

/*******************************************************************************
    Function: printNormalArray()
    Description: Prints an array
    Parameters: primes array
    Return: ---
*******************************************************************************/
void printNormalArray(int array[SIZE]) {
    for (size_t i = 0; i < SIZE; ++i) {
        // New space every 10 elements (neatly formatted)
        if (i % DIVISOR == 0) {
            printf("\n");
        }
        printf("%d ", array[i]);
    }
    puts("");
} // End printNormalArray()

/*******************************************************************************
    Function: printTrue()
    Description: Prints only subscripts that are prime
    Parameters: primes array
    Return: ---
*******************************************************************************/
void printTrue(int array[SIZE]) {
    for (int i = 0; i < SIZE; ++i) { 
        if (array[i] != 0) {
            printf("%d ", i);     
        }
    }
} // End printNormalArray()

/*******************************************************************************
    Function: theSieve()
    Description: Loops through an array of subscripts, determining which ones
        are prime
    Parameters: primes array
    Return: ---
*******************************************************************************/
void theSieve(int primes[SIZE + 1]) { // + 1 because indexing to 100 = 0 - 99
    primes[0] = 0; // Not prime
    primes[1] = 0; // Not prime

    for (int i = 2; i * i <= SIZE; i++) {
        // First check is 2. Assumes everything is prime after 
        // Until inner loop.
        printf("i is %d\n", i);

        if (primes[i] != 0) {
            // Assming primes[i] is prime (1)
            // j is the sqrt of i, looped until j reaches the end of the array.
            // For instance, the first iteration is 2, 4, 6, 8, etc
            // Then 3, 9, 
            for (int j = i * i; j <= SIZE; j += i) {
                primes[j] = 0;
                printf("j is %d\n", j);
            }
        }
    }
} // theSieve

/*******************************************************************************
    Function: isPrime()
    Description: Created originally to check for prime numbers. Obsolete, but
        keeping for future endeavors.
    Parameters: subscript
    Return: 0 (for values that are not prime), 1 (for values that are prime)
*******************************************************************************/
int isPrime(int subscript) {
    // If subscript is 0 - 2, return false
    if (subscript < 2) {
        return 0;
    }
    else {
        for (int i = 2; i < subscript; i++) {
            if (subscript % i == 0) {
                return 0;
            }
        }
    }
    return 1;
} // End is Prime
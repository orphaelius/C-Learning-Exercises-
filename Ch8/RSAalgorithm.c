/*******************************************************************************
                            // RSA Algorithm //

        This program follows exercises 8.43, 8.44, 8.45, 8.46, and 8.47. The 
        program takes several evolutions from being a fairly rudimentary 
        representation of a generic RSA algorithm to a fully functional
        encryption and decryption program using the RSA framework. A user may
        elect to try and brute force the encrypted message before using the 
        decryption function.

        Written by: Jon-Austin

******************************************************************************/

/*************** Libraries ***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

/*******************************************************************************

                            // RSA Function Prototypes //

******************************************************************************/

#define MAXEXPONENTS 1000
#define MAXINPUT 100

// Input functions
void getUserInput(int* p, int* q);
void inputMessageToEncrypt(char inputMessage[MAXINPUT]);
int getSwitchKey(int* switchKey);

// Output functions
void showPrime();
void printCharMessage(char* message, int messageLength);
void displayProgramHeader();
void printHeaderLines();
void displayMenu();
void printPrimeNums(int elements, long long int potentialExponents[]);
void printIntMessage(long long int* message, int messageLength);

// Calculation functions
int testIfPrime(int n);
int calcModulus(int p, int q);
int calcTotient(int p, int q); // Depreciated
int calcLambdaOf(int p, int q);
int determineGCD(int a, int b);
int findLCM(int a, int b);
int modularPow(int base, int exp, int mod);

// Encrypt/decrypt functions
int determinePubKeyExponent(long long int potentialExponents[MAXEXPONENTS],
    long long int lambda);
int determinePrivKeyExponent(int publicExp, long long int lambda,
    long long int potentialExponents[MAXEXPONENTS], int elements);
int selectPubKey(int exponent);
int selectPrivKey(int exponent);
void encryptMessage(char* messageToEncrypt, long long int* encryptedMessage,
    int publicExp, int modulus, int* messageLength);
void decryptMessage(long long int* encryptedMessage, char* decryptedMessage,
    int privExp, int modulus, int* messageLength);

// Brute force functions
void bruteForce(long long int* encryptedMessage, int messageLength, int modulus);

/******************************************************************************

                            // Main //

******************************************************************************/
int main(void) {

    /*************** Variables ***************/
    int p = 0; // Prime number 1-- user input
    int q = 0; // Prime number 2-- user input
    int modulus = 0;
    long long int lambda = 0;  
    int publicExp = 0;
    long long int privExp = 9;
    long long int elements = 0;
    int messageLength = 0; 
    int switchKey = 0;
   
    /*************** Arrays ***************/ 
    // Array to store possible encryption exponents 
    long long int potentialExponents[MAXEXPONENTS] = { 0 };  
    char inputMessage[MAXINPUT] = { "" };
    long long int encryptedMessage[MAXINPUT] = { 0 };
    char decryptedMessage[MAXINPUT] = { "" };
   
    /*************** Start program ***************/
    displayProgramHeader(); 
    showPrime(); // Display prime numbers from 2-300
    getUserInput(&p, &q); // Input two prime nums

    /*************** Make initial key calculations ***************/
    modulus = calcModulus(p, q);
    printf("The modulus for our key is: %d\n\n", modulus); 
    lambda = calcLambdaOf(p, q); 
    printf("The lambda for our key is %lld\n", lambda);   

    // Display all possible exponents for a user to select from for the key
    elements = determinePubKeyExponent(potentialExponents, lambda); 
    printPrimeNums(elements, potentialExponents); 

    // Calculate public and private exponents for both keys
    publicExp = selectPubKey(publicExp);  
    privExp = determinePrivKeyExponent(publicExp, lambda, potentialExponents, elements); 

    /*************** Main loop ***************
    Allows user to input message to encrypt,
        decrypt that message using the keys,
        or attempt a brute force decryption
    ******************************************/    
    printHeaderLines();
    printf("M E N U  O P T I O N S:\n");
    printHeaderLines();
    displayMenu(); 
    while ((switchKey = getSwitchKey(&switchKey))) {

        if (switchKey == -1) {
            printf("Exiting program...\n");
            break;
        }

        switch (switchKey) {
        case 1: // Input message to encrypt
            inputMessageToEncrypt(inputMessage);
            encryptMessage(inputMessage, encryptedMessage, publicExp, modulus, &messageLength);
            printf("Encrypted message: ");
            printIntMessage(encryptedMessage, messageLength);
            break;

        case 2: // Decrypt message
            decryptMessage(encryptedMessage, decryptedMessage, privExp, modulus, &messageLength);
            printf("Decrypted message: ");
            printCharMessage(decryptedMessage, messageLength);
            break;
        case 3: // Brute force attempt
            printf("Attempting brute force decryption...\n");
            bruteForce(encryptedMessage, messageLength, modulus);
            break;
        }

        // Repeat menu options until user exits
        printHeaderLines();
        printf("M E N U  O P T I O N S:\n");
        printHeaderLines();
        displayMenu();
    }         
   
    return 0; 
} // End main()

/******************************************************************************
    Function: getUserInput()
    Description: Grabs two prime numbers from user; Annoys user to enter a prime
    number if the entry is not prime
    Side Effect: modifies values of p and q in mem
    Parameters: points to p and q
    Return: ---
******************************************************************************/
void getUserInput(int* p, int* q) {
	printf("Enter a prime number for p: ");
    scanf("%d", p); 
    int tempPrime = *p;  
    while (testIfPrime(tempPrime) != 1) {
        printf("%d is not a prime number\n", tempPrime); 
        printf("Enter a prime number: ");
        scanf("%d", p); 
        tempPrime = *p; 
    }           
    
	printf("Enter a prime number for q: ");
	scanf("%d", q);
    tempPrime = *q; 

    while (testIfPrime(tempPrime) != 1) {
        printf("%d is not a prime number\n", tempPrime);
        printf("Enter a prime number: ");
        scanf("%d", q); 
        tempPrime = *q; 
    }
} // End getUserInput()

/*******************************************************************************
    Function: getSwitchKey()
    Description: Passes switch key back into main body loop
    Parameters: Points to switchKey, allowing for perpetual update of value to
    navigate the main loop accordingly
    Return: switchKey
*******************************************************************************/
int getSwitchKey(int* switchKey) {
    scanf("%d", switchKey);
    return *switchKey; 
} // End getSwitchKey()

/******************************************************************************
    Function: determinePubKeyExponent()
    Description: Finds potential exponents to use as the public key; stores in
    the array potentialExponents[]
    Formula: 1 < e < totient
    Parameters: potentialExponents[] and totient
    Return: counter (counts total elements in the array)
******************************************************************************/
int determinePubKeyExponent(long long int potentialExponents[MAXEXPONENTS], 
    long long int lambda) {
    int e;
    int counter = 0;
     
    for (e = 2; e < lambda; ++e) {
        if (determineGCD(e, lambda) == 1) {
            potentialExponents[counter++] = e; 
        }
    }
    return counter; 
} // End determinePubKeyExponent()

/******************************************************************************
    Function: selectPubKey()
    Description: Takes user input (for now) for the public key exponent from 
    the displayed list
    Return: exponent entered
******************************************************************************/
int selectPubKey(int exponent) {
    printf("Enter one of the exponents from above to use in the public key: ");
    scanf("%d", &exponent);
    return exponent; 
} // End selectPubKey()

/******************************************************************************
    Function: determinePrivKeyExponent()
    Description: Determines the private key exponent using the formula
    (d * e) mod totient = 1
    Parameters: publicExp, totient, potentialExponents[], elements
    Return: First element in potentialExponents[] that matches the formula 
    criteria
******************************************************************************/
int determinePrivKeyExponent(int publicExp, long long int lambda, 
    long long int potentialExponents[MAXEXPONENTS], int elements) {
    int counter = 0;

    for (int i = 0; i < elements; ++i) {
        if ((potentialExponents[i] * publicExp) % lambda == 1) {
            return potentialExponents[i]; 
        }
    }    
} // End determinePrivKeyExponent()

/******************************************************************************
    Function: selectPrivKey()
    Description: Allows user to input the priv key exponent manually
    Return: Priv key exponent    
******************************************************************************/
int selectPrivKey(int exponent) {
    printf("Enter one of the exponents from above to use in the public key: ");
    scanf("%d", &exponent);
    return exponent;
} // End selectPrivKey()

/******************************************************************************
    Function: modularPow()
    Description: Allows user to input the priv key exponent manually
    Return: Priv key exponent
******************************************************************************/
int modularPow(int base, int exp, int modulus) {
    int result = 1;
    base = base % modulus; 

    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd  
            result = (result * base) % modulus; 
        } 
        // Binary exponentiation-- using bitwise operator to check the bit 
        // of the exponent, square the base, and multiply only if that bit == 1
        exp = exp >> 1;  // exponent = exponent / 2  
        base = (base * base) % modulus;  
    }

    return result;
} // End modularPow()

/******************************************************************************
    Function: inputMessageToEncrypt()
    Description: Takes user input string to encrypt
    Return: ---
******************************************************************************/
void inputMessageToEncrypt(char inputMessage[MAXINPUT]) {
    char endOfLine[10]; 
    fgets(endOfLine, 10, stdin);
    
    printf("Enter a string to encrypt: ");
    
    fgets(inputMessage, MAXINPUT, stdin);
    inputMessage[strlen(inputMessage) - 1] = '\0';
} // End inputMessageToEncrypt()

void encryptMessage(char* messageToEncrypt, long long int* encryptedMessage, 
    int publicExp, int modulus, int* messageLength) {
    *messageLength = strlen(messageToEncrypt);
    for (size_t i = 0; i < *messageLength; ++i) { 
        unsigned char ch = messageToEncrypt[i];  // Range 0–127
        encryptedMessage[i] = (long long int)modularPow((long long int)ch, publicExp, modulus);       
    }
} // end encryptMessage()

void decryptMessage(long long int* encryptedMessage, char* decryptedMessage, 
    int privExp, int modulus, int* messageLength) {
    for (size_t i = 0; i < *messageLength; ++i) {
        decryptedMessage[i] = (char)modularPow(encryptedMessage[i], privExp, modulus);
    }
    decryptedMessage[*messageLength] = '\0';   
} // End decryptMessage()












/*******************************************************************************

                        // RSA Calculation Functions //

******************************************************************************/

/******************************************************************************
    Function: calcTotient()
    Description: Calculates... totient! Formula: (totient) = (p - 1) * (q - 1)
    // DEPRECIATED //
    Side Effects: ---
    Parameters: p and q
    Return: Totient
******************************************************************************/
int calcTotient(int p, int q) {
    return (p - 1) * (q - 1);
} // End calcTotient()

/******************************************************************************
    Function: calcModulus()
    Description: Calculates modulus (n)
    Side Effects: ---
    Parameters: p and q
    Return: p * q
******************************************************************************/
int calcModulus(int p, int q) {
    return p * q;
} // End calcModulus()

int calcLambdaOf(int p, int q) {
    int a = p - 1;
    int b = q - 1;
    long long int lambda = 0;
    lambda = findLCM(a, b);
    return lambda;
} // End calcLambdaOf()

/******************************************************************************
    Function: determineGCD()
    Description: Finds greatest common divisor using Euclidean algo, used in
    the following function to find coprime values (those whose GCD is only 1)
    Formula: (1 < exponent < phi of modulus)
    Parameters: a and b
    Return: a
******************************************************************************/
int determineGCD(int a, int b) {
    while (b != 0) {
        int trash = b;
        b = a % b;
        a = trash;
    }

    return a;
} // End determineGCD()

/******************************************************************************
    Function: findLCM()
    Description: Finds least common multiple of a and b
    Return: Priv key exponent
******************************************************************************/
int findLCM(int a, int b) {
    if (a == 0 || b == 0) return 0; // LCM(0, x) = 0 by definition
    return (a / determineGCD(a, b)) * b;
} // End findLCM()

/******************************************************************************
    Function: testIfPrime()
    Description: Nothing hidden in function definition
    Parameters: Any integer
    Return: Returns false if intgger is not prime, else true
******************************************************************************/
int testIfPrime(int n) {

    if (n < 2) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
} // End testIfPrime()














/*******************************************************************************
* 
                            // RSA Display Functions //    

******************************************************************************/

/******************************************************************************
    Function: showPrime()
    Description: Displays prime numbers from 2 - 300 on console
    Parameters: ---
    Return: ---
******************************************************************************/
void showPrime() {
    int tabCounter = 0;
    printHeaderLines();
    printf("Displaying all prime numbers from 0 to 300:\n");
    printHeaderLines();
    for (int i = 0; i <= 300; i++) {

        if (testIfPrime(i)) {
            printf("%d ", i);
            tabCounter++;
        }

        if (tabCounter == 12) {
            printf("\n");
            tabCounter = 0;  // Reset after newline
        }
    }
    printf("\n\n");
} // End showPrime()

void printIntMessage(long long int* message, int messageLength) {
    for (size_t i = 0; i < messageLength; ++i) {
        printf("%c", message[i]);
    }
    printf("\n\n");
} // End printMessage()

void printCharMessage(char* message, int messageLength) {
    printf("%s\n\n", message);
} // End printMessage()

/*******************************************************************************
    Function: displayProgramHeader()
    Description: Displays program header at initialization
    Parameters: ---
    Return: ---
*******************************************************************************/
void displayProgramHeader() {
    printHeaderLines();
    printf("%s %s %s",
        "-----------------------------------------------------",
        "Functional RSA Encryption and Decryption",
        "--------------------------------------------------\n");
    printHeaderLines();
    printHeaderLines();
    printf("\n\n");
} // End displayProgramHeader()

/*******************************************************************************
    Function: printHeaderLines()
    Description: Displays lines for clean formatting of data
    Parameters: ---
    Return: ---
*******************************************************************************/
void printHeaderLines() {
    for (size_t i = 0; i < 144; ++i) {
        printf("%c", '-');
    }
    puts("");
} // End printHeaderLines() 

/******************************************************************************
    Function: printPrimeNums()
    Description: Prints prime numbers from 0 - elements
    Return: ---
******************************************************************************/
void printPrimeNums(int elements, long long int potentialExponents[]) {
    for (int i = 0; i < elements; ++i) {
        printf("%lld ", potentialExponents[i]);
    }
    printf("\n\n");
} // End printPrimeNums()

void displayMenu() {
    char menuOptions[4][100] = {
        {"Enter 1 to input a message to encrypt using the keys"},
        {"Enter 2 to decrypt that message using the keys"},
        {"Enter 3 to attempt a brute force decryption of the original message"},
        {"Enter -1 to exit the program"}
    };

    for (size_t i = 0; i < 4; ++i) {
        printf("%s\n", menuOptions[i]);
    }
    printf("Selection: ");
}

/******************************************************************************
    Function: bruteForce()
    Description: Very simple brute force function. Iterates through all 
    potential key exponents using a nested loop, then performs a check on each 
    character. Appends each character to a temporary array, prints the array at 
    the end of each cycle, then uses strcmp() to compare each string along the 
    way. 
    Parameters: encryptedMessage[], messageLength, modulus
******************************************************************************/
void bruteForce(long long int* encryptedMessage, int messageLength, int modulus) {
    char attemptedBruteForce[MAXINPUT];
    attemptedBruteForce[messageLength] = '\0'; 

    for (int attempt = 1; attempt < modulus; ++attempt) {
        int printableCount = 0;
       
        for (int i = 0; i < messageLength; ++i) {
            char decryptedChar = (char)modularPow(encryptedMessage[i], attempt, modulus);            
            attemptedBruteForce[i] = decryptedChar;            
        }

        attemptedBruteForce[messageLength] = '\0'; 
        
        printf("Attempt %d message: %s\n", attempt, attemptedBruteForce);
        printf("\n");        

    }

} // End bruteForce()


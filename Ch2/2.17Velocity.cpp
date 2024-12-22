#include <stdio.h>

// write a program that asks the user to enter the initial velocity and acceleration of an object, 
// and the time that has elapsed, places them in the variables u, a, and t, and prints the final velocity, v, 
// and distance traversed, s, using te following equations:
// 
// a) v = u+at
// b) s = ut + 1/2at^2

int main(void) {

// declare the initial variables u, a, and t:
int u = 0;
int a = 0;
int t = 0;

// print the input message, take input from a user:
printf("Let's calculate the final velocity and distance traversed of an object you've thrown. \nEnter the initial velocity in and acceleration of an object, n, in m/s, \nand the time that has lapsed in seconds since the object was thrown.\n");
scanf("%d %d %d", &u, &a, &t);
printf("The initial velocity is %d m/s, the acceleration is %d m/s, and the time lapsed is %d seconds.\n", u, a, t);

//set up formulas:
int v = u + a * t;
int s = (u * t) + (((1/2) * a * t) * ((1/2) * a * t));

//print results:
printf("The final velocity is %d m/s and the total distanced traveled is %d meters.\n", v, s);

}

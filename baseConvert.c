/*
Base converting program.
Possible options are decimal, octal, and hexadecimal.
*/

#include<stdio.h>
#include<math.h>
#include <string.h>

// initializes the functions
void displayValueInBase(int, int);
int toChar(int);

// possible error conditions are if the user does not enter one of the
// specified bases, or if the number is negative
int main(void)
{
    // originalBase variable keeps track of the base entered by the user
    char originalBase[3] = "";
    // convertBase variable keeps track of the base converting to
    char convertBase[3] = "";
    // number variable keeps track of the number entered by the user
    int number = 0;

    // reading information from the user through stdin
    // asks what base the user wants to enter: dec, oct, or hex
    printf("please enter what base you want to convert from\n");
    printf("(dec, oct, or hex): ");
    scanf("%s", originalBase);
    // converts and prints out the number based on the base entered by the user
    if (strcmp("dec", originalBase) == 0) {
        // asks the user for a number
        printf("please enter a number: ");
        scanf("%i", &number);
    } else if (strcmp("oct", originalBase) == 0) {
        // asks the user for a number
        printf("please enter a number: ");
        scanf("%o", &number);
    } else if (strcmp("hex", originalBase) == 0) {
        // asks the user for a number
        printf("please enter a number: ");
        scanf("%x", &number);
    }
    // asks what base the number should be displayed in: dec, oct, or hex
    printf("please enter what base you want the number to be displayed in\n");
    printf("(dec, oct, or hex): ");
    scanf("%s", convertBase);

    // printing information to the user through stdout
    // print the base converted number to the user
    printf("the number in %s base is: ", convertBase);

    // converts and prints out the number based on the base entered by the user
    if (strcmp("dec", convertBase) == 0) {
        displayValueInBase(number, 10);
    } else if (strcmp("oct", convertBase) == 0) {
        displayValueInBase(number, 8);
    } else if (strcmp("hex", convertBase) == 0) {
        displayValueInBase(number, 16);
    }

    return 0;
}

// converts the given number into the specified base
void displayValueInBase(int number, int base) {
    // digits needed in result
    int k = 0;
    // divisor to divide number by to convert
    int divisor = 0;
    // zero is the same in any base
    if (number == 0) {
        printf("0");
    } else {
        k = floor(log10(number) / log10(base)) + 1;
        divisor = pow(base, k - 1);
        // run through value, calculating and displaying the value of each
        // digits in the new base (left to right)
        while (divisor >= 1) {
            putchar(toChar((int)(number / divisor)));
            number = number % divisor;
            divisor = divisor / base;
        }
    }
}

// converts values from integer to character
int toChar(int value) {
    if (value < 10) {
        return '0' + value;
    } else {
        return 'A' + value - 10;
    }
}

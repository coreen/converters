/*
Arithmetic performed on chosen base and returned in requested base,
extension of base convert program.
*/

#include<stdio.h>
#include<math.h>
#include <string.h>

// initializes the functions
int operate(int, int, char);
void displayValueInBase(int, int);
int toChar(int);

// possible error conditions are if the user does not enter one of the
// specified bases, if the number is negative, or fractional results
int main(void)
{
    // originalBase variable keeps track of the base entered by the user
    char originalBase[3] = "";
    // convertBase variable keeps track of the base converting to
    char convertBase[3] = "";
    // number variables keep track of the numbers entered by the user
    int number1 = 0;
    int number2 = 0;
    // calc variable keeps track of the operation the user requests
    int calc = 0;

    // reading information from the user through stdin
    // asks what base the user wants to enter: dec, oct, or hex
    printf("please enter what base you want to enter (dec, oct, or hex): ");
    scanf("%s", originalBase);
    // converts and prints out the number based on the base entered by the user
    if (strcmp("dec", originalBase) == 0) {
        // asks the user for the numbers to calculate
        printf("please enter the first number for calculation: ");
        scanf("%i", &number1);
        printf("please enter the second number for calculation: ");
        scanf("%i", &number2);
    } else if (strcmp("oct", originalBase) == 0) {
        // asks the user for the numbers to calculate
        printf("please enter the first number for calculation: ");
        scanf("%o", &number1);
        printf("please enter the second number for calculation: ");
        scanf("%o", &number2);
    } else if (strcmp("hex", originalBase) == 0) {
        // asks the user for the numbers to calculate
        printf("please enter the first number for calculation: ");
        scanf("%x", &number1);
        printf("please enter the second number for calculation: ");
        scanf("%x", &number2);
    }
    // asks the user for the operation they wish to carry out on the numbers
    printf("what operation would you like to perform on the above numbers\n");
    printf("(+, -, *, or /)? ");
    // get rid of the newline character still in the buffer
    getchar();
    // set the character into the entered operation
    calc = getchar();
    // asks what base the result should be displayed in: dec, oct, or hex
    printf("please enter what base you want the result to be displayed in\n");
    printf("(dec, oct, or hex): ");
    scanf("%s", convertBase);

    // printing information to the user through stdout
    // print the base converted result to the user
    printf("the result in %s base of ", convertBase);

    // converts and prints out the number based on the base entered by the user
    if (strcmp("dec", convertBase) == 0) {
        displayValueInBase(number1, 10);
        printf(" %c ", ((char) calc));
        displayValueInBase(number2, 10);
        printf(" is: %i", operate(number1, number2, ((char)calc)));
    } else if (strcmp("oct", convertBase) == 0) {
        displayValueInBase(number1, 8);
        printf(" %c ", ((char) calc));
        displayValueInBase(number2, 8);
        printf(" is: %o", operate(number1, number2, ((char)calc)));
    } else if (strcmp("hex", convertBase) == 0) {
        displayValueInBase(number1, 16);
        printf(" %c ", ((char) calc));
        displayValueInBase(number2, 16);
        printf(" is: %x", operate(number1, number2, ((char)calc)));
    }

    return 0;
}

// performs the specified operation according to the operator given
int operate(int num1, int num2, char calc) {
    if (calc == '+') {
        return num1 + num2;
    } else if (calc == '-') {
        return num1 - num2;
    } else if (calc == '*') {
        return num1 * num2;
    }else if (calc == '/') {
        return num1 / num2;
    }
    return -1;
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

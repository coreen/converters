/*
Converts numbers from ASCII code into characters.
*/

#include<stdio.h>

int main(void)
{
    // codeValue variable holds the user entered ASCII code value
    int codeValue = 0;

    // reading information from the user through stdin
    // asks the user for an ASCII code value, saving the value
    // into the codeValue variable
    printf("please enter an ASCII code value: ");
    scanf("%i", &codeValue);

    // printing information to the user through stdout
    // print the corresponding character to the ASCII code value
    // entered to the user
    printf("your ASCII character is: %c", codeValue);

    return 0;
}

/*
Asks user age in years, then outputs the corresponding age in seconds.
*/

#include<stdio.h>

int main(void)
{
    // constant variable for the approximate number of seconds per year
    // used for calculating the result printed out to the user
    const float SECPERYEAR = 3.156e+7;

    // age variable holds the user entered age
    int age = 0;

    // reading information from the user through stdin
    // asks the user for their age, saving the value into the age variable
    printf("please enter your age: ");
    scanf("%i", &age);

    // multiply the inputed age with the approximate number of seconds
    // per year and set the answer to the result variable
    float result = age * SECPERYEAR;

    // printing information to the user through stdout
    // print the corresponding age in seconds to the user
    printf("Your age in seconds = %.4e", result);

    return 0;
}

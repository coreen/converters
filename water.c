/*
Prompts user for an amount of water in quarts and
returns the corresponding amount in molecules.
*/

#include<stdio.h>

int main(void)
{
    // constant variables for the approximate mass per molecule
    // of water and the number of grams per quart of water
    const float MOLECULEMASS = 3.0e-23;
    const int QUARTMASS = 950;

    // amount variable holds the user entered amount
    // of water in quarts
    int amount = 0;

    // reading information from the user through stdin
    // asks the user for an amount of water in quarts, saving
    // the value into the amount variable
    printf("please enter an amount of water in quarts: ");
    scanf("%i", &amount);

    // multiply the inputed amount with the approximate number of
    // grams per quart and set the answer to the grams variable
    int grams = amount * QUARTMASS;

    // multiply the grams variable by the number of molecules in
    // each gram and set the answer to the molecules variable
    float molecules = grams / MOLECULEMASS;

    // printing information to the user through stdout
    // print the corresponding amount of water in grams and the
    // number of molecules in that amount to the user
    printf("equivalent amount in grams = %i, \n", grams);
    printf("which is equivalent to %.4e molecules", molecules);

    return 0;
}

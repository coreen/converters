/*
Converts between different temperature scales.
*/

#include<stdio.h>
#include <string.h>

int main(void)
{
    // temperature variable holds the user entered temperature
    float temperature = 0.0;
    // scale variable holds the user entered temperature scale
    char scale[15] = "";
    // convert variable holds the user entered temperature scale
    // that is requested for the temperature to be converted to
    char convert[15] = "";

    // reading information from the user through stdin
    // asks the user for a temperature value
    printf("please enter a temperature: ");
    scanf("%f", &temperature);
    // asks the user for the corresponding scale of the entered
    // temperature
    printf("the scale of the temperature entered above\n");
    printf("Celsius, Fahrenheit, or Kelvin?\n");
    printf("Your scale: ");
    scanf("%s", scale);
    // asks the user for the temperature scale the user wants the
    // temperature to be converted to
    printf("the scale of the temperature you would like to convert to\n");
    printf("Celsius, Fahrenheit, or Kelvin?\n");
    printf("Convert scale: ");
    scanf("%s", convert);
    // convert the temperature between scales according to the scale
    // and convert variable inputs, if scales are equal do nothing
    float result = temperature;
    if (strcmp("Celsius", scale) == 0) {
        if (strcmp("Fahrenheit", convert) == 0) {
            result = (temperature * 9 / 5) + 32;
        } else if (strcmp("Kelvin", convert) == 0) {
            result = temperature + 273.15;
        }
    } else if(strcmp("Fahrenheit", scale) == 0) {
        if (strcmp("Celsius", convert) == 0) {
            result = (temperature - 32) * 5 / 9;
        } else if (strcmp("Kelvin", convert) == 0) {
            result = ((temperature - 32) * 5 / 9) + 273.15;
        }
    } else if(strcmp("Kelvin", scale) == 0) {
        if (strcmp("Celsius", convert) == 0) {
            result = temperature - 273.15;
        } else if (strcmp("Fahrenheit", convert) == 0) {
            result = ((temperature - 273.15)  * 9 / 5) + 32;
        }
    }

    // printing information to the user through stdout
    // print the correponding temperature converted as specified by the user,
    // error message printed if no valid scale(s) entered
    if (strcmp("Celsius", scale) == 0 || strcmp("Fahrenheit", scale) == 0 ||
        strcmp("Kelvin", scale) == 0 || strcmp("Celsius", convert) == 0 ||
        strcmp("Fahrenheit", convert) == 0 || strcmp("Kelvin", convert) == 0) {
    // print equivalence, because scale inputs are valid
        printf("%.2f %s is equivalent to %.2f %s", temperature, scale, result, convert);
    } else {
    // print error, because scale input(s) are NOT valid
        printf("ERROR: invalid input(s) entered for conversion scales");
    }

    return 0;
}

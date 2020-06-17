#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // prompt change until valid number
    float changeF;
    do
    {
        changeF = get_float("Change: ");        
    } 
    while (changeF <= 0);
    // round change
    int change = round(changeF * 100);
    // calculate coins
    int quarters = change / 25;
    int dimes = (change % 25) / 10;
    int nickles = ((change % 25) % 10) / 5;
    int pennies = (((change % 25) % 10) % 5);
    // print result
    printf("%i\n", quarters + dimes + nickles + pennies);
}
#include <cs50.h>
#include <stdio.h>
#include <math.h>

// ##### PROTOTYPES #####
int get_length(long n);
string validate_card(long card_number, int n);
// ##### MAIN #####
int main(void)
{
    // prompt a credit card number
    long cc_number = get_long("Enter Card Number: ");
    // stores the length
    int length = get_length(cc_number);
    // validate the Luhn's Algorithm
    string card = validate_card(cc_number, length);
    printf("%s\n", card);
}

// ##### FUNCTIONS #####

// Function to get the length of the Credit Card Number
int get_length(long n)
{
    // initialize a counter
    int counter = 0;
    // iterate with the number by dividing by 10 until it gets zero
    while(n > 0)
    {
        n = n / 10;
        counter++;
    }
    // return counter
    return counter;
}

// Function to check if the Digit is Backwards Even or Not
bool check_even(int idx_back)
{
    bool back_even;
    
    if ( (idx_back % 2) == 0 ) 
    {
        back_even = false;
    } 
    else
    {
        back_even = true;    
    }
    
    return back_even;
}

// Main Function to Iterate and Return the Credit Card
string validate_card(long card_number, int length)
{
    // Bindings for Iteration
    int sum = 0;
    int idx_back;
    bool valid = false;
    string company = "INVALID";
    // the first number from the left of the card can be found here
    int first_idx = (length - 1);
    // and stored here
    int first_number = 0;
    // same follows for the second number from the left
    int second_idx = (length - 2);
    // and stored here
    int second_number = 0;
    // Iteration through the credit card number
    for (idx_back = 0; idx_back < length; idx_back++)
    {
        // the divisor changes according to the counter to get the last digit
        long divisor = pow(10, idx_back);
        // the last digit is stored into this variable
        int last = (card_number / divisor) % 10;

        // checks every loop to see if it should be stored or not
        if ( idx_back == second_idx )
        {
            second_number = last;
        }
        if ( idx_back == first_idx )
        {
            first_number = last;
        }

        // a boolean variable checks if it's a backwards even or not
        bool back_even = check_even(idx_back);
        // it it's a backward even do the following, skip if not
        if ( back_even == 1 )
        {
            // if the multiplication of the last digit is higher than nine
            if ( (last *= 2) > 9 )
            {
                // then subtract nine from it as suggested on wikipedia luhn's algorithm
                last -= 9;
            }
        }

        // whatever the digit is, multiplied, subtracted or not, sum it to the total
        sum += last;
    }

    // if the total sum divided by 10 results in zero
    if ( (sum % 10) == 0 )
    {
        // it's a valid credit card number
        valid = true;
    }

    // find the Company
    // if a given card is not valid, return invalid which is default company
    if ( valid != true )
    {
        return company;
    }
    // Join the two first numbers to discover the company
    int company_number = (first_number * 10) + second_number;
    // Find the company
    if ( valid == true && length == 15 && (company_number == 34 || company_number == 37) )
    {
        company = "AMEX";
    }
    if ( valid == true && length == 16 && company_number >= 51 && company_number <= 55 )
    {
        company = "MASTERCARD";
    }
    if ( valid == true && length >= 16 && length <= 16 && company_number >= 40 && company_number <= 49 )
    {
        company = "VISA";
    }
    // get the company
    return company;
}
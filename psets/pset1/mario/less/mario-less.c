#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_blocks(int n);

int main(void)
{
    int h = get_height("How tall should the pyramid be? (Choose from 1 to 8)\nYour answer: ");
    print_blocks(h);   
}

// Functions
// Prompt Height
int get_height(string prompt)
{
    int h;
    do
    {
        h = get_int("%s", prompt);
    }
    while ( h < 1 || h > 8 );
    return h;
}
// Print Blocks
void print_blocks(int height)
{
    for (int line = 1; line <= height ; line++ )
    {
        for (int spaces = height - line + 1; spaces > 1; spaces-- )
        {
            printf(" ");
        }
        for (int blocks = 0; blocks < line; blocks++ )
        {
            printf("#");
        }
        printf("\n");
    }
}
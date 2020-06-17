#include <cs50.h>
#include <stdio.h>

// ===== Load Functions =====
int get_height(string prompt);
void print_blocks(int n);

// ===== Main =====
int main(void)
{
    int h = get_height("How tall should the pyramid be?\nYour answer: ");
    print_blocks(h);
}

// ===== Functions =====

// Prompt Pyramid Tall
int get_height(string prompt)
{
    // Declare an INTEGER
    int h;
    // Loop until it's higher than 1 and lower than 8
    do
    {
        h = get_int("%s", prompt);
    }
    while ( h < 1 || h > 8 );
    // Return the value
    return h;
}

// Print Blocks
void print_blocks(int rows)
{
    for (int line = 0; line < rows; line++)
    {
        // Spaces on the left
        for (int space = rows - (line + 1); space > 0; space--) 
        {
            printf(" ");
        }
        // Left blocks
        for (int blockL = 0; blockL <= line; blockL++)
        {
            printf("#");
        }
        // Spaces inbetween
        printf("  ");
        // Right blocks
        for (int blockR = 0; blockR <= line; blockR++)
        {
            printf("#");
        }
        printf("\n");
    }
}

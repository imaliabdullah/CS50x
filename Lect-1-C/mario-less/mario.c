#include <cs50.h>
#include <stdio.h>

void print_row(int total_bricks, int row_number);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(n, i + 1);
    }
}

void print_row(int total_bricks, int row_number)
{
    // Print spaces before the bricks
    for (int i = 0; i < total_bricks - row_number; i++)
    {
        printf(" ");
    }

    // Print bricks
    for (int i = 0; i < row_number; i++)
    {
        printf("#");
    }

    printf("\n");
}

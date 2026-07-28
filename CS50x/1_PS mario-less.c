#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int H;
    do
    {
        H = get_int("Height: ");
    }
    while (H < 1);

    // for the rows
    for (int r = 0; r < H; r++)
    {
        // space per column
        for (int sp = 0; sp < H - r - 1; sp++)
        {
            printf(" ");
        }

        // blocks per column
        for (int b = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}

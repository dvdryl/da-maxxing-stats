#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int H;
    do
    {
        H = get_int("Height:");
    }
    while (H < 1);

    // rows
    for (int r = 0; r < H; r++)
    {
        // spacing per triangle
        for (int sp = 0; sp < H - r - 1; sp++)
        {
            printf(" ");
        }

        // left blocks
        for (int L = 0; L <= r; L++)
        {
            printf("#");
        }

        // gap
        printf("  ");

        // right blocks
        for (int R = 0; R <= r; R++)
        {
            printf("#");
        }
        printf("\n");
    }
}

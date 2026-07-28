#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get valid change owed from user
    int c;
    do
    {
        c = get_int("change owed: ");
    }
    while (c < 0);

    // now checks the coin here to divide it thru 25,10,5 and 1.
    // coins count through a greedy algorithm
    int coins = 0;

    // Quarters
    coins += c / 25;
    c = c % 25;

    // Dimes
    coins += c / 10;
    c = c % 10;

    // Nickels
    coins += c / 5;
    c = c % 5;

    // Pennies
    coins += c / 1;
    c = c % 1;
    // this last one was redundant... but yeah.. just to be sure

    printf("%i\n", coins);
}

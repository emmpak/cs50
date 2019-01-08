#include <stdio.h>
#include <cs50.h>

void print_chars(int num, char c);

// Prompts user for a positive number lower than 23 and constructs two pyramids made of hashes ('#') just like in Mario.
int main(void)
{
    int height;
    do
    {
        height = get_int("How high would you like the pyramids to be? ");
    }
    while (height < 0 || height > 23);

    for (int i = 1; i <= height; i++)
    {
        print_chars(height - i, ' ');
        print_chars(i, '#');
        print_chars(2, ' ');
        print_chars(i, '#');
        printf("\n");
    }
}

// Prints a character 'n' number of times.
void print_chars(int n, char c)
{
    while (n-- > 0)
    {
        printf("%c", c);
    }
}

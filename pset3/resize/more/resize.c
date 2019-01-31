#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_argument_count(int count);
int is_numeric(char *num);
int is_valid_number(float n);
int validate_inputs(int count, char *inputs[]);

int main(int argc, char *argv[])
{
    return validate_inputs(argc, argv);
}

// validates the inputs
int validate_inputs(int count, char *inputs[])
{
    int check = 0;
    check = is_valid_argument_count(count);
    check = is_numeric(inputs[1]);

    if (check)
    {
        float num = atoi(inputs[1]);
        check = is_valid_number(num);
    }
    printf("%i", check);
    return check;
}

// verifies the number of arguments
int is_valid_argument_count(int count)
{
    if (count != 4)
    {
        printf("Please provide exactly 3 arguments.\n");
        return 0;
    }
    return 1;
}

// verifies that the first argument is a number
int is_numeric(char *num)
{
    for (int i = 0, n = strlen(num); i < n; i++)
    {
        if (!isdigit(num[i]))
        {
            printf("Please provide a number between 0 and 100 as the first argument.\n");
            return 0;
        }
    }
    return 1;
}

// verifies that the first argument is a float b/n 0 and 100
int is_valid_number(float n)
{
    if (n < 0 || n > 100)
    {
        printf("Please provide a number between 0 and 100 as the first argument.\n");
        return 0;
    }
    return 1;
}

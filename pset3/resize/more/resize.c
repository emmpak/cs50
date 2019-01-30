#include <stdio.h>
#include <stdlib.h>

void argument_count(int count);
void validate_inputs(int count, char *inputs[]);

int main(int argc, char *argv[])
{
    validate_inputs(argc, argv);

}

void validate_inputs(int count, char *inputs[])
{
    argument_count(count);
}

void argument_count(int count)
{
    if (count != 4)
    {
        printf("Please provide exactly 3 arguments.\n");
        exit(1);
    }
}

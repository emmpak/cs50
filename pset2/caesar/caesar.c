#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void validate_input(int argc, string argv[]);
int format_number(string str);

int main(int argc, string argv[])
{
    validate_input(argc, argv);
    int input = format_number(argv[1]);
    string plain = get_string("plaintext: ");

    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (!isalpha(plain[i])) continue;
        int char_num = (int) plain[i];
        int offset = isupper(char_num) ? 65 : 97;
        int ciph = (char_num - offset + input) % 26;

        plain[i] = ciph + offset;
    }
    printf("ciphertext: %s\n", plain);
    return 0;
}

// converts a string number to an integer
int format_number(string str)
{
    int num = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

// exits the program if the argv is not a single integer
void validate_input(int argc, string argv[])
{
    if (argc != 2 || !isdigit(*argv[1]))
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
}

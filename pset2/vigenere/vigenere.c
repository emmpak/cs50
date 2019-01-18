#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void validate_input(int argc, string argv[]);
int shift(char c);
char encrypt(char c, char key);
bool has_digit(char *key);

int main(int argc, string argv[])
{
    validate_input(argc, argv);
    string input = argv[1];
    string plain = get_string("plaintext: ");
    for (int i = 0, j = 0, n = strlen(plain); i < n; i++)
    {
        char character = plain[i];
        char key = input[j % strlen(input)];
        if (isalpha(character))
        {
            plain[i] = encrypt(character, key);
            j++;
        }
    }
    printf("ciphertext: %s\n", plain);
    return 0;
}

// shifts a character based on the key
char encrypt(char c, char key)
{
    int char_num = (int) c;
    int offset = isupper(char_num) ? 65 : 97;
    int ciph = ((char_num - offset + shift(key)) % 26) + offset;
    return ciph;
}

// converts a key character to its respective number
int shift(char c)
{
    return (int) toupper(c) - 65;
}

// exits the program if there is more than one cli argument
// or argument contains any numbers
void validate_input(int argc, string argv[])
{
    if (argc != 2 || has_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
}

// checks whether a string has a number in it
bool has_digit(char *key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i])) return true;
    }
    return false;
}

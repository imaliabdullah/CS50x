#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if the user did not enter a key or entered multiple keys.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Iterate through each character in argv[1] to check if it's a digit.
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`.
    int k = atoi(argv[1]) % 26;

    // Check if the key is non-positive.
    if (k <= 0)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    // Ask the user for the text to be encrypted and store it in the variable.
    string plaintext = get_string("plaintext: ");

    // Check the length of the entered text.
    int lenText = strlen(plaintext);

    // Declare the variable for the encrypted text.
    char ciphertext[lenText + 1];

    // Add to the variable for the encrypted text each letter of the normal text, now encrypted.
    for (int i = 0; i < lenText; i++)
    {
        // Reset the key variable for the next letters.
        k = atoi(argv[1]) % 26;

        // If it is a letter, ensure cases like 'z + 1' become 'a' and not some random symbol.
        if (isalpha(plaintext[i]))
        {
            // For lowercase letters.
            if (islower(plaintext[i]))
            {
                if (plaintext[i] + k > 122)
                {
                    k = k - 26;
                }
            }

            // For uppercase letters.
            else
            {
                if (plaintext[i] + k > 90)
                {
                    k = k - 26;
                }
            }

            // Encode the letter to change it to another letter according to the key.
            ciphertext[i] = plaintext[i] + k;
        }

        // If the character is not a letter, add it to the encrypted text normally.
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Null-terminate the encrypted text.
    ciphertext[lenText] = '\0';

    // Display the encrypted text on the screen.
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

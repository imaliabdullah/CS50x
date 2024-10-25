// Encrypts a text according to a given key that consists of a rearrangement of the alphabet.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Declare the key and a string with the alphabet for later comparison.
    string key = argv[1];
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Display error messages if the key is invalid (none or more than one key,
    // fewer or more than 26 letters, repeated letters, including symbols or numbers).
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // Check each character of the key to ensure it is a letter and not repeated.
        int i, j, k;
        for (i = 0, j = 0; i < 26; i++)
        {
            if (isalpha(key[i]))
            {
                key[i] = tolower(key[i]);
                for (k = 0; k < 26; k++)
                {
                    if (key[i] == key[k])
                    {
                        j++;
                    }
                }
            }
            else
            {
                printf("Key must only contain letters.\n");
                return 1;
            }
        }
        if (j != 26)
        {
            printf("Key must contain each letter only once.\n");
            return 1;
        }

        // If the key is valid, insert the corresponding letters into the encrypted text.
        else
        {
            // Declare variables to ask the user for the text, check the length of the text, and declare the list of the encrypted
            // text.
            string plaintext = get_string("plaintext:  ");
            int lenPlain = strlen(plaintext);
            char ciphertext[lenPlain];

            // Repeat the process according to the length of the entered text to encrypt each letter.
            for (i = 0; i <= lenPlain; i++)
            {
                // If it's a letter, check if it's uppercase or lowercase and substitute it with the corresponding one in the
                // previously entered key.
                if (isalpha(plaintext[i]))
                {
                    // Repeat the process 26 times (size of the alphabet), to compare letters and find the corresponding encrypted
                    // letter.
                    for (j = 0; j < 26; j++)
                    {
                        if (plaintext[i] == alphabet[j])
                        {
                            ciphertext[i] = key[j];
                        }
                        else if (plaintext[i] == toupper(alphabet[j]))
                        {
                            ciphertext[i] = toupper(key[j]);
                        }
                    }
                }

                // If it's not a letter, simply insert it into the encrypted text.
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }

            // Display the encrypted text on the screen.
            printf("ciphertext: %s\n", ciphertext);
        }
    }
}

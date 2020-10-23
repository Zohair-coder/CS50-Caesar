#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Psuedo-code:
// If the input is not a number or has more than one or no command line arguments then print error code. DONE
// Convert string input to integer using atoi(). DONE
// Input for plain text. DONE
// Loop through each letter in plain text. DONE
// Assign character a value in the alphabet e.g. B = 2 by subtracting ascii value of B. DONE
// Use ci = (pi + k) % 26 to assign the new value to B
// Save the new value of B in a new string


int main(int argc, string argv[])
{
    bool verification = false;
    if (argc == 2)
    {
        verification = true;
        int length = strlen(argv[1]);
        for (int j = 0; j < length; j++)
        {
            if (!isdigit(argv[1][j]))
            {
                verification = false;
            }
        }
    }

    if (verification)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        char ciphertext[strlen(plaintext)];
        char ref;
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            if isupper(plaintext[i])
            {
                ref = 'A';
            }
            else if islower(plaintext[i])
            {
                ref = 'a';
            }
            else
            {
                ciphertext[i] = plaintext[i];
                continue;
            }
            int rank = plaintext[i] - ref;
            char new_rank = (rank + key) % 26 + ref;
            ciphertext[i] = new_rank;

        }
        ciphertext[strlen(plaintext)] = '\0';
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


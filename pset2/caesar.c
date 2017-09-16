#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Implementation of simple Caesar Cipher
int main(int argc, char *argv[])
{
	// get cipher key and account for keys > 26
	// if no key, or multiple keys given, return error and exit
	int k;
	if (argc == 2) {
		k = atoi(argv[1]) % 26;
	} else {
		printf("Please input one integer as an argument\n");
		return 1;
	}

	// get input text
	printf("plaintext: ");
	char plaintext[100];
	fgets (plaintext, 100, stdin);

	// loop over input text
	printf("ciphertext: ");
	for (int i = 0; i < strlen(plaintext); i++)
	{
		// if letter is lower case, and letter + key exceeds ASCII letter code
		// then wrap around to front of alphabet
		if (plaintext[i] >= 97 && plaintext[i] <= 122)
		{
			if (plaintext[i] + k > 122)
			{
				printf("%c", ((plaintext[i] + k) - 122) + 96);
			}
			else
			{
				printf("%c", plaintext[i] + k);
			}

		}
		// if letter is upper case, and letter + key exceeds ASCII letter codes
		// for upper case letters, wrap around the alphabet
		else if (plaintext[i] >= 65 && plaintext[i] <= 90)
		{
			if (plaintext[i] + k > 90)
			{
				printf("%c", ((plaintext[i] + k) - 90) + 64);
			}
			else
			{
				printf("%c", plaintext[i] + k);
			}
		}
		// print non-letters as themselves (i.e. punctuation)
		else
		{
			printf("%c", plaintext[i]);
		}

	}
}

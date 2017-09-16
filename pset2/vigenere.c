#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Implementation of Vigenere's Cipher
int main(int argc, char *argv[])
{
	// Check for correct number of arguments, set k = arg1
	char *k;
	if (argc == 2)
	{
		k = argv[1];
	}
	else
	{
		printf("Invalid number of keys\n");
		return 1;
	}

	// check k is only letters
	for (int i = 0, n = strlen(k); i < n; i++)
	{
		if (!isalpha(k[i]))
		{
			printf("Invalid key\n");
			return 1;
		}
	}

	// convert k to all lowercase
	for (int i = 0, l = strlen(k); i < l; i++)
	{
		k[i] = tolower(k[i]);
	}

	// get input plaintext (s) to be converted
	printf("plaintext: ");
	char s[100];
	fgets (s, 100, stdin);

	printf("ciphertext: ");

	// initialize a counter so that whitespace and punctuation is not used
	// in the cipher
	int kc = 0;

	for (int i = 0, kn = strlen(k); i < strlen(s); i++)
	{
		if (isalpha(s[i]))
		{
			if (isupper(s[i]))
			{
				// convert key letters to 0-26
				// if plaintext ASCII + key exceeds 'Z' then wrap around to 'A'
				if (s[i] + (k[kc % kn] % 97) > 'Z')
				{
					printf("%c", ((s[i] + (k[kc % kn] % 97)) - 'Z') + 'A' - 1);

					// increment the key counter if a key letter was used
					kc++;
				}
				else
				{
					printf("%c", s[i] + (k[kc % kn] % 97));
					kc++;
				}
			}
			else if (islower(s[i]))
			{
				if (s[i] + (k[kc % kn] % 97) > 'z')
				{
					printf("%c", ((s[i] + (k[kc % kn] % 97)) - 'z') + 'a' - 1);
					kc++;
				}
				else
				{
					printf("%c", s[i] + (k[kc % kn] % 97));
					kc++;
				}
			}
		}
		else
		{
			// print punctuation, etc. as itself. don't incremeent key counter, as no key was used
			printf("%c", s[i]);
		}
	}
}

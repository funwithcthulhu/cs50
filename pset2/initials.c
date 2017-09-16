#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	// get input from user
	char *name; // or char name[100] 
	fgets (name, 100, stdin);

	// check first character for letter or space
	if (name[0] != ' ')
	{
		printf("%c", toupper(name[0]));
	}
	// loop through length of string, printing letters
	// with a space in front of them (initials)
	for (int i = 0, l = strlen(name); i < l; i++)
	{
		if (name[i] != ' ' && name[i - 1] == ' ')
		{
			printf("%c", toupper(name[i]));
		}
	}
	printf("\n");

}

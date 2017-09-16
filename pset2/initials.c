#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char *name; // or char name[100] 
	fgets (name, 100, stdin);

	if (name[0] != ' ')
	{
		printf("%c", toupper(name[0]));
	}
	for (int i = 0, l = strlen(name); i < l; i++)
	{
		if (name[i] != ' ' && name[i - 1] == ' ')
		{
			printf("%c", toupper(name[i]));
		}
	}
	printf("\n");

}

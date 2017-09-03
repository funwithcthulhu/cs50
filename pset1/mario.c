#include <stdio.h>

void left(int times);

int main(void)
{
	int height;
	do
	{
		printf("Height: ");
		scanf("%d", &height);
	}
	while (height > 23);
	for (int i = 0; i < height; i++)
	{
		for (int spaces = height - i; spaces > 0; spaces--)
		{
			printf(" ");
		}
		left(i);
		printf("  ");
		left(i);
		printf("\n");
	}
}

void left(int times)
{
	for (int i = 0; i <= times; i++)
	{
		printf("#");
	}
}


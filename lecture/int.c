#include <stdio.h>

int main(void)
{
	long  n = 1;
	for (int i = 0; i < 64; i++)
	{
		printf("n is %ld\n", n);
		n *= 2;
	}
}


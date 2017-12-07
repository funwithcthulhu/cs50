#include <stdio.h>
#include <stdlib.h>

int collatz(int input, int steps);

int main(int argc, char *argv[])
{
	if (argc != 2)
		exit(1);

	char *p;
	int input = strtol(argv[1], &p, 10);
	int steps = 0;
	printf("%i\n", collatz(input, steps));
}

int collatz(int n, int steps)
{
	if (n == 1)
	{
		return steps;
	}
	if (n % 2 == 0)
	{
		return collatz(n / 2, steps + 1);
	}
	if (n ^ 1)
	{
		return collatz(3 * n + 1, steps + 1);
	}
}
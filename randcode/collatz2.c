#include <stdio.h>
#include <stdlib.h>

int collatz(int input);

int main(int argc, char *argv[])
{
	if (argc != 2)
		exit(1);

	char *p;
	int input = strtol(argv[1], &p, 10);
	printf("%i\n", collatz(input));
}

int collatz(int n)
{
	if (n == 1)
		return 0;
	if (n % 2 == 0)
		return 1 + collatz(n / 2);
	if (n ^ 1)
		return 1 + collatz(3 * n + 1);
}
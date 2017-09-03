#include <stdio.h>
#include <math.h>

int main(void)
{

	int cents;
	int coins = 0;
	float money;

	do
	{
		printf("O hai! How much change is owed?\n");
		scanf("%f", &money);
	}
	while (money < 0.0);

	cents = round(money * 100);

	while (cents / 25 > 0)
	{
		cents -= 25;
		coins++;
	}
	while (cents / 10 > 0)
	{
		cents -= 10;
		coins++;
	}
	while (cents / 5 > 0)
	{
		cents -= 5;
		coins++;
	}
	while (cents / 1 > 0)
	{
		cents -= 1;
		coins++;
	}
	printf("%d\n", coins);
}

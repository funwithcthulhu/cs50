#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	long cc_number;
	int checksum = 0;
	int sum = 0;
	int check = 0;
	long long dup;
	bool validated;

	do
	{
		printf("Number: ");
		scanf("%ld", &cc_number);
	}
	while (cc_number < 0);

	dup = cc_number;

	for (int i = 0; i < 10; i++)
	{
		check = (dup / 10 % 10) * 2;
		if (check > 9)
		{
			check = check - 10;
			sum = sum + 1 + check;
		}
		else if (check > 19)
		{
			check = check - 20;
			sum = sum + 2 + check;
		}
		else
		{
			sum = sum + check;
		}
		dup = dup / 100;
	}
	dup = cc_number;

	for (int i = 0; i < 10; i++)
	{
		checksum = dup % 10;
		dup = dup / 100;
		sum = sum + checksum;
	}

	if (sum % 10 == 0)
	{
		validated = true;
	}
	else
	{
		validated = false;
	}

	if (validated == true && cc_number >= 5100000000000000 && cc_number <= 5599999999999999)
	{
		printf("MASTERCARD\n");
	}
	else if (validated == true && cc_number >= 340000000000000 && cc_number <= 379999999999999)
	{
		printf("AMEX\n");
	}
	else if (validated == true && ((cc_number >= 4000000000000 && cc_number <= 4999999999999) || (cc_number >= 4000000000000000 && cc_number <= 4999999999999999)))
	{
		printf("VISA\n");
	}
	else
	{
		printf("INVALID\n");
	}
	return 0;
}

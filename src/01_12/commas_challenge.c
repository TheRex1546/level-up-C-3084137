#include <stdio.h>

char *commas(int input)
{
	static char output[14];
	char *ptr;
	int digits[10];
	output[13] = '\0';

	/*
	for (int i = 0; i < 10; i++)
	{
		digits[i] = (input / (int)pow(10, 9 - i)) % 10;
	}
	*/

	// replace with pow() loop when linking works again
	if (1)
	{
		digits[0] = input % 10;
		digits[1] = (input / 10) % 10;
		digits[2] = (input / 100) % 10;
		digits[3] = (input / 1000) % 10;
		digits[4] = (input / 10000) % 10;
		digits[5] = (input / 100000) % 10;
		digits[6] = (input / 1000000) % 10;
		digits[7] = (input / 10000000) % 10;
		digits[8] = (input / 100000000) % 10;
		digits[9] = (input / 1000000000) % 10;
	}

	int k = 0;
	for (int i = 12; i >= 0; i--)
	{
		if (i == 1 || i == 5 || i == 9)
			output[i] = ',';
		else
		{
			output[i] = digits[k] + 48;
			k++;
		}
	}

	// clip string
	int offset;
	int clip = 0;
	for (int i = 9; i >= 0; i--)
	{
		if (digits[9] == 0)
			clip = 1;
		if (clip && digits[i] != 0)
		{
			if (i <= 2)
			{
				ptr = &output[12 - i];
				return ptr;
			}
			else if (i <= 5)
			{
				ptr = &output[11 - i];
				return ptr;
			}
			else if (i <= 8)
			{
				ptr = &output[10 - i];
				return ptr;
			}
		}
		else if (clip && i == 0)
			return "0!";
	}
	return output;
}

int main()
{
	int values[10] = {
			123, 1899, 48266, 123456, 9876543,
			10100100, 5, 500000, 99000111, 83};

	for (int i = 0; i < 10; i++)
	{
		printf("%d -> ", values[i]);
		printf("%s\n", commas(values[i]));
	}
	return (0);
}

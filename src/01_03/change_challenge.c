#include <stdio.h>
#include <math.h>

int main()
{
	int nquarter, ndime, nnickel, npenny, coins;
	float value[] = {0.49, 1.27, 0.75, 1.31, 0.83};

	for (int i = 0; i < 5; i++)
	{
		// get truncated quotient without decimal
		nquarter = value[i] / 0.25;
		ndime = (value[i] - (nquarter * 0.25)) / 0.1;
		nnickel = ((value[i] - (nquarter * 0.25)) - (ndime * 0.1)) / 0.05;

		// rounding for precision error
		float num = (((value[i] - (nquarter * 0.25)) - (ndime * 0.1)) - (nnickel * 0.05)) / 0.01;
		npenny = (int)(num < 0 ? (num - 0.5) : (num + 0.5));

		coins = nquarter + ndime + nnickel + npenny;

		printf("The change of %.2f uses %d quarters, %d dimes, %d nickels and %d pennies = %d total coins\n",
					 value[i], nquarter, ndime, nnickel, npenny, coins);
	}

	return (0);
}

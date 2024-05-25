#include <stdio.h>

char *ordinal(int v)
{
	int mod = v % 10;
	if (v == 11 || v == 12 || v == 13)
	{
		return ("th");
	}
	switch (mod)
	{
	case 1:
		return ("st");
	case 2:
		return ("nd");
	case 3:
		return ("rd");
	default:
		return ("th");
	}
}

int main()
{
	int c;

	/* output a table of 100 numbers */
	for (c = 1; c <= 20; c++)
	{
		printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",
					 c, ordinal(c),
					 c + 20, ordinal(c + 20),
					 c + 40, ordinal(c + 40),
					 c + 60, ordinal(c + 60),
					 c + 80, ordinal(c + 80));
	}

	return (0);
}

#include <stdio.h>
#include <stdlib.h>

char *left(char *s, int len)
{
	char *chop;
	int strl = 0;

	// get string length, excluding null
	for (int i = 0; s[i] != '\0'; i++)
	{
		strl++;
	}
	if (strl < len)
	{
		len = strl;
	}
	chop = malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		*(chop + i) = s[i];
	}
	*(chop + len) = '\0';

	return chop;
}

char *right(char *s, int len)
{
	char *chop;
	int strl = 0;

	// get string length, excluding null
	for (int i = 0; s[i] != '\0'; i++)
	{
		strl++;
	}
	if (strl < len)
	{
		len = strl;
	}
	chop = malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		*(chop + i) = s[strl - len + i];
	}
	*(chop + len) = '\0';

	return chop;
}

char *mid(char *s, int offset, int len)
{
	char *chop;
	int strl = 0;

	// get string length, excluding null
	for (int i = 0; s[i] != '\0'; i++)
	{
		strl++;
	}
	if (strl < len + offset)
	{
		len = strl - offset;
	}
	chop = malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		*(chop + i) = s[offset + i];
	}
	*(chop + len) = '\0';

	return chop;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n", string);
	printf("Left %d characters: %s\n", 16, left(string, 16));
	printf("Right %d characters: %s\n", 18, right(string, 18));
	printf("Middle %d characters: %s\n", 11, mid(string, 12, 11));

	return (0);
}

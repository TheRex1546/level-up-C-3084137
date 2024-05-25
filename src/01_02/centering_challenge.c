#include <stdio.h>
#include <string.h>

void center_text(int width, char *text)
{
	int length = strlen(text);
	int offset;

	// calculate actual offset needed to shift string to middle
	offset = (width - length) / 2;

	for (int i = 0; i < offset; i++)
	{
		putchar(' ');
	}
	printf("%s\n", text);
}

int main()
{
	/* some sample text to center */
	char *title[] = {
			"March Sales",
			"My First Project",
			"Centering output is so much fun!",
			"This title is very long, just to see whether the code can handle such a long title"};
	int x;

	/* output each of the strings, centered */
	for (x = 0; x < 4; x++)
	{
		/* assume the screen width to be 80 characters */
		center_text(80, title[x]);
	}

	return (0);
}

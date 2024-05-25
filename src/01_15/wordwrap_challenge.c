#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40

int main(int argc, char *argv[])
{
	/* Shakespeare's 18th Sonnet */
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";
	int line_len = W_DEFAULT;

	if (argc > 1 && strlen(argv[1]) == 3)
		line_len = (*argv[1] - 48) * 100 + (*(argv[1] + 1) - 48) * 10 + (*(argv[1] + 2) - 48);
	else if (argc > 1 && strlen(argv[1]) == 2)
		line_len = (*argv[1] - 48) * 10 + (*(argv[1] + 1) - 48);
	else if (argc > 1 && strlen(argv[1]) == 1)
		line_len = (*argv[1] - 48);
	if (line_len < W_MIN || line_len > W_MAX)
	{
		line_len = W_DEFAULT;
		printf("Wrap width out of bounds (16-100), Defaulted to %d characters!", W_DEFAULT);
	}
	else
		printf("%d wrap width was input!\n", line_len);
	for (int i = 0; i < line_len; i++)
	{
		putchar('-');
	}
	putchar('\n');

	int space_taken = 0;
	int word_length = 0;

	for (int i = 0, count = 1; text[i] != '\0'; i++, count++)
	{
		// count word length and reset at a space
		if (text[i] == ' ' || text[i] == '\n')
		{
			word_length = count - 1;
			count = 0;
		}

		// check word and space left
		if (word_length > 0 && text[i] == ' ')
		{
			if (word_length + space_taken > line_len)
			{
				putchar('\n');
				space_taken = word_length + 1;
				for (int k = i - word_length; k <= i; k++)
					putchar(text[k]);
			}
			else if (word_length + space_taken < line_len)
			{
				space_taken = space_taken + word_length + 1;
				for (int k = i - word_length; k <= i; k++)
					putchar(text[k]);
			}
			else if (word_length + space_taken == line_len)
			{
				space_taken = line_len;
				for (int k = i - word_length; k < i; k++)
					putchar(text[k]);
			}
			word_length = 0;
		}
		else if (word_length > 0 && text[i] == '\n')
		{
			if (word_length + space_taken > line_len)
				putchar('\n');
			space_taken = 0;
			for (int k = i - word_length; k <= i; k++)
				putchar(text[k]);
			word_length = 0;
		}
	}
	putchar('\n');

	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PSIZE 20

int main()
{
	char *playlist[PSIZE] = {
			"Like a Rolling Stone", "Satisfaction", "Imagine",
			"What's Going On", "Respect", "Good Vibrations",
			"Johnny B. Goode", "Hey Jude", "What'd I Say",
			"Smells Like Teen Spirit", "My Generation",
			"Yesterday", "Blowin' in the Wind", "Purple Haze",
			"London Calling", "I Want to Hold Your Hand",
			"Maybellene", "Hound Dog", "Let It Be",
			"A Change Is Gonna Come"};
	int frequency[PSIZE];
	int x, r, count, quit;
	char *prevbuffer[15];
	for (int i = 0; i < 15; i++)
		prevbuffer[i] = "N/A";

	/* initialize */
	srand((unsigned)time(NULL));
	for (x = 0; x < PSIZE; x++)
		frequency[x] = 0;

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < 100)
	{
		// ensure song is not repeated
		quit = 0;
		while (quit == 0)
		{
			r = rand() % PSIZE;
			for (int i = 0; i < 15; i++)
			{
				if (strcmp(prevbuffer[i], playlist[r]) == 0)
				{
					quit = 0;
					break;
				}
				quit = 1;
			}
		}

		printf("%3d: Now Playing '%s'\n", count + 1, playlist[r]);
		frequency[r]++;

		// insert valid song into buffer
		for (int i = 14; i >= 0; i--)
		{
			if (i == 0)
			{
				prevbuffer[i] = playlist[r];
				break;
			}
			prevbuffer[i] = prevbuffer[i - 1];
		}

		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	return (0);
}

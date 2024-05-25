#include <stdio.h>
#include <string.h>

int main()
{
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char temp[27];
  int count, nshuffles;
  nshuffles = 0;

  strcpy(temp, alphabet);

  while (1)
  {
    count = 0;
    // single perfect shuffle 0-12, 13-25
    for (int i = 1; i < 25; i++)
    {
      if ((i % 2) != 0)
      {
        temp[i] = alphabet[13 + count];
        count++;
      }
      else
      {
        temp[i] = alphabet[i / 2];
      }
    }
    strcpy(alphabet, temp);
    nshuffles++;

    if (strcmp(temp, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0)
    {
      break;
    }
  }
  printf("%d shuffles were done!\n", nshuffles);

  return 0;
}

/* PATTERN
    alphabet[1] = alphabet[13];
    alphabet[2] = alphabet[1];
    alphabet[3] = alphabet[14];
    alphabet[4] = alphabet[2];
    alphabet[5] = alphabet[15];
    alphabet[6] = alphabet[3];
    alphabet[7] = alphabet[16];
    ...
*/
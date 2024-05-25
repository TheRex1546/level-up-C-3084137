#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int count, movenum;
  // King start position: 4th row, 5th column
  int Krow = 3;
  int Kcol = 4;
  count = 0;

  srand((unsigned)time(NULL));

  while (!(Krow < 0 || Krow > 7 || Kcol < 0 || Kcol > 7))
  {
    // Draw board, from start to last position before illegal move
    for (int i = 7; i >= 0; i--)
    {
      for (int j = 0; j < 8; j++)
      {
        if (i == Krow && j == Kcol)
        {
          printf("K ");
        }
        else
        {
          printf("# ");
        }
      }
      putchar('\n');
    }
    putchar('\n');

    movenum = rand() % 9;
    switch (movenum)
    {
    case 0: // do nothing
      break;
    case 1: // TL
      Krow += 1;
      Kcol -= 1;
      break;
    case 2: // TM
      Krow += 1;
      break;
    case 3: // TR
      Krow += 1;
      Kcol += 1;
      break;
    case 4: // ML
      Kcol -= 1;
      break;
    case 5: // MR
      Kcol += 1;
      break;
    case 6: // BL
      Krow -= 1;
      Kcol -= 1;
      break;
    case 7: // BM
      Krow -= 1;
      break;
    case 8: // BR
      Krow -= 1;
      Kcol += 1;
      break;
    }
    count++;
  }

  printf("King moved outside in %d turns + turn-skips\n", count);

  return 0;
}
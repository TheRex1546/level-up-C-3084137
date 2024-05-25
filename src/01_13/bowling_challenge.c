#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bowl(int pins)
{
  int score;

  score = rand() % (pins + 1);

  return score;
}

int main()
{
  int fst_bowl, snd_bowl, score;

  srand((unsigned)time(NULL));

  fst_bowl = bowl(10);

  printf("You knocked down %d pin/s on the first bowl!\n", fst_bowl);
  if (fst_bowl == 10)
    puts("Strike!!!\n");
  else if (fst_bowl == 0)
    puts("Gutterball! Try Again!\n");
  else
    printf("%d pin/s left! Get Ready for the second bowl!\n", 10 - fst_bowl);
  putchar('\n');

  snd_bowl = bowl(10 - fst_bowl);

  if (fst_bowl != 10)
  {
    printf("You knocked down %d pin/s on the second bowl!\n", snd_bowl);
    if (snd_bowl == 10 - fst_bowl)
    {
      puts("Spare!!\n");
      puts("Frame Score: 10 + next bowl\n");
    }
    else
    {
      printf("%d pin/s remained! Unlucky :(\n", 10 - fst_bowl - snd_bowl);
      printf("Frame Score: %d\n", fst_bowl + snd_bowl);
    }
  }
  else
  {
    puts("Frame Score: 10 + next two bowls\n");
  }
  puts("Frame over!\n");

  return 0;
}
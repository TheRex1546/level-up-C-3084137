#include <stdio.h>

int main()
{
  int i, start;

  printf("Enter hailstone sequence first number: ");
  scanf("%d", &start);
  printf("%d ", start);


  i = 1;
  while (1)
  {
    i++;
    start % 2 ? (start = start * 3 + 1) : (start /= 2);
    printf(" %d ", start);
    if (start == 1)
    {
      putchar('\n');
      printf("Hailstone sequence length: %d\n", i);
      break;
    }
  }
  

  return 0;
}
#include <stdio.h>

int leapyear(int year)
{
  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 1;
    }
  }
  else
  {
    return 0;
  }
}

int main()
{
  puts("Leap years since 1582: ");
  for (int i = 1582; i <= 2101; i++)
  {
    if (leapyear(i) == 1)
    {
      printf("%d ", i);
    }
  }

  return 0;
}
#include <stdio.h>

// 1.618...
double goldenRatio(double a, int i)
{
  double GR;
  GR = 1.0 + 1.0 / a;
  i++;
  if (i > 30)
  {
    return;
  }
  return goldenRatio(GR, i);
}

int main()
{
  double golden = goldenRatio(1, 0);

  printf("Golden Ratio = %.9lf\n", golden);

  return 0;
}
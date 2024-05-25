#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// input the original 2D array and its dimensions, return the 90 deg rotated 2D array
char **rotateArray(char *orgArray, int orgRows, int orgCols)
{
  char **newArray;
  int srows = orgCols;
  int scols = orgRows;

  // allocate memory to address of row pointers, given 'srows' in the grid
  newArray = malloc(sizeof(char *) * srows);
  if (newArray == NULL)
  {
    exit(1);
  }
  
  // allocate memory to address of each row, given 'scols' elements/columns per row
  for (int i = 0; i < srows; i++)
  {
    *(newArray + i) = malloc(sizeof(char *) * scols);
  }

  // rotate
  for (int i = 0; i < srows; i++)
  {
    for (int j = 0; j < scols; j++)
      *(*(newArray + i) + j) = *(orgArray + (orgRows - 1 - j) * orgCols + i);
  }
  return newArray;
}

int main()
{
  // 8x3 Matrix
  char array83[8][3];
  // 5x5 Matrix
  char array55[5][5];
  // 4x6 Matrix
  char array46[4][6];

  srand((unsigned)time(NULL));

  // fill arrays, NOTE i = 0 indicates topmost row
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      array83[i][j] = rand() % 26 + 'a';
    }
  }
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
      array55[i][j] = rand() % 26 + 'a';
  }
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 6; j++)
      array46[i][j] = rand() % 26 + 'a';
  }

  // print arrays
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 3; j++)
      printf("%c ", array83[i][j]);
    putchar('\n');
  }
  putchar('\n');

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
      printf("%c ", array55[i][j]);
    putchar('\n');
  }
  putchar('\n');

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 6; j++)
      printf("%c ", array46[i][j]);
    putchar('\n');
  }
  putchar('\n');

  puts("Rotated 90 degrees clockwise:");

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 8; j++)
      printf("%c ", rotateArray(array83[0], 8, 3)[i][j]);
    putchar('\n');
  }
  putchar('\n');

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
      printf("%c ", rotateArray(array55[0], 5, 5)[i][j]);
    putchar('\n');
  }
  putchar('\n');

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 4; j++)
      printf("%c ", rotateArray(array46[0], 4, 6)[i][j]);
    putchar('\n');
  }
  putchar('\n');

  return 0;
}
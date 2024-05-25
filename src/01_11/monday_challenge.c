#include <stdio.h>

char *ordinal(int v)
{
  int mod = v % 10;
  if (v == 11 || v == 12 || v == 13)
  {
    return ("th");
  }
  switch (mod)
  {
  case 1:
    return ("st");
  case 2:
    return ("nd");
  case 3:
    return ("rd");
  default:
    return ("th");
  }
}

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

int weekday(int day, int month, int year)
{
  int month_code[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  int century_code[] = {4, 2, 0, 6, 4, 2, 0};
  int y1y2 = ((year / 1000) % 10) * 10 + ((year / 100) % 10);
  int y3y4 = ((year / 10) % 10) * 10 + (year % 10);
  int leap_code = (month == 1 || month == 2) ? -1 : 0;
  int wDay = (((y3y4 + (y3y4 / 4)) % 7) + month_code[month - 1] + century_code[y1y2 - 17] + day + leap_code) % 7;
}

int main()
{
  int wDay, day, mDay, month, mMonth, year;
  char date[11];
  char *month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  char *day_str[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

  printf("Enter date as dd/mm/yyyy: ");
  scanf("%s", &date);
  putchar('\n');

  // convert characters to numerical dates
  year = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9] - 53328;
  month = date[3] * 10 + date[4] - 528;
  day = date[0] * 10 + date[1] - 528;

  // catch invalid dates
  if (!(day < 1 || day > 31 || month < 1 || month > 12 || year < 1700 || year > 2398))
  {
    if (month == 2 && leapyear(year) && (day > 29))
    {
      puts("INVALID DATE ENTERED! TRY AGAIN");
      return 1;
    }
    else if (month == 2 && !leapyear(year) && (day > 28))
    {
      puts("INVALID DATE ENTERED! TRY AGAIN");
      return 1;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
    {
      puts("INVALID DATE ENTERED! TRY AGAIN");
      return 1;
    }
  }
  else
  {
    puts("INVALID DATE ENTERED! TRY AGAIN");
    return 1;
  }

  mMonth = month;
  wDay = weekday(day, month, year);

  mDay = day + (8 - wDay);
  if (month == 2)
  {
    if (leapyear(year))
    {
      if (mDay > 29)
      {
        mDay -= 29;
        mMonth = month + 1;
      }
    }
    else
    {
      if (mDay > 28)
      {
        mDay -= 28;
        mMonth = month + 1;
      }
    }
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11) // 30 day months
  {
    if (mDay > 30)
    {
      mDay -= 30;
      mMonth = month + 1;
    }
  }
  else // 31 day months
  {
    if (mDay > 31)
    {
      mDay -= 31;
      mMonth = (month == 12) ? 1 : (month + 1);
    }
  }

  printf("Today is %s, %s %d%s, %d\n", day_str[wDay - 1], month_str[month - 1], day, ordinal(day), year);
  printf("Next Monday will be on the %d%s of %s\n", mDay, ordinal(mDay), month_str[mMonth - 1]);
  return 0;
}
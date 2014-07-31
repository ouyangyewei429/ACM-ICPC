/*
PROG:   小Q系列故事——世界上最遥远的距离
Author: ouyangyewei
*/
#include <stdio.h>

int MONTH[] = {0, 31, 28, 31, 30, 31, 30,
              31, 31, 30, 31, 30, 31};

int cYear, cMonth, cDay;

void Init()
{
  cYear = 2013;
  cMonth = 3;
  cDay = 24;
}

int IsLeapYear(int year)
{
  return ((0==year%4 && 0!=year%100)
          || (0==year%400));
}

void DayForward(int diff)
{
  Init();
  while (diff--)
  {
    cDay++;
    MONTH[2] = 28 + IsLeapYear(cYear);
    if (cDay > MONTH[cMonth])
    {
      cDay = 1;
      cMonth++;
      if (cMonth > 12)
      {
        cMonth = 1;
        cYear++;
      }
    }
  }// End of while
  printf("%04d/%02d/%02d", cYear, cMonth, cDay);
}

void DayBackward(int diff)
{
  Init();
  while (diff--)
  {
    cDay--;
    MONTH[2] = 28 + IsLeapYear(cYear);
    if (0 == cDay)
    {
      cMonth--;
      if (cMonth < 1)
      {
        cMonth = 12;
        cYear--;
      }
      cDay = MONTH[cMonth];
    }
  }// End of while
  printf("%04d/%02d/%02d", cYear, cMonth, cDay);
}

int main(void)
{
  int diff = 0;
  int nCases = 0;

  scanf("%d", &nCases);
  while (nCases--)
  {
    scanf("%d", &diff);

    DayForward(diff);
    printf(" ");
    DayBackward(diff);
    printf("\n");
  }// End of while

  return 0;
}

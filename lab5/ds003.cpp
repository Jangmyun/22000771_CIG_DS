#include <iostream>
#include <cstdio>
using namespace std;

int checkMonth(int month);

int main()
{
  int month, day;
  int day_count = 0;

  scanf("%d %d", &month, &day);
  cout << month << day << endl;

  for (int i = 1; i < month; i++)
  {
    day_count += checkMonth(i);
  }
  day_count += day;
  cout << day_count << endl;
  return 0;
}

int checkMonth(int month)
{
  if (month == 2)
  {
    return 28;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    return 30;
  }
  else
  {
    return 31;
  }
  return -1;
}
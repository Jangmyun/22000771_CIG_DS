#include <iostream>
#include <cstdio>
using namespace std;

int checkMonth(int month);

int main()
{
  int month, day;
  int day_count = 0;

  scanf("%d %d", &month, &day); // 날짜 입력받기

  for (int i = 1; i < month; i++) // 1월부터 month-1까지 날짜 더하기
  {
    day_count += checkMonth(i);
  }
  day_count += day; // 마지막 달은 일수 더하기
  cout << day_count << endl;
  return 0;
}

int checkMonth(int month) // 달을 전달받으면 달에 맞는 일수를 리턴하는 함수
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
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int height, weight;
  double bmi;

  scanf("%d %d", &height, &weight);
  double heightM = (double)height / 100; // m단위로 변환
  bmi = weight / (heightM * heightM);    // bmi 연산

  if (bmi >= 25) // bmi 25 이상이면 yes, 아니면 no 출력
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
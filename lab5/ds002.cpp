#include <iostream>
#include <cstdio>
#include <cmath> // cmath 라이브러리
using namespace std;

int main()
{
  double x1, y1;
  double x2, y2;

  scanf("%lf %lf", &x1, &y1);
  scanf("%lf %lf", &x2, &y2);

  double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // 두 점의 거리  = (x좌표 차이의 제곱 + y좌표 차이의 제곱 ) 의 루트

  printf("%.1lf\n", result); // 소수점 1자리 까지 프린트

  return 0;
}
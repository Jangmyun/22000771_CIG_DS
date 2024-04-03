#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  double x1, y1;
  double x2, y2;

  scanf("%lf %lf", &x1, &y1);
  scanf("%lf %lf", &x2, &y2);

  double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  printf("%.1lf\n", result);

  return 0;
}
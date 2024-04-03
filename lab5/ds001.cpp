#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int height, weight;
  double bmi;
  scanf("%d %d", &height, &weight);
  double heightM = (double)height / 100;
  bmi = weight / (heightM * heightM);

  if (bmi >= 25)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
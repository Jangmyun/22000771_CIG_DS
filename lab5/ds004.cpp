#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

struct st_score
{
  int kor, eng, math;
  int total;
  double average;
};

string checkPass(int score)
{
  if (score >= 70)
  {
    return "Pass";
  }
  return "Fail";
}

int main()
{
  st_score s;
  scanf("%d %d %d", &(s.kor), &(s.eng), &(s.math));
  s.total = s.kor + s.eng + s.math;
  s.average = (double)s.total / 3;

  cout << s.total << " " << fixed << setprecision(1) << s.average << endl;
  cout << "Korean - " << checkPass(s.kor) << endl;
  cout << "English - " << checkPass(s.eng) << endl;
  cout << "Math - " << checkPass(s.math) << endl;

  return 0;
}

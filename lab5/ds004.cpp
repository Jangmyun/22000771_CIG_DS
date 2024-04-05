#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

struct st_score
{
  int kor, eng, math; // 국영수 점수
  int total;          // 총점
  double average;     // 평균점수
};

string checkPass(int score) // 성적을 입력받으면 pass인지 체크해서 pass또는 fail 문자열을 리턴하는 함수
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

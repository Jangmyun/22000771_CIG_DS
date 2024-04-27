#include <iostream>
using namespace std;

class Student {
 private:
  double getAvg()
      const;  // const => 객체 내부 변수 변경 불가 & const 함수만 호출 가능

 public:
  string name;
  string sid;
  int *score;  // 국영수 점수 받을 포인터 멤버 변수
  void print() const;
};

void Student::print() const {
  cout << "[" << sid << "] " << name << endl;
  cout << fixed;  // 소수점 한자리 제한해서 출력
  cout.precision(1);
  cout << "The Average score is " << getAvg() << endl;
}
double Student::getAvg() const {
  double avg;
  int sum = 0;
  for (int i = 0; i < 3; i++) {  // score 포인터 멤버변수를 배열처럼 사용
    sum += score[i];
  }
  avg = (double)sum / 3;
  return avg;
}

int main() {
  int score[3];
  string sid;
  string sName;
  cin >> sid >> score[0] >> score[1] >> score[2];
  getline(cin >> ws, sName);
  Student s1;
  s1.name = sName;
  s1.sid = sid;
  s1.score = score;

  s1.print();

  return 0;
}

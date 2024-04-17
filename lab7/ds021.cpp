#include <iostream>
using namespace std;

class Student {
 private:
  double getAvg() const;

 public:
  string name;
  string sid;
  int *score;
  void print() const;
};

void Student::print() const {
  cout << '[' << sid << "] " << name << endl;
  cout << fixed;
  cout.precision(1);
  cout << "The Average score is " << getAvg() << endl;
}
double Student::getAvg() const {
  double avg;
  int sum = 0;
  for (int i = 0; i < 3; i++) {
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

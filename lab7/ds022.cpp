#include <iostream>
using namespace std;

class EnglishScore {
 private:
  string sName;
  int rcScore, lcScore;
  int total;

 public:
  EnglishScore();
  bool isInvalidScore(int score);
  void print();
  bool isPass(int score);
  void setScore();
  void setName();
};

EnglishScore::EnglishScore() {
  sName = "Hong gil-dong";
  lcScore = 0;
  rcScore = 0;
  total = 0;
}

bool EnglishScore::isInvalidScore(int score) {
  if (0 <= score && score <= 495) {
    return false;
  }
  return true;
}

bool EnglishScore::isPass(int score) {
  if (score >= 350) {
    return true;
  }
  return false;
}

void EnglishScore::setScore() {
  int lc = 0, rc = 0;

  do {
    cout << "LC> ";
    cin >> lc;
  } while (isInvalidScore(lc));

  do {
    cout << "RC> ";
    cin >> rc;
  } while (isInvalidScore(rc));

  rcScore = rc;
  lcScore = lc;

  total = rcScore + lcScore;
}

void EnglishScore::setName() {
  string nameInput;
  getline(cin >> ws, nameInput);

  sName = nameInput;
}

void EnglishScore::print() {
  cout << "[" << sName << "] " << endl;
  string lcPass = isPass(lcScore) ? "Pass" : "Fail";
  string rcPass = isPass(rcScore) ? "Pass" : "Fail";
  cout << "LC - " << lcScore << " " << lcPass << endl;
  cout << "RC - " << rcScore << " " << rcPass << endl;
  cout << "Total - " << total << endl;
}

int main() {
  EnglishScore es1;
  es1.setName();
  es1.setScore();
  es1.print();
  return 0;
}

#include <iostream>
using namespace std;

class StudentEnglish {
 private:
  string name;
  int LC, RC;

 public:
  StudentEnglish() {  // 기본생성자
    this->name = "No name";
    this->LC = 0;
    this->RC = 0;
  }
  StudentEnglish(int a) {  // 입력받는 생성자
    setName();
    setLC();
    setRC();
  }
  StudentEnglish(string name, int LC, int RC) {  // 매개변수 받는 생성자
    this->name = name;
    this->LC = LC;
    this->RC = RC;
  }

  void setName() {  // 이름 입력받기
    string name;
    getline(cin, name);
    this->name = name;
  }
  bool isValidScore(int score) {  // 입력받은 점수값이 올바른 값인지 확인
    if (0 <= score && score <= 495) {
      return true;
    }
    return false;
  }

  string checkPass(int score) {  // pass fail 여부를 확인해서 string 리턴
    if (score >= 350) {
      return "Pass";
    }
    return "Fail";
  }

  void setLC() {  // lc점수 입력
    int LC = 0;
    do {
      cout << "LC> ";
      cin >> LC;
    } while (!isValidScore(LC));
    this->LC = LC;
  }

  void setRC() {  // rc점수 입력
    int RC = 0;
    do {
      cout << "RC> ";
      cin >> RC;
    } while (!isValidScore(RC));
    this->RC = RC;
  }

  int getTotal() { return LC + RC; }  // total값 리턴

  void printInfo() {  // 이름/점수/합계 출력
    cout << "[" << this->name << "]" << endl;
    cout << "LC - " << this->LC << " " << checkPass(LC) << endl;
    cout << "RC - " << this->RC << " " << checkPass(RC) << endl;
    cout << "Total - " << getTotal() << endl;
  }
};

int main() {
  StudentEnglish s(1);  // 입력받는 생성자
  s.printInfo();        // 입력받은 정보 출력
  return 0;
}
#include <fstream>
#include <iostream>
using namespace std;

struct Element {
  string name;
  double gpa;
};

class MyStack {
 private:
  int maxsize;
  int top;
  Element *list;

 public:
  void initialize() { top = 0; }
  bool isEmpty() const { return (top == 0) ? true : false; }
  bool isFull() const { return (top == maxsize) ? true : false; }
  void push(const Element &e) {
    if (isFull()) return;
    list[top] = e;
    top++;
  }

  Element *pop() {
    if (isEmpty()) return nullptr;
    return &list[--top];
  }

  MyStack(int size = 10) {
    list = new Element[size];
    maxsize = size;
    top = 0;
  }
  ~MyStack() {}
};

// gpa값이 더 큰지 비교하는 함수
int compareGpa(Element s1, Element s2) {
  // s2가 더 크면 1, 같으면 0, 작으면 -1
  if (s1.gpa < s2.gpa) {
    return 1;
  } else if (s1.gpa == s2.gpa) {
    return 0;
  }
  return -1;
}

void printGpa(MyStack s) {
  Element *tmp;
  tmp = s.pop();

  cout << "Top GPA: " << tmp->gpa << endl;
  cout << tmp->name << endl;
  while (!s.isEmpty()) {
    tmp = s.pop();
    cout << tmp->name << endl;
  }
}

void analyzeGPA() {
  fstream f;                      // fstream 객체 생성
  f.open("./gpaData/gpa_2.txt");  // file open
  if (!f.is_open()) {  // file 열리지 않으면 에러메시지 출력
    cout << "File Open Error" << endl;
    return;
  }
  MyStack s(10);  //  stack 생성

  Element standard;
  f >> standard.gpa >> standard.name;  // 처음 값 받아서 push
  s.push(standard);
  Element tmp;
  while (!f.eof()) {           // 파일 끝까지 반복
    f >> tmp.gpa >> tmp.name;  // 다음 줄의 gpa와 이름 읽기

    if (compareGpa(standard, tmp) == 1) {  // 새로받은 GPA가 더 크면
      while (!s.isEmpty()) {  // 모두 pop하고 새로운 gpa element push
        s.pop();
      }
      s.push(tmp);
      standard = tmp;
    } else if (compareGpa(standard, tmp) == 0) {  // gpa값 같으면 push
      s.push(tmp);
    }
  }
  printGpa(s);  // gpa 출력
}

int main() {
  analyzeGPA();

  return 0;
}
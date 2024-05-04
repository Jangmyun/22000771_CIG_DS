#include <iostream>
using namespace std;

struct Element {  // Student 구조체 멤버변수 value
  int value;
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
  ~MyStack() { delete[] list; }
  void print() const {
    for (int i = 0; i < top; i++) {
      cout << list[i].value << endl;
    }
  }
};

void start() {
  int N;  // 스택 list 크기 입력받기
  cin >> N;
  MyStack s(N);  // 입력받은 크기의 list를 가진 스택 s 생성

  string in;               // 명령어 입력받을 변수
  int value;               // 명령어 뒤에 입력될 값
  while (in != "print") {  // 명령어 print가 나올 때 까지 반복
    cin >> in;
    // 명령어가 push면 뒤에 숫자도 읽어서 Element에 값을 넣어 push
    if (in == "push") {
      cin >> value;
      Element t;
      t.value = value;
      s.push(t);
    }
    if (in == "pop") {  // pop 이면 뒤 값 읽지 않고 스택 pop
      s.pop();
    }
    if (in == "print") {  // print면 반복문 종료 후 print() 실행
      break;
    }
  }
  s.print();
}

int main() {
  start();
  return 0;
}
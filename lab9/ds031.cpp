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
  int N;
  cin >> N;
  MyStack s(N);

  string in;
  int value;
  while (in != "print") {
    cin >> in;
    if (in == "push") {
      cin >> value;
      Element t;
      t.value = value;
      s.push(t);
    }
    if (in == "pop") {
      s.pop();
    }
    if (in == "print") {
      break;
    }
  }
  s.print();
}

int main() {
  start();
  return 0;
}
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* link;
  Node(int data) {  // node의 link는 NULL로, data는 입력받은 매개변수로
    this->data = data;
    this->link = NULL;
  }
};

class MyLinkedStack {
 private:
  Node* stacktop;

 public:
  void initialize() {    // stack 초기화 함수
    Node* i = stacktop;  // stacktop 부터 i가 NULL이 아닐때까지 반복
    Node* tmp;
    while (i != NULL) {
      tmp = i;      // tmp에 i주소 저장
      i = i->link;  // i 를 i->link로 변경 후 tmp 메모리 해제
      delete tmp;
    }
    stacktop = NULL;  // 모든 node 메모리 해제 후 stacktop == NULL
  }
  bool isEmpty() const {  // stacktop 이 NULL이면 true리턴
    if (stacktop == NULL) {
      return true;
    }
    return false;
  }
  void push(const Node& n) {
    Node* newNode = new Node(n.data);
    if (isEmpty()) {
      stacktop = newNode;
      return;
    }
    newNode->link = stacktop;
    stacktop = newNode;
  }
  void pop() {
    Node* t;
    t = stacktop;
    stacktop = stacktop->link;
    delete t;
  }
  Node peek() const {
    cout << stacktop->data << endl;
    return *stacktop;
  }
  int getNodeCnt() const {
    Node* i;
    int count = 0;
    for (i = stacktop; i != NULL; i = i->link) {
      count++;
    }
    return count;
  }

  MyLinkedStack(int size = 10) { stacktop = NULL; }

  ~MyLinkedStack() {
    Node* i = stacktop;
    Node* tmp;
    while (i != NULL) {
      tmp = i;
      i = i->link;
      delete tmp;
    }
  }
  void printAll() {
    Node* i;
    for (i = stacktop; i != NULL; i = i->link) {
      if (i->link == NULL) {
        cout << i->data << " ";
      } else {
        cout << i->data << " -> ";
      }
    }
    cout << "(" << getNodeCnt() << " nodes)" << endl;
  }
};

void manageStack() {
  MyLinkedStack s;
  string input = "";
  int value;

  while (input != "q") {
    cin >> input;
    if (input == "push") {
      cin >> value;
      Node a(value);
      s.push(a);
    }
    if (input == "pop") {
      s.pop();
    }
    if (input == "peek") {
      s.peek();
    }
    if (input == "clear") {
      s.initialize();
    }
    if (input == "print") {
      if (s.isEmpty()) {
        cout << "Stack is empty" << endl;
        continue;
      }
      s.printAll();
    }
  }
  cout << "Bye!" << endl;
}

int main() {
  manageStack();

  return 0;
}

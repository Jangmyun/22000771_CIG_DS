#include <iostream>
using namespace std;

class Node {
 public:
  char data;
  Node* link;
  Node(char data) {  // node의 link는 NULL로, data는 입력받은 매개변수로
    this->data = data;
    this->link = NULL;
  }
};

class MyLinkedStack {
 private:
  Node* stacktop;

 public:
  MyLinkedStack();
  ~MyLinkedStack();
  void initialize();
  bool isEmpty() const;
  // bool isFull() const;
  void push(const char& c);
  void pop();
  char peek() const;
  int getNodeCnt() const;
  void printAll();
};
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
  void initialize();
  bool isEmpty() const;
  void push(const Node& n);
  void pop();
  Node peek() const;
  int getNodeCnt() const;
  MyLinkedStack();
  ~MyLinkedStack();
  void printAll();
};
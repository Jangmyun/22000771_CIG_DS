#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* link;
  Node(int data) {
    this->data = data;
    this->link = NULL;
  }
};

class LinkedListQ {
 private:
  Node *front, *rear;

 public:
  LinkedListQ();
  ~LinkedListQ();
  void initialize();
  bool isEmpty() const;
  void enqueue(const int& data);
  void dequeue();
  int Rear() const;
  int Front() const;
  void printAll() const;
};
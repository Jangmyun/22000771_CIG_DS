#include <iostream>
using namespace std;

template <typename T>
class MyCircularQueue {
  int maxsize;
  int front;
  int rear;
  T* list;

 public:
  void initialize();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(const T&);
  void dequeue();
  T Front();
  T Rear();
  MycircularQueue(int size = 10);
  ~MyCircularQueue();
  void print();
};

int main() { return 0; }
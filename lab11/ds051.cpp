#include <iostream>
using namespace std;

template <typename T>
class MyCircularQueue {
 private:
  int maxsize;
  int front;
  int rear;
  T* list;

 public:
  void initialize();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(const T& elem);
  void dequeue();
  T Front();
  T Rear();
  MyCircularQueue(int size = 10);
  ~MyCircularQueue();
  void print() const;
  int size() const;
  void printDetail() const;
};

template <typename T>
MyCircularQueue<T>::MyCircularQueue(int size) {
  list = new T[size];
  maxsize = size;
  front = 0;
  rear = 0;
}

template <typename T>
MyCircularQueue<T>::~MyCircularQueue() {
  delete[] list;
}

template <typename T>
void MyCircularQueue<T>::initialize() {
  maxsize = 0;
  front = 0;
  rear = 0;
}

template <typename T>
bool MyCircularQueue<T>::isFull() const {
  if ((rear + 1) % maxsize == front) {
    return true;
  }
  return false;
}

template <typename T>
bool MyCircularQueue<T>::isEmpty() const {
  if (rear == front) {
    return true;
  }
  return false;
}

template <typename T>
void MyCircularQueue<T>::enqueue(const T& elem) {
  if (!isFull()) {
    list[rear] = elem;
    rear = (rear + 1) % maxsize;
    return;
  }
  cout << "Queue is Full !" << endl;
}

template <typename T>
void MyCircularQueue<T>::dequeue() {
  if (!isEmpty()) {
    front = (front + 1) % maxsize;
    return;
  }
  cout << "Queue is empty ! " << endl;
}

template <typename T>
T MyCircularQueue<T>::Front() {
  return list[front];
}

template <typename T>
T MyCircularQueue<T>::Rear() {
  return list[rear - 1];
}

template <typename T>
int MyCircularQueue<T>::size() const {
  int size = 0;
  int tmp = front;
  while (tmp != rear) {
    size++;
    tmp = (tmp + 1) % maxsize;
  }
  return size;
}

template <typename T>
void MyCircularQueue<T>::print() const {
  int tmp = front;
  while (tmp != rear) {
    cout << "[" << list[tmp] << "]";
    tmp = (tmp + 1) % maxsize;
  }
  cout << endl;
}

template <typename T>
void MyCircularQueue<T>::printDetail() const {
  cout << "Size : " << size() << endl;
  cout << "Queue :";
  print();
  cout << "index : ";
  for (int i = front; i != rear; i = (i + 1) % maxsize) {
    cout << i + 1 << " ";
  }
  cout << endl;
  cout << "front : " << front << ", rear : " << rear << endl;
}

int main() {
  MyCircularQueue<int> q;
  cout << "===== Dequeue x 1 =====" << endl;
  q.dequeue();
  q.printDetail();

  cout << "===== Enqueue x 7 (10 ~ 70) =====" << endl;
  for (int i = 10; i <= 70; i += 10) {
    q.enqueue(i);
  }
  q.printDetail();

  cout << "===== Dequeue x 3 =====" << endl;
  for (int i = 0; i < 3; i++) {
    q.dequeue();
  }
  q.printDetail();

  cout << "===== Enqueue x 6 (10 ~ 60) =====" << endl;
  for (int i = 10; i <= 60; i += 10) {
    q.enqueue(i);
  }
  q.printDetail();

  return 0;
}
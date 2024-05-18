#include "./myqueue.h"

// 출력 시 Student class 타입에 대한 출력 변경을 위해 ostream 연산자 오버로딩
ostream& operator<<(ostream& os, const Student& s) {
  return os << s.getName() << " " << s.getGpa();
}

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

template class MyCircularQueue<int>;
template class MyCircularQueue<Student>;
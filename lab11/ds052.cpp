#include <iostream>
using namespace std;
#include "./lib/myqueue.h"

// library의 print() 메서드 오버라이딩
template <typename T>
void MyCircularQueue<T>::print() const {
  int tmp = front;
  while (tmp != rear - 1) {
    cout << list[tmp] << " => ";
    tmp = (tmp + 1) % maxsize;
  }
  cout << list[tmp] << endl;
}

int main() {
  int q_size;
  cin >> q_size;
  MyCircularQueue<int> q(q_size);  // int 저장하
  string input;
  while (input != "q") {  // q 입력받을 때까지 계속 반복
    cin >> input;
    int data;
    if (input == "en") {
      cin >> data;
      q.enqueue(data);
    } else if (input == "de") {
      q.dequeue();
    } else if (input == "front") {
      data = q.isEmpty() ? -1 : q.Front();
      cout << "=> " << data << endl;
    } else if (input == "rear") {
      data = q.isEmpty() ? -1 : q.Rear();
      cout << "=> " << data << endl;
    } else if (input == "size") {
      cout << "=> " << q.size() << endl;
    } else if (input == "empty") {
      int a = q.isEmpty() ? 1 : 0;
      cout << "=> " << a << endl;
    } else if (input == "print") {
      q.print();
    }
  }
  cout << "bye!" << endl;
  return 0;
}
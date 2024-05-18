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
  MyCircularQueue<int> q(q_size);  // int 타입을 다루는 Queue 생성
  string input;
  while (input != "q") {  // q 입력받을 때까지 계속 반복
    cin >> input;
    int data;
    if (input == "en") {  // 키워드 en이면 그 다음 나오는 숫자를 en q
      cin >> data;
      q.enqueue(data);
    } else if (input == "de") {  // de 면 de q
      q.dequeue();
    } else if (input == "front") {  // front면 front값 출력, q 비었으면 -1 출력
      data = q.isEmpty() ? -1 : q.Front();
      cout << "=> " << data << endl;
    } else if (input == "rear") {  // rear면 rear값 출력, q 비었으면 -1 출력
      data = q.isEmpty() ? -1 : q.Rear();
      cout << "=> " << data << endl;
    } else if (input == "size") {  // size 출력
      cout << "=> " << q.size() << endl;
    } else if (input == "empty") {  // 비었으면 1 값 있으면 0 출력
      int a = q.isEmpty() ? 1 : 0;
      cout << "=> " << a << endl;
    } else if (input == "print") {  // print
      q.print();
    }
  }
  cout << "bye!" << endl;
  return 0;
}
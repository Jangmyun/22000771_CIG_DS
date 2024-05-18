#include <fstream>
#include <iostream>
using namespace std;
#include "./lib/myqueue.h"

template <typename T>
void MyCircularQueue<T>::print() const {
  int tmp = front;
  while (tmp != rear) {
    cout << list[tmp].getName() << " " << list[tmp].getGpa() << endl;
    tmp = (tmp + 1) % maxsize;
  }
}

template <typename T>
void MyCircularQueue<T>::printDetail() const {
  cout << "Highest GPA = " << list[front].getGpa() << endl;
  print();
}

int main() {
  ifstream file("./data.txt");
  if (!file.is_open()) {  // 파일 안열리면 메시지 출력 후 종료
    cout << "File is not opened." << endl;
    return 0;
  }
  MyCircularQueue<Student> q(10);
  double gpa;
  string name;
  while (!file.eof()) {
    file >> gpa >> name;
    Student s(gpa, name);
    if (q.isEmpty()) {
      q.enqueue(s);
    } else if (q.Front().getGpa() < gpa) {
      q.initialize();
      q.enqueue(s);
    } else if (q.Front().getGpa() == gpa) {
      q.enqueue(s);
    }
  }
  q.printDetail();
  return 0;
}

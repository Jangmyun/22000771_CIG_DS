#include <iostream>
using namespace std;
#include "./lib/myqueue.h"

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
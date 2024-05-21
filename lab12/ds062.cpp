#include <iostream>
using namespace std;
#include "./lib/linkedlistq.h"

string ordinal(int x) {
  switch (x / 10) {
    case 1:
      return "st";
    case 2:
      return "nd";
    case 3:
      return "rd";
    default:
      return "th";
  }
}

int main() {
  LinkedListQ q;
  q.enqueue(1);
  q.enqueue(1);
  int N;
  cin >> N;

  int nMinus1, nMinus2;

  for (int i = 1; i <= N; i++) {
    nMinus1 = q.Front();
    cout << i << ordinal(i) << " : " << nMinus1 << endl;
    q.dequeue();
    nMinus2 = q.Front();
    q.enqueue(nMinus1 + nMinus2);
  }

  cout << "=> fibonacci(" << N << ") : " << nMinus1 << endl;

  return 0;
}
#include <iostream>
using namespace std;
#include "./lib/minHeap.h"

int main() {
  MinHeap mh;
  int menu;
  while (1) {
    cout << "1. Array to minHeap 2.insert 3.delete 4.print 0.quit > ";
    cin >> menu;
    if (menu == 1) {
      int n;
      cin >> n;
      int tmp;
      for (int i = 0; i < n; i++) {
        cin >> tmp;
        mh.insertKey(tmp);
      }
      mh.printHeap();
    } else if (menu == 2) {
      int value;
      cin >> value;
      mh.insertKey(value);
      mh.printHeap();
    } else if (menu == 3) {
      cout << "min value; " << mh.peek() << endl;
      mh.deleteKey();
      mh.printHeap();
    } else if (menu == 4) {
      mh.printHeap();
    } else {
      break;
    }
  }
  cout << "Bye!" << endl;
  return 0;
}
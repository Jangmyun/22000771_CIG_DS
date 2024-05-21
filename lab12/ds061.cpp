#include <iostream>
using namespace std;
#include "./lib/linkedlistq.h"

int main() {
  LinkedListQ q;
  int choice, flag = 1, value;
  while (flag == 1) {
    cout << "\n1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue "
            "6.exit > ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter Value:";
        cin >> value;
        q.enqueue(value);
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        q.showfront();
        break;
      case 4:
        q.showrear();
        break;
      case 5:
        q.printAll();
        break;
      case 6:
        flag = 0;
        cout << "bye!" << endl;
        break;
    }
  }

  return 0;
}
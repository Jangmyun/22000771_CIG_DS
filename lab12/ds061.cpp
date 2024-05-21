#include <iostream>
using namespace std;
#include "./lib/linkedlistQ.h"

int main() {
  int choice, flag = 1, value;
  while (flag == 1) {
    cout << "\n1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue "
            "6.exit\n";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter Value:\n";
        cin >> value;
        enqueue(value);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        showfront();
        break;
      case 4:
        showrear();
        break;
      case 5:
        displayQueue();
        break;
      case 6:
        flag = 0;
        cout << "bye!" << endl;
        break;
    }
  }

  return 0;
}
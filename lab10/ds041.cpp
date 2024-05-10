#include <iostream>

#include "./lib/mystack.h"
using namespace std;

void manageStack() {
  MyLinkedStack s;
  string input = "";
  int value;

  while (input != "q") {
    cin >> input;
    if (input == "push") {
      cin >> value;
      s.push(value);
    }
    if (input == "pop") {
      s.pop();
    }
    if (input == "peek") {
      cout << s.peek() << endl;
    }
    if (input == "clear") {
      s.initialize();
    }
    if (input == "print") {
      if (s.isEmpty()) {
        cout << "Stack is empty" << endl;
        continue;
      }
      s.printAll();
    }
  }
  cout << "Bye!" << endl;
}

int main() {
  manageStack();

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "./lib/linkedListSorting.cpp"

int main() {
  int choice;
  linkedList list;

  while (1) {
    cout << "How many numbers do you want to create (0:exit) ... ";
    cin >> choice;
    if (choice == 0) break;
    list.init(choice);
    // list.selectionLinked();
    list.selectionLinked();
    list.printLinked();
  }
}
#include <iostream>
using namespace std;
#include "./lib/linkedListSorting.cpp"

int main() {
  int choice;
  linkedList list;
  cin >> choice;
  list.initName(choice);
  list.bubbleLinked();
  list.printLinkedName();

  return 0;
}
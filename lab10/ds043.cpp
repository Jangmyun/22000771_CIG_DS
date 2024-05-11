#include <iostream>

#include "./lib/mystack_char.cpp"
using namespace std;

void findString(string input) {}

bool isValidChar(char c) {
  if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122) ||
      c == '<' || c == '>') {
    return true;
  }
  return false;
}

bool isValidInput(string input) {
  for (char c : input) {
    if (!isValidChar(c)) {
      return false;
    }
  }
  return true;
}

void enterString() {
  string input;
  while (input != "q") {
    cin >> input;

    findString(input);
  }
}

int main() {
  MyLinkedStack s;
  s.push('c');

  cout << s.peek();
  return 0;
}
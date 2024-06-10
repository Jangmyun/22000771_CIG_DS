#include <iostream>
#include <stack>
using namespace std;

// 문자가 알파벳, 숫자, 방향키인지 확인
bool isValidChar(char c) {
  if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
      ('0' <= c && c <= '9') || c == '<' || c == '>') {
    return true;
  }
  return false;
}

// input이 올바른지 확인
bool isValidInput(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (isValidChar(input[i])) {
      return true;
    }
  }
  return false;
}
// 방향키인지 확인
bool isArrowKey(char c) {
  if (c == '<' || c == '>') {
    return true;
  }
  return false;
}

void findString(string input) {
  // stack left right 두개 사용
  stack<char> left, right;

  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
    if (!isArrowKey(c)) {
      left.push(c);
    }
    if (c == '<') {  // 왼쪽 방향키면 left top 값 right에 push
      if (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    }
    if (c == '>') {
      if (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
    }
  }
  // left 모든 원소 right에 push
  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  cout << "=> ";
  while (!right.empty()) {
    cout << right.top();
    right.pop();
  }
  cout << endl;
  return;
}

int main() {
  string input;
  stack<char> left, right;
  while (true) {
    cin >> input;
    if (input == "q") {
      return 0;
    }
    if (!isValidInput(input)) {
      cout << "Invalid Input" << endl;
      return 0;
    }
    findString(input);
  }
  return 0;
}
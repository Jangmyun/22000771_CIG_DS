#include <iostream>

#include "./lib/mystack_char.h"
using namespace std;

bool isValidChar(char c) {
  // 문자가 알파벳, 숫자, <> 인 경우 true 리턴
  if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122) ||
      c == '<' || c == '>') {
    return true;
  }
  return false;
}

bool isValidInput(string input) {  // input이 올바른지 확인
  for (char c : input) {
    if (!isValidChar(c)) {
      return false;
    }
  }
  return true;
}

bool isArrowKey(char c) {  // 방향키인지 확인
  if (c == '<' || c == '>') {
    return true;
  }
  return false;
}

void findString(string input) {
  MyLinkedStack left, right;  // stack 두개 사용

  for (char c : input) {
    if (!isArrowKey(c)) {  // 방향키가 아니면 left에 push
      left.push(c);
    }
    if (c == '<') {  // 왼쪽 방향키면 left top의 값을 right에 push
      if (!left.isEmpty()) {
        right.push(left.peek());
        left.pop();
      }
    }
    if (c == '>') {  // 오른쪽  방향키면 right top의 값을 left에 push
      if (!right.isEmpty()) {
        left.push(right.peek());
        right.pop();
      }
    }
  }

  while (!left.isEmpty()) {  // left의 모든 원소를 right에 push
    right.push(left.peek());
    left.pop();
  }

  // 출력
  cout << "=> ";
  while (!right.isEmpty()) {
    cout << right.peek();
    right.pop();
  }
  cout << endl;
  return;
}

void enterString() {
  string input;
  while (true) {
    cin >> input;
    if (input == "q") {
      return;
    }
    if (!isValidInput(input)) {  // input이 올바르게 입력됐는지 확인
      cout << "Invalid Input" << endl;
      return;
    }

    findString(input);
  }
}

int main() {
  enterString();
  return 0;
}
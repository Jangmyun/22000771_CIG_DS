#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "./lib/mystack.h"
using namespace std;

bool isOperator(char c) {  // 연산자 인지 판별
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    return true;
  }
  return false;
}

// 피연산자 두개와 연산자 두개 매개변수로 받아서 계산해서 리턴
int operate(int op1, int op2, char oper) {
  if (oper == '+') {
    return op1 + op2;
  }
  if (oper == '-') {
    return op1 - op2;
  }
  if (oper == '*') {
    return op1 * op2;
  }
  if (oper == '/') {
    return op1 / op2;
  }
  return -1;
}

bool isValidCharacter(char c) {
  if (c == '#' || c == '+' || c == '-' || c == '*' || c == '/') {
    return true;
  }
  return false;
}

bool isNumber(char c) {
  if (48 <= c && c <= 57) {
    return true;
  }
  return false;
}

void calculatePostfix(string input) {
  for (char c : input) {  // string 순회하면서 이상한 문자 나오는지 확인
    if (!isValidCharacter(c) && !isNumber(c) && !(c == '=') && !(c == ' ')) {
      cout << input << endl << "=> Expression error !!!" << endl;
      return;
    }
  }
  MyLinkedStack stack;
  stringstream ss(input);
  string tmp;
  string output;
  int operand1, operand2;
  int result;

  while (ss >> tmp) {
    if (tmp[0] == '=') {
      break;
    }
    if (tmp[0] == '#') {                // #으로 시작되는 토큰은
      stack.push(stoi(tmp.substr(1)));  // #을 제거하고 정수변환 후 stack.push
    } else if (isValidCharacter(tmp[0])) {
      operand1 = stack.peek();
      stack.pop();
      operand2 = stack.peek();
      stack.pop();
      if (operand1 == 0) {  // 나누는 피연산자가 0이면 Division by 0 출력
        cout << input << endl << "=> Division by 0" << endl;
        return;
      }

      stack.push(operate(operand2, operand1, tmp[0]));  // stack에 연산결과 push
    }
  }
  if (stack.getNodeCnt() > 1) {
    cout << input << endl << "=> Too many operands !!!" << endl;
    return;
  }
  result = stack.peek();
  cout << input << " " << result << endl;
}

void readFile() {
  ifstream file("./ds042_input.txt");  // ds042_input.txt 파일 열기
  string oneLine;                      // 한줄 씩 연산

  if (!file.is_open()) {  // 파일 안열리면 메시지 출력 후 종료
    cout << "File is not opened." << endl;
    return;
  }

  while (!file.eof()) {  // 파일 끝까지 읽기
    getline(file, oneLine);
    calculatePostfix(oneLine);
  }
}

int main() {
  readFile();
  return 0;
}
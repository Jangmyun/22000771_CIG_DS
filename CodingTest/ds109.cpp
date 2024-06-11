#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  stack<char> s;

  string input;
  cin >> input;

  for (int i = 0; i < input.length(); i++) {
    if (s.empty()) {
      s.push(input[i]);
      continue;
    }
    if (s.top() == input[i]) {
      s.pop();
    } else {
      s.push(input[i]);
    }
  }

  int n = s.size();
  char *cstr = new char[n];
  for (int i = n - 1; i >= 0; i--) {
    cstr[i] = s.top();
    s.pop();
  }
  cout << cstr << endl;
  return 0;
}
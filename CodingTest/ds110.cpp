#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> dummy;
  int n;
  cin >> n;

  // 1에서 n까지 queue push
  for (int i = 1; i <= n; i++) {
    dummy.push(i);
  }
  // dummy에 숫자 한개 남을 때까지 반복해서 카드 한개 pop하고 맨 위카드 아래로
  // 이동시키기
  while (dummy.size() > 1) {
    dummy.pop();
    dummy.push(dummy.front());
    dummy.pop();
  }
  cout << dummy.back() << endl;
  return 0;
}
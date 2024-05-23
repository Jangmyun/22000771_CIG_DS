#include <iostream>
using namespace std;
#include "./lib/linkedlistq.h"

string ordinal(int x) {  // 순서 뒤에 st, nd, rd, th 중 어떤 걸 붙일 지 선택
  switch (x / 10) {
    case 1:
      return "st";
    case 2:
      return "nd";
    case 3:
      return "rd";
    default:
      return "th";
  }
}

int main() {
  LinkedListQ q;
  q.enqueue(1);  // n=1이면 1, n=2면 1 이므로 미리 Queue 에 1 두개 enqueue
  q.enqueue(1);
  int N;
  cin >> N;  // 몇번째 피보나치 수까지 출력할지 입력받기

  int nMinus1, nMinus2;

  for (int i = 1; i <= N; i++) {  // 1부터 입력받은 N까지 반복
    nMinus1 =
        q.Front();  // Queue에서 front와 front 다음 값을 더한 다음 다시 q에 넣기
    cout << i << ordinal(i) << " : " << nMinus1 << endl;
    q.dequeue();
    nMinus2 = q.Front();
    q.enqueue(nMinus1 + nMinus2);
  }

  cout << "=> fibonacci(" << N << ") : " << nMinus1
       << endl;  // 최종 값은 마지막에 Queue에서 꺼낸 수

  return 0;
}
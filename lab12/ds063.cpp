#include <iostream>
using namespace std;
#include "./lib/linkedlistq.h"

int findWinner(int p1, int p2) {
  if (p1 > p2) {
    return 1;
  } else if (p1 < p2) {
    return 2;
  } else {
    return 0;
  }
}

void cardGame() {
  // 각 플레이어 승리 횟수
  int p1WinCount = 0, p2WinCount = 0;
  // 각 플레이어 이전 라운드 대결 숫자
  int prevP1, prevP2;
  // 이전 승리자 :  0 = 무승부,  1= P1 승리,  2= P2 승리
  int prevWinner = 0;
  // 각 플레이어 대결 숫자
  int p1, p2;
  LinkedListQ q1, q2;
  int N;
  int tmp;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    q1.enqueue(tmp);
  }
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    q2.enqueue(tmp);
  }

  for (int i = 0; i < N; i++) {
    cout << "Round" << i + 1 << " - ";
    // 이전 라운드가 무승부였다면
    if (prevWinner == 0) {
      prevP1 = p1 = q1.Front();
      q1.dequeue();
      prevP2 = p2 = q2.Front();
      q2.dequeue();
      prevWinner = findWinner(p1, p2);
    }  // 이전 라운드가 P1이 승리였다면
    else if (prevWinner == 1) {
      prevP1 = p1 = q1.Front() + prevP1 - prevP2 - 1;
      q1.dequeue();
      prevP2 = p2 = q2.Front();
      q2.dequeue();
      prevWinner = findWinner(p1, p2);
    }  // 이전 라운드가 P2가 승리였다면
    else if (prevWinner == 2) {
      prevP2 = p2 = q2.Front() + prevP2 - prevP1 - 1;
      q2.dequeue();
      prevP1 = p1 = q1.Front();
      q1.dequeue();
      prevWinner = findWinner(p1, p2);
    }

    if (prevWinner == 1) {
      cout << "P1 win!" << endl;
      p1WinCount++;
    }
    if (prevWinner == 2) {
      cout << "P2 win!" << endl;
      p2WinCount++;
    }
    if (prevWinner == 0) {
      cout << "Draw!" << endl;
    }
  }
  cout << "Final - ";
  if (p1WinCount > p2WinCount) {
    cout << "P1 win!" << endl;
  } else if (p1WinCount < p2WinCount) {
    cout << "P2 win!" << endl;
  } else {
    cout << "Draw!" << endl;
  }
}

int main() {
  cardGame();
  return 0;
}
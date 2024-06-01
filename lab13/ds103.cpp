#include <iostream>
using namespace std;
#include "./lib/sorting.h"

int main() {
  int N, K;
  cin >> N >> K;
  int score[N];

  for (int i = 0; i < N; i++) {
    cin >> score[i];
  }

  quickSort(score, N);
  cout << score[N - K] << endl;

  return 0;

  // 89 100 112 170 180  190 210
}
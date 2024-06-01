#include <iostream>
using namespace std;
#include "./lib/sorting.h"

int sumArray(int* arr, int n) {
  int output = 0;
  for (int i = 0; i < n; i++) {
    output += arr[i];
  }
  return output;
}

void cardGame() {
  int N, K;
  cin >> N >> K;

  int deck1[N];
  int deck2[N];

  for (int i = 0; i < N; i++) {
    cin >> deck1[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> deck2[i];
  }
  quickSort(deck1, N);
  quickSort(deck2, N);

  int changeTimes = 0;
  for (int i = 0; i < K; i++) {
    if (deck1[i] >= deck2[N - 1 - i]) {
      break;
    }
    deck1[i] = deck2[N - 1 - i];
    changeTimes++;
  }

  cout << changeTimes << " " << sumArray(deck1, N) << endl;
}

int main() {
  cardGame();
  return 0;
}
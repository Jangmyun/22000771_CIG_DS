#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findNumber(int* arr, int N, int K) {
  vector<int> vec(arr, arr + N);
  priority_queue<int> pq(vec.begin(), vec.end());

  int output;
  for (int i = 0; i < K; i++) {
    output = pq.top();
    pq.pop();
  }
  return output;
}

int main() {
  int N, K;
  cin >> N >> K;

  int* arr = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cout << findNumber(arr, N, K) << endl;
  return 0;
}
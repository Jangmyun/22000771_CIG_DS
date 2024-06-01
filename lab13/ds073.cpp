#include <iostream>
using namespace std;
#include "./lib/sorting.h"

int main() {
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "=== ascending order ===" << endl;
  bubbleSortAscending(arr, n);
  print(arr, n);
  cout << "=== descending order ===" << endl;
  bubbleSortDescending(arr, n);
  print(arr, n);
  return 0;
}
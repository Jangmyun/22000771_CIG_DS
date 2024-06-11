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

  quickSort(arr, n);
  printDescending(arr, n);

  return 0;
}
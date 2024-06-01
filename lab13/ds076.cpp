#include <iostream>
using namespace std;
#include "./lib/sorting.h"

int main() {
  int select = 0;
  while (select != 6) {
    cout << "1. selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
    cin >> select;

    if (select == 6) {
      cout << "bye!" << endl;
      return 0;
    }

    int n;
    cout << "Enter count: ";
    cin >> n;
    int arr[n];

    cout << "Enter numbers : ";
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    switch (select) {
      case 1:
        selectionSort(arr, n);
        print(arr, n);
        break;
      case 2:
        insertionSort(arr, n);
        print(arr, n);
        break;
      case 3:
        bubbleSortAscending(arr, n);
        print(arr, n);
        break;
      case 4:
        quickSort(arr, n);
        print(arr, n);
        break;
      case 5:
        mergeSort(arr, n);
        print(arr, n);
      default:
        break;
    }
  }
  return 0;
}
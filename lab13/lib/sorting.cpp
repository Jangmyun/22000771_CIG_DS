#include "./sorting.h"
// #define _DEBUG

void print(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << "[" << arr[i] << "]";
  }
  cout << endl;
}

void selectionSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
#ifdef _DEBUG
    print(arr, n);
#endif
    if (minIndex != i) swap(arr[i], arr[minIndex]);
  }
}

void insertionSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int tmp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = tmp;
#ifdef _DEBUG
    print(arr, n);
#endif
  }
}

void bubbleSortAscending(int *arr, int n) {
  for (int i = 0; i < n; i++) {
#ifdef _DEBUG
    print(arr, n);
#endif
    for (int j = 0; j < n - i; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void bubbleSortDescending(int *arr, int n) {
  for (int i = 0; i < n; i++) {
#ifdef _DEBUG
    print(arr, n);
#endif
    for (int j = 0; j < n - i; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void quickSort(int *arr, int n) {}
void mergeSort(int *arr, int n) {}
#include "./sorting.h"
// #define _DEBUG

void print(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << "[" << arr[i] << "] ";
  }
  cout << endl;
}

void selectionSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
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
  for (int i = 1; i < n; i++) {
#ifdef _DEBUG
    print(arr, n);
#endif
    int tmp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = tmp;
  }
}

void bubbleSortAscending(int *arr, int n) {
  for (int i = 0; i < n; i++) {
#ifdef _DEBUG
    print(arr, n);
#endif
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
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

int partition(int *arr, int left, int right, int n) {
  int pivot = arr[right];
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]);
  return i + 1;  // return pivot
}

void qs(int *arr, int left, int right, int n) {
  if (left < right) {
#ifdef _DEBUG
    print(arr, n);
#endif
    int pivot = partition(arr, left, right, n);
    qs(arr, left, pivot - 1, n);
    qs(arr, pivot + 1, right, n);
  }
}

void quickSort(int *arr, int n) {
  qs(arr, 0, n - 1, n);
#ifdef _DEBUG
  print(arr, n);
#endif
}

// void merge(int *arr1, int *arr2, int n1, int n2, int n3, int n4) {
//   int i, j, k, t;
//   i = n1;
//   j = n3;
//   k = n1;
//   while ((i <= n2) && (j <= n4)) {
//     if (arr1[i] <= arr1[j]) {
//       arr2[k++] = arr1[j++];
//     } else {
//       arr2[k++] = a[j++];
//     }
//     if (i > n2) {
//       for (t = j; t <= n4; t++) {
//         arr2[t] = arr1[t];
//       }
//     } else {
//       for (t = i; t <= n2; t++) {
//         arr2[k + t - i] = arr1[t];
//       }
//     }
//   }
// }
// void merge_pass(int *arr1, int *arr2, int n, int s) {
//   int i, j;
//   for (i = 0; i < (n - 2 * s + 1); i += 2 * s) {
//     merge(arr1, arr2, i, i + s - 1, i + s, i + 2 * s - 1);
//   }
//   if (i + s <= n) {
//     merge(arr1, arr2, i + s - 1, i + s, n);
//   } else {
//     for (j = i; j <= n; j++) {
//       arr2[j] = arr1[j];
//     }
//   }
// }

// void mergeSort(int *arr, int n) {
//   int s = 1;
//   int arr2[n];

//   while (s < n) {
//     merge_pass(arr, arr2, n - 1, s);
//     s *= 2;
//     merge_pass(arr, arr2, n - 1, s);
//     s *= 2;
//   }
// }
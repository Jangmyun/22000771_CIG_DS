#include "./minHeap.h"

MinHeap::MinHeap() { length = 0; }

void MinHeap::printHeap() {
  cout << "==> minHeap : ";
  for (int i = 0; i < length; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void MinHeap::insertKey(int value) {
  if (length == 30) {
    cout << "\nOverflow: Could not insert Key\n";
    return;
  }
  // 현재 heap size를 저장하고 1증가
  int k = length++;
  while ((k > 0) && (value < arr[(k - 1) / 2])) {
    arr[k] = arr[(k - 1) / 2];
    k = (k - 1) / 2;
  }
  arr[k] = value;
}

int MinHeap::peek() { return arr[0]; }

bool MinHeap::isEmpty() { return length == 0 ? true : false; }

void MinHeap::minHeapifyDown(int root) {
  int tmp = arr[root];
  // child를 root의 left child로
  int child = 2 * root + 1;

  if ((child + 1 < length) && (arr[child] > arr[child + 1])) {
    child++;
  }
  if (tmp > arr[child]) {
    arr[(child - 1) / 2] = arr[child];
    arr[child] = tmp;
    minHeapifyDown(child);
  }
}

void MinHeap::minHeapifyUp(int index) {
  int parent = (index - 1) / 2;
  while ((index > 0) && (arr[index] < arr[parent])) {
    swap(arr[index], arr[parent]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

int MinHeap::size() { return length; }

int MinHeap::deleteKey() {
  if (isEmpty()) {
    cout << "\nHeap is empty.\n";
    return -1;
  }
  int tmp = arr[0];
  arr[0] = arr[length - 1];
  minHeapifyDown(0);
  length--;
  return tmp;
}
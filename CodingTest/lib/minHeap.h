#include <iostream>
using namespace std;

class MinHeap {
 private:
  int arr[30];
  int length;

 public:
  MinHeap();
  void printHeap();
  void insertKey(int value);
  int peek();
  bool isEmpty();
  int size();
  void minHeapifyDown(int root = 0);
  void minHeapifyUp(int index);
  int deleteKey();
};
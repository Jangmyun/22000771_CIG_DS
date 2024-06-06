#include <iostream>
using namespace std;
#define _DEBUG

int size = 0;

void printArray(int* arr, int size) {
  cout << "==> Heap : ";
  for (int i = 0; i < size; ++i) cout << arr[i] << " ";
  cout << endl;
}

// insertKey 함수 (배열 , 전체 사이즈, 넣을 값)
void insertKey(int arr[], int N, int value) {
  // size 꽉차면 overflow 표시
  if (::size == N) {
    cout << "\nOverflow: Could not insertKey\n";
    return;
  }

  // 현재 heap 사이즈 저장
  int k = ::size++;
  // k가 root가 아니고, 넣을 value값이 부모 ((k-1)/2)보다 크면
  // 현재 위치에 부모의 값을 넣고 k 위치를 한단계 위로 올린다.
  while ((k > 0) && (value > arr[(k - 1) / 2])) {
    arr[k] = arr[(k - 1) / 2];
    k = (k - 1) / 2;
  }
  // 한단계 위로 올라간 k에 value 저장
  arr[k] = value;
#ifdef _DEBUG
  printArray(arr, ::size);
#endif
}

void maxHeapify(int arr[], int root) {
  // root 위치의 값을 tmp에 저장
  int tmp = arr[root];
  // 먼저 child를 root의 left child로 설정
  int child = 2 * root + 1;

  // root 의 left와 right를 먼저 비교하여 더 큰 값을 찾아낸다.
  // (child가 left로 설정되어 있으므로 right가 더 크다면 child++ 해준다.)
  if ((child + 1 < ::size) && arr[child] < arr[child + 1]) {
    child++;
  }
  // (child의)left,right중 더 큰 값이 tmp보다 크면
  // child의 값과 root의 값을 교환한다.
  if (tmp < arr[child]) {
    arr[(child - 1) / 2] = arr[child];
    arr[child] = tmp;
    // 변경된 child에 대해 maxHeapify를 재귀적으로 진행한다.
    maxHeapify(arr, child);
  }
}

void deleteKey(int arr[], int N) {
  if (::size == 0) {
    cout << "\nCould not deleteKey\n";
    return;
  }
#ifdef _DEBUG
  cout << "=> Delete " << arr[0] << endl;
#endif

  // root값에 마지막 원소를 저장
  arr[0] = arr[--::size];
  // maxHeapify 진행
  maxHeapify(arr, 0);

#ifdef _DEBUG
  printArray(arr, ::size);
#endif
}

int main() {
  int arr[20];
  int menu;
  while (1) {
    cout << "1. insert 2.delete 3.print 4.quit > ";
    cin >> menu;
    if (menu == 1) {
      int value;
      cout << "new value? ";
      cin >> value;
      insertKey(arr, 20, value);
    } else if (menu == 2) {
      deleteKey(arr, 20);
    } else if (menu == 3) {
      printArray(arr, ::size);
    } else
      break;
  }
  cout << "Bye!" << endl;

  return 0;
}
#include <iostream>
#include <queue>
using namespace std;
#include "./lib/binaryTree.h"

int main() {
  MyTree tree;

  int n, s;
  cin >> n >> s;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  tree.buildTree(arr, n);

  switch (s) {
    case 1:
      tree.printPreOrderTree();
      break;
    case 2:
      tree.printPostOrderTree();
    default:
      break;
  }
  return 0;
}

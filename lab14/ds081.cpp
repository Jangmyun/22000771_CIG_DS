#include <iostream>
#include <queue>
using namespace std;
#include "./lib/binaryTree.h"

int main() {
  int n;
  cin >> n;
  int nums[n];

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  MyTree tree;
  tree.buildTree(nums, n);
  tree.printInOrderTree();
  return 0;
}
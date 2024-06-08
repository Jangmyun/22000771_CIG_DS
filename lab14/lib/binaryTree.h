#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

class MyTree {
 private:
  TreeNode *root;

 public:
  MyTree();
  TreeNode *getRoot();
  TreeNode *buildTree(int *nums, int size);
  void inOrderTraversal(TreeNode *node);
  void printInOrderTree();
  void preOrderTraversal(TreeNode *node);
  void printPreOrderTree();
  void postOrderTraversal(TreeNode *node);
  void printPostOrderTree();
};
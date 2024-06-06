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
  MyTree() { root = NULL; }

  TreeNode *getRoot() { return root; }

  TreeNode *buildTree(int *nums, int size) {
    if (nums == NULL) return NULL;
    root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (i < size) {
      TreeNode *curr = q.front();
      q.pop();
      if (i < size) {
        curr->left = new TreeNode(nums[i++]);
        q.push(curr->left);
      }
      if (i < size) {
        curr->right = new TreeNode(nums[i++]);
        q.push(curr->right);
      }
    }
    return root;
  }

  void inOrderTraversal(TreeNode *node) {
    if (!node) return;
    inOrderTraversal(node->left);
    cout << node->val << " ";
    inOrderTraversal(node->right);
  }

  void printInOrderTree() {
    inOrderTraversal(root);
    cout << endl;
  }
};

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
#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int x) {
    val = x;
    left = right = NULL;
  }
};

class BinaryTree {
 private:
  TreeNode *root;

 public:
  BinaryTree() { root = NULL; }

  TreeNode *getRoot() { return root; }

  TreeNode *buildTree(int *nums, int size) {
    if (nums == NULL) return NULL;
    queue<TreeNode *> q;

    root = new TreeNode(nums[0]);
    q.push(root);

    int i = 1;
    while (i < size) {
      TreeNode *current = q.front();
      q.pop();
      if (i < size) {
        current->left = new TreeNode(nums[i++]);
        q.push(current->left);
      }
      cout << endl;
      if (i < size) {
        current->right = new TreeNode(nums[i++]);
        q.push(current->right);
      }
    }

    return root;
  }

  void printInOrderTree(TreeNode *root) {
    if (root == NULL) {
      return;
    }

    printInOrderTree(root->left);
    if (root->val != 0) {
      cout << root->val << " ";
    }
    printInOrderTree(root->right);
  }

  void printPreOrderTree(TreeNode *root) {
    if (root == NULL) return;

    if (root->val != 0) {
      cout << root->val << " ";
    }
    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
  }

  void printPostOrderTree(TreeNode *root) {
    if (root == NULL) return;

    printPostOrderTree(root->left);
    printPostOrderTree(root->right);
    if (root->val != 0) {
      cout << root->val << " ";
    }
  }
};

int main() {
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  BinaryTree btree;
  btree.buildTree(arr, n);
  btree.printInOrderTree(btree.getRoot());
  return 0;
}
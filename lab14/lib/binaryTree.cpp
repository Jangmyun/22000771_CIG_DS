#include "./binaryTree.h"

MyTree::MyTree() { root = NULL; }

TreeNode *MyTree::getRoot() { return root; }

TreeNode *MyTree::buildTree(int *nums, int size) {
  if (nums == NULL) return NULL;
  root = new TreeNode(nums[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (i < size) {
    TreeNode *curr = q.front();
    q.pop();

    if (curr->val == 0) {
      i++;
      continue;
    } else {
      if (i < size) {
        curr->left = new TreeNode(nums[i++]);
        q.push(curr->left);
      }
      if (i < size) {
        curr->right = new TreeNode(nums[i++]);
        q.push(curr->right);
      }
    }
  }
  return root;
}

void MyTree::inOrderTraversal(TreeNode *node) {
  if (!node) return;
  inOrderTraversal(node->left);
  if (node->val != 0) {
    cout << node->val << " ";
  }
  inOrderTraversal(node->right);
}

void MyTree::printInOrderTree() {
  inOrderTraversal(root);
  cout << endl;
}

void MyTree::preOrderTraversal(TreeNode *node) {
  if (!node) return;
  if (node->val != 0) {
    cout << node->val << " ";
  }
  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
}

void MyTree::printPreOrderTree() {
  preOrderTraversal(root);
  cout << endl;
}

void MyTree::postOrderTraversal(TreeNode *node) {
  if (!node) return;
  postOrderTraversal(node->left);
  postOrderTraversal(node->right);
  if (node->val != 0) {
    cout << node->val << " ";
  }
}

void MyTree::printPostOrderTree() {
  postOrderTraversal(root);
  cout << endl;
}
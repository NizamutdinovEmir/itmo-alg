#include <iostream>
#include <vector>
#include <algorithm>

struct Tree {
  int key;
  Tree* left;
  Tree* right;

  Tree(int val) : key(val), left(nullptr), right(nullptr) {}
};

void preorder(Tree* root) {
  if (root != nullptr) {
    std::cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

Tree* build(std::vector<int>& decorations, int start, int end) {
  if (start > end) {
    return nullptr;
  }

  int mid = (start + end) / 2;
  Tree* root = new Tree(decorations[mid]);
  root->left = build(decorations, start, mid - 1);
  root->right = build(decorations, mid + 1, end);

  return root;
}

void delete_tree(Tree* root) {
  if (root == nullptr) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> decorations(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> decorations[i];
  }

  Tree* root = build(decorations, 0, n - 1);

  preorder(root);

  delete_tree(root);

  return 0;
}



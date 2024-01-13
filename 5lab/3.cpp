#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
  long long key;
  long long size;
  Tree* left;
  Tree* right;

  Tree(long long val) : key(val), size(1) , left(nullptr), right(nullptr) {}
};

void preorder(Tree* root, vector<long long>& keys) {
  if (root != nullptr) {
    keys.push_back(root->key);
    preorder(root->left, keys);
    preorder(root->right, keys);
  }
}

Tree* build(std::vector<long long>& decorations, long long start, long long end) {
  if (start > end) {
    return nullptr;
  }

  long long mid = (start + end) / 2;
  Tree* root = new Tree(decorations[mid]);
  root->left = build(decorations, start, mid - 1);
  root->right = build(decorations, mid + 1, end);

  return root;
}

Tree* search(Tree* root , long long x) {
  if (root == nullptr || x == root->key) {
    return root;
  }
  if (x < root->key) {
    return search(root->left , x);
  } else {
    return search(root->right , x);
  }
}

struct Tree *newTree(long long item) {
  struct Tree* temp = new Tree(item);
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

Tree* insert(Tree* root, long long z) {
  if (root == nullptr) {
    return newTree(z);
  } else if (z < root->key) {
    root->left = insert(root->left, z);
  } else if (z > root->key) {
    root->right = insert(root->right, z);
  }

  root->size = 1 + ((root->left != nullptr) ? root->left->size : 0) + ((root->right != nullptr) ? root->right->size : 0);

  return root;
}

Tree* next(Tree* root, long long x) {
  Tree* current = root;
  Tree* successor = nullptr;
  while (current != nullptr) {
    if (current->key > x) {
      successor = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return successor;
}

Tree* prev(Tree* root , long long x) {
  Tree* current = root;
  Tree* successor = nullptr;
  while (current != nullptr) {
    if (current->key < x) {
      successor = current;
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return successor;
}

Tree* minimum(Tree* root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}

Tree* delete_key(Tree* root, int z) {
  if (root == nullptr) {
    return root;
  }
  if (z < root->key) {
    root->left = delete_key(root->left, z);
  } else if (z > root->key) {
    root->right = delete_key(root->right, z);
  } else {
    if (root->left == nullptr) {
      Tree* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Tree* temp = root->left;
      delete root;
      return temp;
    }

    Tree* temp = minimum(root->right);
    root->key = temp->key;
    root->right = delete_key(root->right, temp->key);
  }

  root->size = 1 + ((root->left != nullptr) ? root->left->size : 0) + ((root->right != nullptr) ? root->right->size : 0);

  return root;
}

long long kmax(Tree* root, long long k) {
  if (root == nullptr || k <= 0 || k > root->size) {
    return -1;
  }

  long long rightSize = (root->right != nullptr) ? root->right->size : 0;
  if (k == rightSize + 1) {
    return root->key;
  } else if (k <= rightSize) {
    return kmax(root->right, k);
  } else {
    return kmax(root->left, k - rightSize - 1);
  }
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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  Tree* root = nullptr;
  int n;
  cin >> n;
  int oper;
  long long x;
  for (int i = 0; i < n; ++i) {
    cin >> oper;
    cin >> x;
    if (oper == 1) {
      root = insert(root , x);
    } else if (oper == 0) {
      if (root != nullptr) {
        cout << kmax(root , x) << '\n';
      } else {
        continue;
      }
    } else {
      root = delete_key(root, x);
    }
  }
  delete_tree(root);
  return 0;
}

#include <iostream>
#include <vector>
#include <string>

struct Tree {
  int key;
  Tree* left;
  Tree* right;
  int height;

  Tree(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

int height(Tree* root) {
  return root ? root->height : 0;
}

int balanceroot(Tree* root) {
  if (!root) return 0;
  return height(root->right) - height(root->left);
}

void fixheight(Tree* p) {
  if (!p) return;
  int hl = height(p->left);
  int hr = height(p->right);
  p->height = (hl > hr ? hl : hr) + 1;
}

Tree* rotateright(Tree* p) {
  Tree* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

Tree* rotateleft(Tree* q) {
  Tree* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

Tree* balance(Tree* p) {
  fixheight(p);
  if (balanceroot(p) == 2) {
    if (balanceroot(p->right) < 0)
      p->right = rotateright(p->right);
    return rotateleft(p);
  }
  if (balanceroot(p) == -2) {
    if (balanceroot(p->left) > 0)
      p->left = rotateleft(p->left);
    return rotateright(p);
  }
  return p;
}

Tree* insert(Tree* root, int z) {
  if (root == nullptr) {
    root = new Tree(z);
  } else if (z < root->key) {
    root->left = insert(root->left, z);
  } else if (z > root->key) {
    root->right = insert(root->right, z);
  }
  return balance(root);
}

void inorder(Tree* root, std::vector<Tree*>& inOrder) {
  if (root != nullptr) {
    inorder(root->left, inOrder);
    inOrder.push_back(root);
    inorder(root->right, inOrder);
  }
}

bool search(Tree* root, int x) {
  while (root != nullptr) {
    if (x == root->key) {
      return true;
    } else if (x < root->key) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return false;
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
Tree* maximum(Tree* root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->right != nullptr) {
    root = root->right;
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
      return balance(temp);
    } else if (root->right == nullptr) {
      Tree* temp = root->left;
      delete root;
      return balance(temp);
    }

    Tree* temp = maximum(root->left);
    root->key = temp->key;
    root->left = delete_key(root->left, temp->key);
  }
  return balance(root);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  Tree *root = nullptr;
  int n;
  std::cin >> n;
  char s;
  bool ans = false;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> s;
    std::cin >> x;
    if (s == 'A') {
      root = insert(root, x);
      std::cout << balanceroot(root) << '\n';
    } else if (s == 'C') {
      ans = search(root, x);
      if (ans) {
        std::cout << "Y" << '\n';
      } else
        std::cout << "N" << '\n';
    } else if (s == 'D') {
      root = delete_key(root, x);
      std::cout << balanceroot(root) << '\n';
    }
  }
}
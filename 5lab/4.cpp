#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

Tree* search(Tree* root , int x) {
  if (root == nullptr || x == root->key) {
    return root;
  }
  if (x < root->key) {
    return search(root->left , x);
  } else {
    return search(root->right , x);
  }
}

struct Tree *newTree(int item) {
  struct Tree* temp = new Tree(item);
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

Tree* insert(Tree* root , int z) {
  if (root == nullptr) {
    return newTree(z);
  } else if (z < root->key) {
    root->left = insert(root->left , z);
  } else if (z > root->key) {
    root->right = insert(root->right , z);
  }
  return root;
}

Tree* next(Tree* root,int x) {
  Tree* current = root;
  Tree* succesor = nullptr;
  while (current != nullptr) {
    if (current->key > x) {
      succesor = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return succesor;
}


Tree* prev(Tree* root , int x) {
  Tree* current = root;
  Tree* succesor = nullptr;
  while (current!= nullptr) {
    if (current->key < x) {
      succesor = current;
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return succesor;
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
  return root;
}

void level(Tree* root , vector<int>& res , int x) {
  if (!root) {
    return;
  }
  if (x == res.size()) {
    res.push_back(root->key);
  } else {
    res[x] = max(res[x] , root->key);
  }
  level(root->left , res , x + 1);
  level(root->right , res , x + 1);
}

vector<int> largersKeys(Tree* root) {
  vector<int> res;
  level(root, res , 0);
  return res;
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
  Tree* root = nullptr;
  int n;
  cin >> n;
  int x;
  for (int i = 0;i < n;++i) {
    cin >> x;
    root = insert(root , x);
  }
  vector<int> res = largersKeys(root);

  for (int i = 0;i<res.size();++i) {
    cout << res[i] << " ";
  }

  delete_tree(root);
  return 0;
}

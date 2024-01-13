#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

void delete_tree(Tree* root) {
  if (root == nullptr) {
    return;
  }
  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}


int main() {
  std::string operation;
  int x;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  Tree* root = nullptr;
  while (std::cin >> operation) {
    std::cin >> x;
    if (operation == "insert") {
      root = insert(root , x);
    } else if (operation == "exists") {
      if (search(root , x)) {
        std::cout << "true";
      } else {
        std::cout << "false";
      }
      std::cout << '\n';
    } else if (operation == "next") {
      Tree* temp_next = next(root , x);
      if (temp_next == nullptr) {
        std::cout << "none";
      } else {
        std::cout << temp_next->key;
      }
      std::cout << '\n';
    } else if (operation == "prev") {
      Tree* temp_prev = prev(root , x);
      if (temp_prev == nullptr) {
        std::cout << "none";
      } else {
        std::cout << temp_prev->key;
      }
      std::cout << '\n';
    } else {
      root = delete_key(root , x);
    }
  }
  delete_tree(root);
  return 0;
}

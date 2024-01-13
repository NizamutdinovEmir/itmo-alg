#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

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

void inorder(Tree* root , std::vector<int>& ans) {
  if (root != nullptr) {
    inorder(root->left , ans);
    ans.push_back(root->key);
    inorder(root->right , ans);
  }
}

void postorder(Tree* root , std::vector<int>& ans) {
  if (root != nullptr) {
    postorder(root->left , ans);
    postorder(root->right , ans);
    ans.push_back(root->key);
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

Tree* buildTree(std::vector<int>& preorder) {
  if (preorder.empty()) {
    return nullptr;
  }

  Tree* root = new Tree(preorder[0]);

  std::stack<Tree*> s;
  s.push(root);

  for (int i = 1; i < preorder.size(); ++i) {
    Tree* node = nullptr;

    while (!s.empty() && preorder[i] >= s.top()->key) {
      node = s.top();
      s.pop();
    }

    if (node != nullptr) {
      node->right = new Tree(preorder[i]);
      s.push(node->right);
    }

    else {
      s.top()->left = new Tree(preorder[i]);
      s.push(s.top()->left);
    }
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
  int n;
  std::cin >> n;
  Tree* root;
  std::vector<int> preorderinput;
  bool ans = true;
  int x;
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    preorderinput.push_back(x);
  }
  root = buildTree(preorderinput);
  std::vector<int> InOrder;
  inorder(root , InOrder);
  std::vector<int> PostOrder;
  postorder(root , PostOrder);
  int y;
  for (int i = 0; i < n; ++i) {
    std::cin >> y;
    if (y != InOrder[i]) {
      ans = false;
    }
  }
  int z;
  for (int i = 0; i < n; ++i) {
    std::cin >> z;
    if (z != PostOrder[i]) {
      ans = false;
    }
  }
  if (ans) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  delete_tree(root);

  return 0;
}

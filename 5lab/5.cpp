#include <iostream>
#include <vector>
#include <string>

struct Tree {
  std::string key;
  Tree* left;
  Tree* right;
  bool stud1;
  bool stud2;
  bool stud3;

  Tree(std::string val) : key(val), left(nullptr), right(nullptr), stud1(false), stud2(false), stud3(false) {}
};

Tree* insert(Tree* root, std::string z, int student) {
  if (root == nullptr) {
    root = new Tree(z);
    switch (student) {
      case 1:
        root->stud1 = true;
        break;
      case 2:
        root->stud2 = true;
        break;
      case 3:
        root->stud3 = true;
        break;
    }
  } else if (z < root->key) {
    root->left = insert(root->left, z, student);
  } else if (z > root->key) {
    root->right = insert(root->right, z, student);
  } else {
    switch (student) {
      case 1:
        root->stud1 = true;
        break;
      case 2:
        root->stud2 = true;
        break;
      case 3:
        root->stud3 = true;
        break;
    }
  }
  return root;
}

void inorder(Tree* root, std::vector<Tree*>& inOrder) {
  if (root != nullptr) {
    inorder(root->left, inOrder);
    inOrder.push_back(root);
    inorder(root->right, inOrder);
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
  Tree* root = nullptr;
  std::vector<Tree*> ans;
  std::string abc;
  int n;
  std::cin >> n;
  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  for (int student = 1; student <= 3; ++student) {
    for (int i = 0; i < n; ++i) {
      std::cin >> abc;
      root = insert(root, abc, student);
    }
  }
  inorder(root, ans);
  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i]->stud1 && !ans[i]->stud2 && !ans[i]->stud3) {
      sum1 += 3;
    } else if (!ans[i]->stud1 && ans[i]->stud2 && !ans[i]->stud3) {
      sum2 += 3;
    } else if (!ans[i]->stud1 && !ans[i]->stud2 && ans[i]->stud3) {
      sum3 += 3;
    } else if (ans[i]->stud1 && ans[i]->stud2 && !ans[i]->stud3) {
      sum1 += 1;
      sum2 += 1;
    } else if (!ans[i]->stud1 && ans[i]->stud2 && ans[i]->stud3) {
      sum2 += 1;
      sum3 += 1;
    } else if (ans[i]->stud1 && !ans[i]->stud2 && ans[i]->stud3) {
      sum1 += 1;
      sum3 += 1;
    }
  }
  std::cout << sum1 << " " << sum2 << " " << sum3;
  delete_tree(root);
  return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct Tree {
  std::string key;
  Tree* left;
  Tree* right;
  bool stud1;
  bool stud2;
  bool stud3;
  int height;

  Tree(std::string val) : key(val), left(nullptr), right(nullptr), stud1(false), stud2(false), stud3(false) , height(1) {}
};

int height(Tree* root) {
  return root?root->height:0;
}

int balanceroot(Tree* root) {
  return height(root->right) - height(root->left);
}


void fixheight(Tree* p)
{
  int hl = height(p->left);
  int hr = height(p->right);
  p->height = (hl > hr ? hl : hr)+1;
}

Tree* rotateright(Tree* p)
{
  Tree* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

Tree* rotateleft(Tree* q)
{
  Tree* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

Tree* balance(Tree* p)
{
  fixheight(p);
  if( balanceroot(p)==2 )
  {
    if( balanceroot(p->right) < 0 )
      p->right = rotateright(p->right);
    return rotateleft(p);
  }
  if( balanceroot(p)==-2)
  {
    if( balanceroot(p->left) > 0)
      p->left = rotateleft(p->left);
    return rotateright(p);
  }
  return p;
}

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
  root->height = std::max(height(root->left), height(root->right)) + 1;
  return balance(root);
}

void inorder(Tree* root, std::vector<Tree*>& inOrder) {
  if (root != nullptr) {
    inorder(root->left, inOrder);
    inOrder.push_back(root);
    inorder(root->right, inOrder);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
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
  return 0;
}

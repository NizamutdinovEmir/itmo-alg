#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "cstring"

int check(std::string x) {
  std::vector<bool> seen(256, false);

  int uniqueCount = 0;
  for (char ch : x) {
    if (!seen[ch]) {
      seen[ch] = true;
      ++uniqueCount;
    }
  }

  return uniqueCount;
}

int x = 0;
struct Tree {
  std::string key;
  Tree* left;
  Tree* right;
  int height;

  Tree(std::string val) : key(val), left(nullptr), right(nullptr), height(1) {}
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

Tree* insert(Tree* root, std::string z) {
  if (root == nullptr) {
    root = new Tree(z);
  } else if (z < root->key) {
    root->left = insert(root->left, z);
  } else if (z > root->key) {
    root->right = insert(root->right, z);
  } else {
    if (z.size() == 1) {
      x+=1;
    } else {
      x += check(z);
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
  int n;
  std::cin >> n;
  Tree* root = nullptr;
  std::string y;
  for (int i = 0;i<n;++i) {
    std::cin >> y;
    root = insert(root , y);
  }
  std::cout << x;
}

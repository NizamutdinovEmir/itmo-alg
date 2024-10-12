#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Tree {
  int key;
  int height;
  Tree* left;
  Tree* right;
  Tree(int val) : key(val) , left(nullptr) , right(nullptr) , height(1){}

};

int height(Tree* root) {
  return (root) ? root->height : 0;
}

int balance(Tree* root) {
  return height(root->right) - height(root->left);
}

Tree* maximum(Tree* root) {
  if (root->right == NULL) {
    return root;
  }
  return maximum(root->right);
}


Tree* fixheight(Tree* root) {
  if (root == NULL) {
    return root;
  }
  root->height = max(height(root->left), height(root->right)) + 1;
  return root;
}

Tree* rotateleft(Tree* q) {
  Tree* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

Tree* rotateright(Tree* p) {
  Tree* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}


Tree* balanceroot(Tree* p) {
  fixheight(p);
  if (balance(p) == 2) {
    if (balance(p->right) < 0)
      p->right = rotateright(p->right);
    return rotateleft(p);
  }
  if (balance(p) == -2) {
    if (balance(p->left) > 0)
      p->left = rotateleft(p->left);
    return rotateright(p);
  }
  return p;
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

Tree* insert(Tree* root, int z) {
  if (root == nullptr) {
    root = new Tree(z);
  } else if (z < root->key) {
    root->left = insert(root->left, z);
  } else if (z > root->key) {
    root->right = insert(root->right, z);
  }
  return balanceroot(root);
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
      return balanceroot(temp);
    } else if (root->right == nullptr) {
      Tree* temp = root->left;
      delete root;
      return balanceroot(temp);
    }

    Tree* temp = minimum(root->right);
    root->key = temp->key;
    root->right = delete_key(root->right, temp->key);
  }
  return balanceroot(root);
}

struct keys {
  int key, l, r;
  keys(int key = 0, int l=0, int r=0) : key(key), l(l), r(r) {}
};

Tree* build(Tree* tree, int i, vector <keys>& a) {
  if (i == -1) {
    return tree;
  }
  tree = new Tree(a[i].key);
  tree->left = fixheight(build(tree->left, a[i].l, a));
  tree->right = fixheight(build(tree->right, a[i].r, a));
  tree = fixheight(tree);

  return tree;
}


int main(){
  int n; cin >> n;
  vector <keys> a(n);
  for (int i = 0; i < n; i++) {
    int key, l, r;
    cin >> key >> l >> r; l--; r--;
    a[i] = keys(key, l, r);
  }
  int y;
  std::cin >> y;
  if (n == 0) {
    cout << 1 << '\n';
    cout << y << ' ' << 0 << ' ' << 0;
    return 0;
  }
  Tree* tree = NULL;
  tree = build(tree, 0, a);
  tree = insert(tree , y);
  tree = balanceroot(tree);
  queue <Tree*> tmp;
  tmp.push(tree);
  int cnt = 0;
  std::cout << n+1 << '\n';
  while (!tmp.empty()) {
    auto now = tmp.front();
    tmp.pop();
    int num1 = -1, num2 = -1;
    if (now->left != nullptr) {

      cnt++;
      num1 = cnt;
      tmp.push(now->left);
    }
    if (now->right != nullptr) {
      cnt++;
      num2 = cnt;
      tmp.push(now->right);
    }
    cout << now->key << ' ' << num1+1 << ' ' << num2+1 << '\n';
  }
}

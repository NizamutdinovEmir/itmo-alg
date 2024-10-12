#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
  long long key;
  long long left;
  long long right;
  long long height;
  long long balance;
  Tree(long long val) : key(val), left(0), right(0), height(1), balance(0) {}
};

long long updateHeightAndBalance(vector<Tree*>& nodes, int i) {
  if (i == 0) {
    return 0;
  }

  long long rightHeight = updateHeightAndBalance(nodes, nodes[i - 1]->right);
  long long leftHeight = updateHeightAndBalance(nodes, nodes[i - 1]->left);

  nodes[i - 1]->height = max(leftHeight, rightHeight) + 1;
  nodes[i - 1]->balance = rightHeight - leftHeight;

  return nodes[i - 1]->height;
}

int main() {
  int n;
  cin >> n;
  vector<Tree*> nodes;

  for (int i = 0; i < n; ++i) {
    long long k, l, r;
    cin >> k >> l >> r;
    nodes.push_back(new Tree(k));
    nodes[i]->left = l;
    nodes[i]->right = r;
  }

  updateHeightAndBalance(nodes , 1);
  for (int i = 0;i<n;++i) {
    cout << nodes[i]->balance << '\n';
  }
  return 0;
}

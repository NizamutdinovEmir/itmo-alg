#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Tree {
    string key;
    long long size;
    Tree* left;
    Tree* right;

    Tree(string val) : key(val), size(1) , left(nullptr), right(nullptr) {}
};


struct Tree *newTree(string item) {
    struct Tree* temp = new Tree(item);
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Tree* insert(Tree* root, string z) {
    if (root == nullptr) {
        return newTree(z);
    } else if (z <= root->key) {
        root->left = insert(root->left, z);
    } else if (z > root->key) {
        root->right = insert(root->right, z);
    }

    root->size = 1 + ((root->left != nullptr) ? root->left->size : 0) + ((root->right != nullptr) ? root->right->size : 0);

    return root;
}



string kmax(Tree* root, int k) {
    if (root == nullptr || k <= 0 || k > root->size) {
        return " ";
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




int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Tree* root = nullptr;
    int n;
    cin >> n;
    string x;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (isdigit(x[0]) == 1) {
            cout <<  kmax(root , count - stoi(x) + 1);
            cout << '\n';
        } else {
            root = insert(root , x);
            count++;
        }
    }
    return 0;
}

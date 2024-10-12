#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* next;

  Node(int _key) : key(_key), next(nullptr) {}
};

struct myList {
  Node *start;
  Node *finish;

  myList() : start(nullptr), finish(nullptr) {}

  bool is_empty() {
    return start == nullptr;
  }
  void push_start(int _key) {
    Node *p = new Node(_key);
    if (is_empty()) {
      start = p;
      finish = p;
      return;
    }
    p->next = start;
    start = p;
  }
  void push_back(int _key) {
    Node *p = new Node(_key);
    if (is_empty()) {
      start = p;
      finish = p;
      return;
    }
    finish->next = p;
    finish = p;
  }

  void delete_start() {
    if (is_empty()) return;
    Node *p = start;
    start = p->next;
    delete p;
  }
  void delete_finish() {
    if (is_empty()) return;
    if (start == finish) {
      delete_start();
      return;
    }
    Node *p = start;
    while (p->next != finish) p = p->next;
    p->next = nullptr;
    delete finish;
    finish = p;
  }
  void printtop() {
    if (is_empty()) return;
    cout << start->key;
  }
};
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  myList l;
  int n;
  cin >> n;
  char operation;
  long long message = 0;
  for (int i = 0;i<n;++i) {
    cin >> operation;
    if (operation == '+') {
      cin >> message;
      l.push_start(message);
    }
    else if (operation == '-') {
      l.printtop();
      l.delete_start();
      cout << '\n';
    }
  }
  return 0;
}
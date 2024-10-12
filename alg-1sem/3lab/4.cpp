#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* next;
  Node* prev;

  Node(int _key) : key(_key), next(nullptr) , prev(nullptr) {}
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
    start->prev = p;
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
    p->prev = finish;
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
    Node *p = finish;
    finish = p->prev;
    delete p;
  }
  int printtop() {
    if (is_empty()) return -1;
    return finish->key;
  }
  int printstart() {
    if (is_empty()) return -1;
    return start->key;
  }
  void print() {
    if (is_empty()) return;
    Node *p = start;
    while (p) {
      cout << p->key << " ";
      p = p->next;
    }
    cout << endl;
  }
};
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  myList l;
  int n , m;
  cin >> n >> m;
  for (int i = 0;i<n;++i){
    int x;
    cin >> x;
    if (i < m) {
      l.push_back(x);
    }
    if (i >= m) {
      int a = l.printtop();
      int b = l.printstart();
      l.delete_start();
      l.delete_finish();
      if (a >= b && a >= x) {
        if (b >= x) {
          l.push_back(b);
          l.push_back(a);
        }
        else{
          l.push_back(x);
          l.push_back(a);
        }
      }else if (b >= a && b >= x) {
        if (a >= x) {
          l.push_back(a);
          l.push_back(b);
        }
        else{
          l.push_back(x);
          l.push_back(b);
        }
      }if (x >= a && x >= b) {
        if (a >= b) {
          l.push_back(a);
          l.push_back(x);
        }
        else{
          l.push_back(b);
          l.push_back(x);
        }
      }
    }
    }

  l.print();
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;


struct Node {
  long long key;
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
  void push_back(long long _key) {
    Node *p = new Node(_key);
    if (is_empty()) {
      start = p;
      finish = p;
      return;
    }
    finish->next = p;
    p->prev = finish;
    p->next = nullptr;
    finish = p;
  }

  void delete_start() {
    if (is_empty()) return;

    Node *p = start;
    start = p->next;

    if (start)
      start->prev = nullptr;

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
    finish->next = nullptr;
    delete p;
  }
  int printtop() {
    if (is_empty()) {
      return -1;
    }
    return finish->key;
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
    int n;
    std::cin >> n;
    std::vector<int> result(n, -1);
    std::vector<int> difficulties(n);
    myList st;
    for (int i = 0; i < n; ++i) {
        std::cin >> difficulties[i];
    }

    for (int i = 0; i < n; ++i) {
        while ( difficulties[i] > difficulties[st.printtop()]  && !st.is_empty()) {
            result[st.printtop()] = i - st.printtop();
            st.delete_finish();
        }
        st.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}

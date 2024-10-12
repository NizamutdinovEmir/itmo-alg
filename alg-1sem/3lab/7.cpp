#include <iostream>
#include <vector>
using namespace std;


struct Node {
  long long key;
  Node* next;
  Node* prev;

  Node(long long _key) : key(_key), next(nullptr) , prev(nullptr) {}
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
  long long printtop() {
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
long long MaxArea(vector<long long> a, int n) {
  myList s;
  long long max = 0, top, area_top = 0;
  long long i = 0;

  while (i < n) {
    if (s.is_empty() || a[s.printtop()] <= a[i])
      s.push_back(i++);
    else {
      top = s.printtop();
      s.delete_finish();
      if (s.is_empty()) {
        area_top = a[top] * i;
      } else {
        area_top = a[top] * (i - s.printtop() - 1);
      }
      if (max < area_top)
        max = area_top;
    }
  }

  while (s.is_empty() == false) {
    top = s.printtop();
    s.delete_finish();
    if (s.is_empty()) {
      area_top = a[top] * i;
    } else {
      area_top = a[top] * (i - s.printtop() - 1);
    }
    if (max < area_top)
      max = area_top;
  }

  return max;
}
int main()
{
  long long n , x;
  cin >> n;
  vector <long long> wood(n);
  for (int i = 0;i<n;++i) {
    cin >> x;
    wood[i] = x;
  }
  long long ans = MaxArea(wood, n);
  cout << ans;
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[70000];
  for (int i = 0; i < n; ++i) {
    a[i] = i+1;
  }
  for (int i = 2; i < n;++i){
    swap(a[i] , a[i/2]);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
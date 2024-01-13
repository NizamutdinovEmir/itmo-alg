#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector <int> chair , int x , int k) {
  int boyar = 1;
  int last_boyar = chair[0];
  for (int c : chair) {
    if (c - last_boyar >= x) {
      boyar++;
      last_boyar = c;
    }
  }
  return boyar >= k;
}

int solve(vector <int> a , int k) {
  int left = 0;
  int right = a.back() - a[0] + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (check(a , mid , k)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

int main () {
  int n , k;
  cin >> n >> k;
  vector<int> a(n);
  int x;
  for (int i = 0;i < n;++i) {
    cin >> x;
    a[i] = x;
  }
  long long ans = solve(a , k);
  cout << ans;
  return 0;
}
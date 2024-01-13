#include <iostream>
#include <vector>



using namespace std;

void quicksort(vector <long long>& a, int l, int r) {
  int i = l;
  int j = r;
  int mid = a[l + rand() % (r - l + 1)];
  //int mid = a[(l+r) / 2];
  while (i <= j) {
    while ((a[i]) < (mid)) {
      i++;
    }
    while ((a[j]) > (mid)) {
      j--;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  if (l < j) {
    quicksort(a, l, j);
  }
  if (i < r) {
    quicksort(a, i, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  quicksort(a, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }

  return 0;
}

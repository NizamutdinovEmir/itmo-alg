#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& a, int left, int mid, int right) {
  long long count = 0;
  int it1 = 0, it2 = 0;
  vector<int> temp(right - left);

  while (left + it1 < mid && mid + it2 < right) {
    if (a[left + it1] <= a[mid + it2]) {
      temp[it1 + it2] = a[left + it1];
      it1 += 1;
    } else {
      temp[it1 + it2] = a[mid + it2];
      count += mid - left - it1;
      it2 += 1;
    }
  }

  while (left + it1 < mid) {
    temp[it1 + it2] = a[left + it1];
    it1 += 1;
  }

  while (mid + it2 < right) {
    temp[it1 + it2] = a[mid + it2];
    it2 += 1;
  }

  for (int i = 0; i < it1 + it2; ++i) {
    a[left + i] = temp[i];
  }

  return count;
}

long long mergeSort(vector<int>& a, int left, int right) {
  long long count = 0;

  if (left + 1 < right) {
    int mid = left + (right - left) / 2;
    count += mergeSort(a, left, mid);
    count += mergeSort(a, mid, right);
    count += merge(a, left, mid, right);
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long count = mergeSort(a, 0, n);

  cout << count << endl;

  return 0;
}

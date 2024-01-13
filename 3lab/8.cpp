#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quicksort(vector <long long>& a, int l, int r) {
  long long i = l;
  long long j = r;
  long long mid = a[(l+r) / 2];
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

long long upper_binserach(const std::vector<long long>& arr, long long x) {
  long long left = 0;
  long long right = arr.size();

  while (left < right) {
    long long mid = left + (right - left) / 2;

    if (arr[mid] <= x) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}


int main() {
  long long n, k;
  std::cin >> n >> k;

  std::vector<long long> womenCoefficients(n);
  std::vector<long long> menCoefficients(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> womenCoefficients[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> menCoefficients[i];
  }

  quicksort(womenCoefficients , 0 , n - 1);
  quicksort(menCoefficients, 0 , n - 1);

  long long left = 0;
  long long right = womenCoefficients[n - 1] + menCoefficients[n - 1];
  long long result = 0;

  while (left <= right) {
    long long mid = (left + right) / 2;
    long long count = 0;

    for (int i = 0; i < n; ++i) {
      long long x;
      x = mid - womenCoefficients[i];
      count += upper_binserach(menCoefficients, x);
    }

    if (count < k) {
      left = mid + 1;
    } else {
      result = mid;
      right = mid - 1;
    }
  }
  std::cout << result << std::endl;

  return 0;
}

#include <iostream>
using namespace std;

void quicksort(long long a[], int index[], int l, int r) {
  if (l >= r) {
    return;
  }

  int i = l;
  int j = r;
  int pivot = a[l + (r - l) / 2];

  while (i <= j) {
    while (a[i] > pivot) {
      i++;
    }
    while (a[j] < pivot) {
      j--;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      swap(index[i], index[j]);
      i++;
      j--;
    }
  }

  if (l < j) {
    quicksort(a, index, l, j);
  }
  if (i < r) {
    quicksort(a, index, i, r);
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int* rep = new int[n];
  long long* rat_film = new long long[m];
  int* rat_film_index = new int[m];

  for (int i = 0; i < n; ++i) {
    cin >> rep[i];
  }
  for (int i = 0; i < m; ++i) {
    rat_film[i] = 0;
    for (int j = 0; j < n; j++) {
      long long x;
      cin >> x;
      rat_film[i] += ((x * rep[j]) % 1000000007);
      rat_film[i] = rat_film[i] % 1000000007;
    }
    rat_film_index[i] = i + 1;
  }
  quicksort(rat_film, rat_film_index, 0, m - 1);

  for (int i = 0; i < k; i++) {
    cout << rat_film_index[i] << " ";
  }

  delete[] rep;
  delete[] rat_film;
  delete[] rat_film_index;
  return 0;
}

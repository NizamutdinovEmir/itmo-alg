#include <iostream>
using namespace std;

void quicksort(long long a[], int l , int r) {
  int i = l;
  int j = r;
  long long mid = a[(l+r) / 2];
  while(i <= j) {
    while (a[i] > mid) {
      ++i;
    }
    while(a[j] < mid) {
      --j;
    }
    if (i <= j) {
      swap(a[i] , a[j]);
      ++i;
      --j;
    }
  }
  if (l < j) {
    quicksort(a , l , j);
  }
  if (i < r) {
    quicksort(a , i , r);
  }
}

int main() {
  const int maxN = 1000000;
  long long a[maxN];
  int kolvo_vetok;
  cin >> kolvo_vetok;

  for (int i = 0; i < kolvo_vetok; ++i) {
    cin >> a[i];
  }

  quicksort(a, 0, kolvo_vetok - 1);
  long long ploshad = 0;
  int j = 0;
  long long array[maxN];

  for (int i = 0; i < kolvo_vetok-1; ++i) {
    if (a[i] > 0 && a[i+1] > 0 && (a[i] - a[i+1] <= 1)) {
      array[j] = min(a[i] , a[i+1]);
      a[i] = -1;
      a[i+1] = -1;
      j++;
      i++;
    }
  }

  if (j % 2 != 0) {
    j = j - 1;
  }
  int i = 0;
  while (i < j) {
    ploshad = ploshad + (array[i] * array[i+1]);
    i = i+2;
  }

  cout << ploshad;
  return 0;
}

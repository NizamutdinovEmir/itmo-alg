#include <iostream>

using namespace std;

void heapify(int a[], int n, int i) {
  int minim = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && a[l] > a[minim]) {
    minim = l;
  }
  if (r < n && a[r] > a[minim]) {
    minim = r;
  }

  if (minim != i) {
    swap(a[i], a[minim]);
    heapify(a, n, minim);
  }
}

void buildMinHeap(int a[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }
}

void heapSort(int a[], int n) {
  buildMinHeap(a, n);

  for (int i = n - 1; i > 0; i--) {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
}

int main() {
  int n;
  cin >> n;
  int a[1000000];
  for (int i = 0;i<n;++i){
    cin >> a[i];
  }
  heapSort(a, n);
  printArray(a, n);
}

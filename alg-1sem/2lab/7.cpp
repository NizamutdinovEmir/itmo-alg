#include <iostream>
using namespace std;

void quicksort(long long a[], long long index[] ,  int l, int r) {
  int i = l;
  int j = r;
  int mid = a[l + rand() % (r - l + 1)];
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
    quicksort(a , index, l, j);
  }
  if (i < r) {
    quicksort(a, index ,  i, r);
  }
}

int main(){
  int n;
  cin >> n;
  long long index[1000000];
  long long a[1000000];
  for (int i = 0 ; i < n;++i){
    cin >> a[i] >> index[i];
  }
  long long sum = 0, day = 0;
  quicksort(a , index , 0 , n-1);
  for (int i = 0;i<n;++i){
    day += a[i];
    sum += index[i] - day;
  }
  cout << sum;
  return 0;
}
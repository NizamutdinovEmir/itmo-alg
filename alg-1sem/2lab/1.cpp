#include <iostream>


using namespace std;

int main(){
  int n;
  cin >> n;
  long long a[10000];
  for (int i = 0;i<n;++i){
    cin >> a[i];
  }
  
  int j = 1;
  for (j;j<n;j++){
    int i , key;
    key = a[j];
    i = j - 1;
    while (i >= 0 && a[i] > key){
      a[i+1] = a[i];
      i = i - 1;
    }
    a[i+1] = key;
  }
  //вывод
  for (int i = 0;i<n;++i){
    cout<<a[i]<<" ";
  }
  return 0;
}
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  char slovo[1000000];
  cin >> n;
  for (int i = 0;i<n;++i) {
    cin >> slovo[i];
  }
  bool ans = false;
  int m = 1 , p = n - 1, l = 0,r = n-2;
  for (int i = 1;i < n;i++){
    if (slovo[l] == slovo[r]){
      m++;
      --p;
      ans = true;
    }
    else{
      break;
    }
  }
  if (ans == false){
    for (int i = 1;i < n;i++){
      int j = 0 , k = n-1;

      while(j < i && k>i){
        if (slovo[j] == slovo[k]){
          ++j;
          --k;
          ans = true;
        }
        else{
          ans = false;
          break;

        }
        break;
      }

    }
  }

  if (ans == true){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
  return 0;


}
#include <iostream>
#include <vector>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n , m , q;
  cin >> n >> m >> q;
  int kolvo_seriy = n*m;
  std::vector<bool> seriyi(kolvo_seriy);
  int seriy , sezon;
  int k = 0;
  int test1 = 0 , test2 = 0;
  for (int i = 0; i < q;++i){
    cin >> seriy >> sezon;
    seriyi[(sezon*m-m) + seriy -1] = true;
    if ((test1 != seriy) || (test2 != sezon)){
      k+=1;
      test1 = seriy;
      test2 = sezon;
    }
  }

  cout << kolvo_seriy - k << endl;
  for (int i = 0;i<kolvo_seriy;++i){
    if (seriyi[i] == 0){
      cout << (i % m) + 1 << " " << (i/m) + 1 << '\n';
    }
  }
  return 0;
}
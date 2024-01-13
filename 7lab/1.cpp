#include <iostream>
#include <vector>
#include "string"
#include "cmath"
using namespace std;

vector<string> gray(int n)
{
  if(n==1) {
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    return v;
  } else {
    vector<string> answer;
    vector<string> added;
    added=gray(n-1);

    for(int i=0;i<added.size();i++) {
      answer.push_back("0"+added[i]);
    }
    for(int i=(added.size()-1);i>-1;i--) {
      answer.push_back("1"+added[i]);
    }
    return answer;
  }
}

int main()
{
  int n; cin >> n;
  vector<string> ans;
  ans = gray(n);
  for (int i = 0;i < pow(2 , n);++i) {
    cout << ans[i] << '\n';
  }
}
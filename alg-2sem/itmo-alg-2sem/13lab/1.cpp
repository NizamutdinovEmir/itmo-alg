#include "iostream"
#include <vector>
#include "algorithm"

using namespace std;

void find(string& s , string& t , vector<int>& ans) {
    int n = s.size();
    int m = t.size();
    for (int i = 0; i <= n - m;++i) {
        string temp = s.substr(i,m);
        if (temp == t) {
            ans.push_back(i);
        }
    }
}

int main () {
    string s;
    string t;
    cin >> s;
    cin >> t;
    vector<int> ans;
    find(s , t , ans);
    std::cout << ans.size() << '\n';
    sort(ans.begin() , ans.end());
    for (auto& i : ans) {
        cout << i << " ";
    }
}
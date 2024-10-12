#include <iostream>
#include <vector>
#include <string>

using namespace std;

void suffix_prefix(string& s , vector<int>& ans, int n) {

    for (int i = 1; i < n; ++i) {
        int j = ans[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = ans[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        ans[i] = j;
    }

}

int main() {
    string s;
    cin >> s;

    vector<int> ans(s.length() , 0);

    suffix_prefix(s,ans , s.length());

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}

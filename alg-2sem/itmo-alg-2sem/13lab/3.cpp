#include <iostream>
#include "cstring"
#include "vector"

using namespace std;

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a , b , c;
    string temp1 , temp2;
    int count = 0;
    for (int i = 0; i < m;++i) {
        cin >> a >> b >> c;

        if (s.substr(a - 1, c) == s.substr(b - 1 , c))     {
            count++;
        }
    }
    cout << count;
}
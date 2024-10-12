#include "blazingio.hpp"
#include <vector>

#define int long long

using namespace std;

signed main () {
    int n;
    cin >> n;
    int x1;
    int x2;
    int x3;
    int y1;
    int y2;
    int y3;
    x1 = x2 =  x3 = y1 = y2 = y3 = 0;
    vector<int> a1(n);
    vector<int> a2(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a2[i];
    }

    for (int i = 0; i < n; ++i) {
        x1+=a1[i];
        x2*=a1[i];
        x3^=a1[i];
        y1+=a2[i];
        y2*=a2[i];
        y3^=a2[i];
    }
    if (x1 == y1 && x2 == y2 && x3 == y3) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
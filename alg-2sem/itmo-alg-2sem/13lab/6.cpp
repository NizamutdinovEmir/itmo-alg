#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int prime = 37;
int modul= 1e9 + 7;



signed main() {
    int n , m;
    cin >> n >> m;
    vector<int> counts(n);
    vector<int> hashes1(n), hashes2(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    b = a;
    std::reverse(b.begin(), b.end());
    counts[0] = 1;
    hashes1[0] = a[0];
    hashes2[0] = b[0];
    for (int i = 1; i < n; i++) {
        counts[i] = (counts[i - 1] * prime) % modul;
        hashes1[i] = (hashes1[i - 1] * prime + a[i]) % modul;
        hashes2[i] = (hashes2[i - 1] * prime + b[i]) % modul;
    }
    for (int i = n / 2; i > 0; i--) {
        if (n-2 * i != 0) {
            if (hashes1[i-1] == (hashes2[n - i - 1] - (hashes2[n - 2 * i - 1] * counts[i]) % modul + modul) % modul) {
                std::cout << n - i << ' ';
            }
        } else {
            if (hashes1[i-1] == hashes2[n - i - 1]) {
                std::cout << n - i << ' ';
            }
        }
    }
    cout << n;
    return 0;
}

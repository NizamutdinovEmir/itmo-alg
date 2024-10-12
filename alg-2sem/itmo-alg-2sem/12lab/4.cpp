#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int>tree1(n + 1);
    vector<int>tree2(n + 1);
    for (int i = 0; i < n-1;++i) {
        int a , b;
        cin >> a >> b;
        tree1[a]++;
        tree1[b]++;
    }
    for (int i = 0; i < n-1;++i) {
        int a , b;
        cin >> a >> b;
        tree2[a]++;
        tree2[b]++;
    }
    long long hash1 = 0;
    long long hash2 = 0;
    for (int i = 0; i<n+1;i++) {
        if(tree1[i]!=0) {
            hash1+=tree1[i]*tree1[i]*tree1[i];
        }
        if(tree2[i]!=0) {
            hash2+=tree2[i]*tree2[i]*tree2[i];
        }
    }
    if (hash1 == hash2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
#include <iostream>
#include <vector>

using namespace std;

class HashMap {
private:
    int size;
    vector<int> data{};

public:
    HashMap(int x) : size(x), data(x) {}

    int HashFunc(int x) {
        return (x % size);
    }

    void insert(int x) {
        int hash = HashFunc(x);
        data[hash]++;
    }

    int find(int x) {
        int hash = HashFunc(x);
        return data[hash];
    }

};

const int sdvig = 1000000;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> res(3 * sdvig);
    for (long long i = 0; i < n;++i) {
        cin >> a[i];
    }
    for (long long i = 0; i < n;++i) {
        res[a[i] - i + sdvig]+=1;
    }
    long long answer = 0;
    for (long long i = 0; i < 3 * sdvig;++i) {
        if (res[i]==0) continue;
        answer+=((res[i] * (res[i] - 1)))/2;
    }
    cout << answer;
}

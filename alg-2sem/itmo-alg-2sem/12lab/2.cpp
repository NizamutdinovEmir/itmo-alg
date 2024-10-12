#include "blazingio.hpp"
#include <vector>

using namespace std;

struct Student {
    int isu;
    int points;
};

class HashMap {
private:
    int size;
    vector<vector<Student>> data;

public:
    HashMap(int x) : size(x), data(x) {}

    int HashFunc(int x) {
        return (x % size);
    }

    void insert(int x , int y , int z) {
        int hash = HashFunc(z);
        data[hash].push_back({x , y});
    }

    bool find(int x , int z) {
        int hash = HashFunc(z);
        for (auto& i : data[hash]) {
            if (x == i.isu) {
                return true;
            }
        }
        return false;
    }

    void Delete(int x , int z) {
        int hash = HashFunc(z);
        for (auto it = data[hash].begin(); it != data[hash].end(); ++it) {
            if (x == it->isu) {
                data[hash].erase(it);
                break;
            }
        }
        return;
    }

    int maxim( int z) {
        int hash = HashFunc(z);
        int maxim = 0;
        for (auto& i : data[hash]) {
            if(maxim < i.points) {
                maxim = i.points;
            }
        }
        return maxim;
    }

    int mid(int z) {
        int hash = HashFunc(z);
        int middle = 0;
        for (auto& i : data[hash]) {
            middle+=i.points;
        }
        int size_hash = data[hash].size();
        middle = middle / size_hash;
        return middle;
    }


};

int main() {


    int m , q;
    cin >> m >> q;

    HashMap hashMap(m);

    for (int i = 0; i < q; ++i) {
        char c;
        int g;
        cin >> c >> g;
        if (c == '+') {
            int isu , points;
            cin >> isu >> points;
            hashMap.insert(isu , points , g);
        } else if (c == '-') {
            int isu;
            cin >> isu;
            hashMap.Delete(isu , g);
        } else if (c == 'a') { // средний

            cout << hashMap.mid(g) << '\n';

        } else { // самый высокий
            cout << hashMap.maxim(g) << '\n';
        }
    }

    return 0;
}

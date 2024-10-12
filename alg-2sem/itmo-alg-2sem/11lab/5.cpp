#include <iostream>
#include <vector>
#include "queue"
#include "algorithm"
using namespace std;

int main() {
    int n , m;
    std::cin >> n >> m;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    vector<int>q;

    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        auto flag = find(q.begin() , q.end() , a);
        if (flag == q.end()) {
            q.push_back(a);
        }
        auto flag2 = find(q.begin() , q.end() , b);
        if (flag2 == q.end()) {
            q.push_back(b);
        }
    }

    for (int i = 0; i < n*(n-1); ++i) {
        if (graph[q[0]][q[1]]) {
            q.push_back(q[0]);
            q.erase(q.begin());
        } else {
            int edge = -1;
            for (int j = 2; j < n*(n-1); ++j) {
                if (graph[q[0]-1][q[j]-1] && graph[q[1]-1][q[j+1]-1]) {
                    edge = j;
                    break;
                }
            }
            int j = 0;
            while (1 + j < edge - j) {
                q[1 + j], q[edge - j] = q[edge - j], q[1 + j];
                j+=1;
            }
        }
    }

    for (auto& i : q) {
        cout << i << " ";
    }

    return 0;
}

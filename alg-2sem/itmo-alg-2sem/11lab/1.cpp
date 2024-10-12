#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visit, vector<int>& match, int v) {
    if (visit[v]) {
        return false;
    }
    visit[v] = true;
    for (int u : graph[v]) {
        if (match[u] == -1 || dfs(graph, visit, match, match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> MatrixGraph(n + 1, vector<bool>(m + 1, false));
    vector<vector<int>> ListGraph((n + 1) * (m + 1));
    vector<bool> visit((n + 1) * (m + 1), false);
    vector<int> match((n + 1) * (m + 1), -1);
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        MatrixGraph[a][b] = true;
    }
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            if (!MatrixGraph[x][y]) {
                // проверка снизу
                if (y > 1 && !MatrixGraph[x][y - 1]) {
                    ListGraph[x * m + y].push_back(x * m + (y - 1));
                }
                // проверка сверху
                if (y < m && !MatrixGraph[x][y + 1]) {
                    ListGraph[x * m + y].push_back(x * m + (y + 1));
                }
                // проверка слева
                if (x > 1 && !MatrixGraph[x - 1][y]) {
                    ListGraph[x * m + y].push_back((x - 1) * m + y);
                }
                // проверка справа
                if (x < n && !MatrixGraph[x + 1][y]) {
                    ListGraph[x * m + y].push_back((x + 1) * m + y);
                }
            }
        }
    }
    int ans = 0;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            fill(visit.begin(), visit.end(), false);
            if (dfs(ListGraph, visit, match, (x * m + y))) {
                ans++;
            }
        }
    }
    cout << ans;
}

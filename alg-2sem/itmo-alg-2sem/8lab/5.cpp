#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, int current, int start, int count) {
    visit[current] = true;
    count++;
    for (int v : graph[current]) {
        if (!visit[v]) {
            if (dfs(graph, visit, v, start, count)) {
                return true;
            }
        } else if (v == start && count > 2) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    int x, y;

    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i < n + 1; ++i) {
        std::vector<bool> visit(n + 1, false);
        int count = 0;
        if (!visit[i] && dfs(graph, visit, i, i , count)) {
            std::cout << "YES" << '\n';
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}

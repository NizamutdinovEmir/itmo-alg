#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> answer;

void dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, int v) {
    visit[v] = true;
    for (int u : graph[v]) {
        if (!visit[u]) {
            dfs(graph, visit, u);
        }
    }
}

bool check(std::vector<std::vector<int>>& graph, int n) {
    for (int i = 1; i <= n; ++i) {
        if (graph[i].size() % 2 == 1) {
            return false;
        }
    }
    std::vector<bool> visit(n + 1, false);
    dfs(graph , visit, 1);
    for (int i = 1; i <= n; ++i) {
        if (!visit[i] && !graph[i].empty()) {
            return false;
        }
    }
    return true;
}

void euler(int v, std::vector<std::vector<int>>& graph) {
    while (!graph[v].empty()) {
        int u = graph[v][0];
        graph[v].erase(graph[v].begin());
        graph[u].erase(std::remove(graph[u].begin(), graph[u].end(), v), graph[u].end());
        euler(u, graph);
    }
    answer.push_back(v);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    int x, y;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if (check(graph, n)) {
        euler(1, graph);
        for (int i = answer.size() - 1; i >= 0; --i) {
            std::cout << answer[i] << " ";
        }
    } else {
        std::cout << ":(";
    }
    return 0;
}

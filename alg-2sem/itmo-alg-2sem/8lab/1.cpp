#include <iostream>
#include <stack>
#include <vector>

void dfs(std::vector<std::vector<int>>& graph, int u, std::vector<bool>& visit, std::stack<int>& tops) {
    visit[u] = true;
    for (int v : graph[u]) {
        if (!visit[v]) {
            dfs(graph, v, visit, tops);
        }
    }
    tops.push(u);
}

void topsort(int n, std::vector<std::vector<int>>& graph, std::stack<int>& tops , std::vector<int>& ans) {
    std::vector<bool> visit(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            dfs(graph, i, visit, tops);
        }
    }
    for(int i = 0; i < n;++i) {
        ans[tops.top()] = i + 1;
        tops.pop();
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    int x, y;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x-1].push_back(y-1);
    }

    std::stack<int> tops;
    std::vector<int> ans(n, 0);

    topsort(n, graph, tops , ans);
    return 0;
}

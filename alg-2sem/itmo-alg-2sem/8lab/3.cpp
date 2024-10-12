#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& graph, int u,  std::vector<bool>& visit) {
    visit[u] = true;
    for (int v : graph[u]) {
        if (!visit[v]) {
            dfs(graph , v , visit);
        }
    }
}

void answer(std::vector<std::vector<int>>& graph, std::vector<bool>& visit , int& count , int n) {
    for(int i = 0;i < n;++i) {
        if(!visit[i]) {
            dfs(graph , i , visit);
            count++;
        }
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    int x, y;

    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y-1].push_back(x-1);
    }

    std::vector<bool> visit(n, false);
    int count = 0;
    answer(graph , visit , count , n);

    std::cout << count;

    return 0;
}

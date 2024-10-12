#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visit , int a , int b) {
    if (a == b) {
        return true;
    }
    visit[a] = true;
    for (int v : graph[a]) {
        if (!visit[v]) {
            if (dfs(graph ,  visit , v , b)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n , m , q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int>> graph(n+1);
    int start , end;
    for (int i = 0 ; i < m ; ++i) {
        std::cin >> start >> end;
        graph[start].push_back(end);
    }
    int a , b;
    for (int i = 0;i < q;++i) {
        std::cin >> a >> b;
        std::vector<bool> visit1(n+1 , false);
        std::vector<bool> visit2(n+1 , false);
        if (dfs(graph, visit1, a, b) && dfs(graph, visit2, b ,  a)) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << "\n";
        }
    }

    return 0;
}

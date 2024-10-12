#include <iostream>
#include <vector>


void dfs(std::vector<std::vector<int>>& graph , std::vector<bool>& visit , int& count , int current) {
    visit[current] = true;
    count++;
    for (int u : graph[current]) {
        if (!visit[u]) {
            dfs(graph , visit , count , u);
        }
    }
}
int main () {
    int n , m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n+1);
    int x , y;
    for (int i = 0; i<m;++i) {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    std::vector<bool> visit(n+1 , false);
    int count = 0;
    dfs(graph , visit , count , 1);
    if (count == n && n == m) {
        std::cout << "ARCHIMEDES";
    } else {
        std::cout << "EUCLID";
    }
}
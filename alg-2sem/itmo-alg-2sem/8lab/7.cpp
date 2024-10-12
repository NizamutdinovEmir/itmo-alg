#include <iostream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>> graph , std::vector<int>& distance , int i , int k) {
    std::queue<int> queue;
    distance[i] = 0;
    queue.push(i);
    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for (int u : graph[v]) {
            if (distance[u] == -1) {
                distance[u] = distance[v] + 1;
                queue.push(u);
            }
        }
    }
}


int main() {
    int n;
    std::cin >> n;
    int m , k;
    std::cin >> m >> k;
    std::vector<std::vector<int>> graph(n+1);
    int x , y;
    for (int i = 1; i < m+1; ++i) {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    std::vector<int> distance(n+1 , -1);
    bfs(graph , distance , 1 , k);
    bool ans = false;
    for (int i = 1; i < n + 1;++i) {
        if (distance[i] == k) {
            ans  = true;
            std::cout << i << '\n';
        }
    }
    if (ans == false) {
        std::cout << "NO";
    }
}

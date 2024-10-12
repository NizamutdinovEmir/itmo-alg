#include <iostream>
#include <vector>
#define int unsigned long long

bool dfs(std::vector<std::vector<std::pair<int , int>>>& graph, std::vector<bool>& visit, int v, int parent , int& count , long long& sum) {
visit[v] = true;

for (auto& u : graph[v]) {
count++;
int neighbor = u.first;
int weight = u.second;
sum+=weight;
if (!visit[neighbor]) {
return dfs(graph, visit, neighbor, v , count , sum);

} else if (neighbor != parent) {
return true;
}

}
return false;
}

signed main() {
    int N, k;
    std::cin >> N >> k;
    for (int i = 0; i < N; ++i) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<std::pair<int , int>>> graph(n + 1);
        int x, y, weight;
        for (int z = 0; z < m; ++z) {
            std::cin >> x >> y >> weight;
            graph[x].emplace_back(y, weight);
        }
        bool ans = false;
        std::vector<bool> visit(n + 1, false);
        for (int j = 1; j <= n; ++j) {
            int count = 1;
            long long sum = 0;
            if (!visit[j]) {
                if (dfs(graph, visit, j , j , count , sum) && count > k && sum < 0) {
                    ans = true;
                    break;
                }
            }
        }
        if (ans == true) {
            std::cout << "NO" << '\n';
        } else {
            std::cout << "YES" << '\n';
        }
    }
    return 0;
}

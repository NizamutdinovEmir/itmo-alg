#include <iostream>
#include <vector>
int n;
std::vector<std::vector<int>> graph(500001);
std::vector<int> parents(500001);
std::vector<bool> visit(500001);
std::vector<int> deg(500001);
std::vector<int> answer;




void dfs(int v) {
    visit[v] = true;
    for (auto& u : graph[v]) {
        if (!visit[u] && u != parents[v]) {
            parents[u] = v;
            dfs(u);
        }
    }
}


void pruffer(int n) {
    int point = -1;
    dfs(n);
    for (int i = 1;i <= n;++i) {
        deg[i] = graph[i].size();
        if (deg[i] == 1 && point == -1) {
            point = i;
        }
    }
    int leaf = point;
    for (int i = 1; i <= n - 2;++i) {
        int next_egde = parents[leaf];
        answer.push_back(next_egde);
        deg[next_egde]-=1;
        if (deg[next_egde] == 1 && next_egde < point) {
            leaf = next_egde;
        } else {
            point+=1;
            while (point < n && deg[point] != 1) {
                point+=1;
            }
            leaf = point;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n , m;
    std::cin >> n >> m;
    int x , y;
    for (int i = 0; i < m;++i) {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    pruffer(n);
    for (int i = 0; i < answer.size();++i) {
        std::cout << answer[i] << " ";
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void dfs(std::vector<std::vector<int>>& graph , std::vector<bool>& visit , int v , int p , std::vector<int>& in , std::vector<int>& ret , std::set<std::pair<int, int>, std::less<>>& ans) {
    visit[v] = true;
    if (p == -1) {
        ret[v] = 0;
        in[v] = 0;
    } else {
        ret[v] = in[p] + 1;
        in[v] = in[p] + 1;
    }

    for (int u : graph[v]) {
        if (u == p) continue;
        if (visit[u]) {
            ret[v] = std::min(ret[v] , in[u]);
        } else {
            dfs(graph , visit , u , v , in , ret , ans);
            ret[v] = std::min(ret[v] , ret[u]);
            if (in[v] < ret[u]) {
                if (v < u) {
                    ans.insert({v , u});
                } else {
                    ans.insert({u , v});
                }
            }
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
    std::vector<bool> visit(n+1);
    std::vector<int> in(n+1);
    std::vector<int> ret(n+1);
    std::set<std::pair<int, int>, std::less<>>  ans;
    for (int i = 1; i <= n;++i) {
        if (!visit[i]) {
            dfs(graph , visit , i , -1 , in , ret , ans);
        }
    }
    for (auto v : ans) {
        std::cout << v.first << " " << v.second << '\n';
    }
}
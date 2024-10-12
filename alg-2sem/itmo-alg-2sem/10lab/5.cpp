#include <iostream>
#include <vector>
#include <set>
#include <stack>
std::stack<int> ans;
int color = 0;
void paint(int u , std::vector<int>& colors) {
    color++;
    int last = -1;
    while (last != u && (!ans.empty())) {
        colors[ans.top()] = color;
        last = ans.top();
        ans.pop();
    }
}

void dfs(std::vector<std::set<int>>& graph , std::vector<bool>& visit , int v , int p , std::vector<int>& in , std::vector<int>& ret , std::vector<int>& colors) {
    visit[v] = true;
    if (p == -1) {
        ret[v] = 0;
        in[v] = 0;
    } else {
        ret[v] = in[p] + 1;
        in[v] = in[p] + 1;
    }
    ans.push(v);
    for (int u : graph[v]) {
        if (u == p) continue;
        if (visit[u]) {
            ret[v] = std::min(ret[v] , in[u]);
        } else {
            dfs(graph , visit , u , v , in , ret , colors);
            ret[v] = std::min(ret[v] , ret[u]);
            if (in[v] < ret[u]) {
                paint(u , colors);
            }
        }
    }
}

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::set<int>> graph(n + 1);
    int x, y;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    int a, b;
    std::vector<bool> visit(n+1);
    std::vector<int> in(n+1);
    std::vector<int> ret(n+1);
    std::vector<int>colors(n+1);

    for (int i = 0;i < n+1;++i) {
        if (!visit[i]) {
            dfs(graph , visit , i , -1 , in , ret , colors);
        }
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> a >> b;
        if(colors[a] != colors[b]) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}

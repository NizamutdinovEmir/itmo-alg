#include <iostream>
#include <vector>
#include <climits>
#include <set>

void dfs1(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, std::vector<int>& ans, int i) {
    visit[i] = true;
    for (int v : graph[i]) {
        if (!visit[v]) {
            dfs1(graph, visit, ans, v);
        }
    }
    ans.push_back(i);
}

void dfs2(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, int& min, int& semiya, int i, std::vector<int>& component) {
    visit[i] = true;
    if (i < min) {
        min = i;
    }
    for (int v : graph[i]) {
        if (!visit[v]) {
            dfs2(graph, visit, min, semiya, v, component);
        }
    }
    component[i] = semiya + 1;
}


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<std::vector<int>> graph_reverse(n + 1);
    int x, y;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph_reverse[y].push_back(x);
    }

    std::vector<int> ans;
    std::vector<bool> visit1(n + 1, false);
    std::vector<bool> visit2(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visit1[i]) {
            dfs1(graph, visit1, ans, i);
        }
    }


    int semiya = 0;
    std::vector<int> component(n + 1);
    std::vector<int> min_house;
    for (int i = n - 1; i >= 0; --i) {
        int min = INT_MAX;
        int u = ans[i];
        if (!visit2[u]) {
            dfs2(graph_reverse, visit2, min, semiya, u, component);
            min_house.push_back(min);
            semiya++;
        }
    }


    std::set<std::pair<int, int>> otvet;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            int v = graph[i][j];
            if (component[i] != component[v]) {
                int x = min_house[component[i] - 1];
                int y = min_house[component[v] - 1];
                otvet.insert({x , y});
            }
        }
    }
    std::cout << semiya << " " <<  otvet.size() << '\n';

    for (const auto& edge : otvet) {
        std::cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}

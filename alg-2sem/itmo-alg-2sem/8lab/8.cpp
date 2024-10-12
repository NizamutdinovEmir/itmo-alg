#include <iostream>
#include <vector>

void read(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& graph2, int k , int n) {
    std::string func;
    for (int i = 0; i < k; ++i) {
        std::cin >> func;
        if (func[0] == '!') {
            int a = std::stoi(func.substr(1));
            graph[a].push_back(a + n);
            graph2[a + n].push_back(a);
        } else {
            int b;
            int a = std::stoi(func.substr(0));
            std::cin >> func >> b;
            if (func == "||") {
                graph[a + n].push_back(b);
                graph2[b].push_back(a + n);
                graph[b + n].push_back(a);
                graph2[a].push_back(b + n);
            } else if (func == "->") {
                graph[a].push_back(b);
                graph2[b].push_back(a);
                graph[b + n].push_back(a + n);
                graph2[a + n].push_back(b + n);
            } else if (func == "&") {
                graph[a + n].push_back(b);
                graph2[b].push_back(a + n);
                graph[b + n].push_back(a);
                graph2[a].push_back(b + n);
                graph[a + n].push_back(b + n);
                graph2[b + n].push_back(a + n);
                graph[b].push_back(a);
                graph2[a].push_back(b);
                graph[a].push_back(b);
                graph[b + n].push_back(a + n);
                graph2[b].push_back(a);
                graph2[a + n].push_back(b + n);
            } else if (func == "^") {
                graph[a].push_back(b + n);
                graph2[b + n].push_back(a);
                graph[b].push_back(a + n);
                graph2[a + n].push_back(b);
                graph[a + n].push_back(b);
                graph2[b].push_back(a + n);
                graph[b + n].push_back(a);
                graph2[a].push_back(b + n);
            }
        }
    }
}

void dfs1(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, std::vector<int>& ans, int i) {
    visit[i] = true;
    for (int v : graph[i]) {
        if (!visit[v]) {
            dfs1(graph, visit, ans, v);
        }
    }
    ans.push_back(i);
}

void dfs2(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, int& count, int i, std::vector<int>& component) {
    visit[i] = true;
    for (int v : graph[i]) {
        if (!visit[v]) {
            dfs2(graph, visit, count, v, component);
        }
    }
    component[i] = count + 1;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> graph(2 * n + 2);
    std::vector<std::vector<int>> graph2(2 * n + 2);

    read(graph, graph2, k , n);

    std::vector<bool> visit(2 * n + 2, false);
    std::vector<bool> visit2(2 * n + 2, false);
    std::vector<int> component(2 * n + 2);
    int count = 0;
    std::vector<int> ans;

    for (int i = 1; i < 2 * n + 2; ++i) {
        if (!visit[i]) {
            dfs1(graph, visit, ans, i);
        }
    }
    for (int i = 2 * n - 1; i >= 0; --i) {
        int u = ans[i];
        if (!visit2[u]) {
            dfs2(graph2, visit2, count, u, component);
            count++;
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        if (component[i] == component[i + n]) {
            std::cout << "NO" << "\n";
            return 0;
        }
    }
    std::cout << "YES" << "\n";

    return 0;
}

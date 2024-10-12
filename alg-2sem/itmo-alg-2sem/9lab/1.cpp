#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visit, std::vector<int>& predki, int v, int start) {
    visit[v] = true;
    for (int i : graph[v]) {
        if (!visit[i]) {
            dfs(graph, visit, predki, i, start);
        }
    }
    predki[v] = start;
}

int predok(int x, std::vector<int>& predki) {
    if (predki[x] == x) {
        return x;
    } else {
        return  predki[x] = predok(predki[x], predki);
    }
}

void pluss(int a, int b, std::vector<int>& predki) {
    a = predok(a , predki);
    b = predok(b ,predki);
    if (a!=b) {
        predki[a] = b;
    }
}



int main() {

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> predki(n + 1);
    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    std::vector<char> questions(q);
    std::vector<std::pair<int, int>> questions_graph(q);
    std::vector<std::string> ans;
    for (int i = 0; i < q; ++i) {
        char oper;
        int a, b;
        std::cin >> oper >> a >> b;
        questions[i] = oper;
        questions_graph[i] = {a, b};
        if (oper == '-') {
            auto it = std::find(graph[a].begin(), graph[a].end(), b);
            if (it != graph[a].end())
                graph[a].erase(it);

            it = std::find(graph[b].begin(), graph[b].end(), a);
            if (it != graph[b].end())
                graph[b].erase(it);

        }
    }
    std::vector<bool> visit(n + 1);

    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            dfs(graph, visit, predki, i, i);
        }
    }
    for (int i = q - 1; i >= 0; --i) {
        if (questions[i] == '?') {
            int x = questions_graph[i].first;
            int y = questions_graph[i].second;
            if (predok(x, predki) == predok(y, predki)) {
                ans.emplace_back("YES");
            } else {
                ans.emplace_back("NO");
            }
        } else if (questions[i] == '-') {
            int x = questions_graph[i].first;
            int y = questions_graph[i].second;
            pluss(x, y, predki);
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}

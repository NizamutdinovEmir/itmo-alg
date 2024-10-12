#include <algorithm>
#include <iostream>
#include <vector>
#define int long long

struct Edges_Graph {
    int x, y, weight;
};

bool my_sort(Edges_Graph& a, Edges_Graph& b) {
    return a.weight < b.weight;
}

int predok(int x, std::vector<int>& predki) {
    if (predki[x] == x) {
        return x;
    } else {
        return predki[x] = predok(predki[x], predki);
    }
}

void pluss(int a, int b, std::vector<int>& predki, std::vector<int>& weights) {
    a = predok(a, predki);
    b = predok(b, predki);
    if (weights[a] < weights[b]) {
        std::swap(a, b);
    }
    predki[b] = a;
    if (weights[a] == weights[b]) {
        weights[a]++;
    }
}

signed main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Edges_Graph> graph(m);
    int x, y, weight;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y >> weight;
        graph[i] = {x, y, weight};
    }
    std::vector<int> predki(n + 1);
    std::vector<int> weights(n + 1, 0);
    std::sort(graph.begin(), graph.end(), my_sort);
    for (int i = 1; i <= n; ++i) {
        predki[i] = i;
    }
    int ans = 0;
    for (auto& e : graph) {
        if (predok(e.x, predki) != predok(e.y, predki)) {
            ans += e.weight;
            pluss(e.x, e.y, predki, weights);
        }
    }
    std::cout << ans;
    return 0;
}

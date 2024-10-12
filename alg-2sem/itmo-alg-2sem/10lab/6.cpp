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
    std::vector<int> a;
    for (int i = 0; i < m;++i) {
        if (predok(graph[i].x, predki) != predok(graph[i].y, predki)) {
            ans += graph[i].weight;
            a.push_back(i);
            pluss(graph[i].x, graph[i].y, predki, weights);
        }
    }

    int ans2 = 9223372036854775807;

    for (int i = 0;i < a.size();++i) {
        for (int k = 1; k <= n; ++k) {
            predki[k] = k;
            weights[k] = 0;
        }
        int sum = 0;
        for (int j = 0; j < m;++j) {
            if (j != a[i]) {
                if (predok(graph[j].x, predki) != predok(graph[j].y, predki)) {
                    sum += graph[j].weight;
                    pluss(graph[j].x, graph[j].y, predki, weights);
                }
            }
        }
        ans2 = std::min(ans2 , sum);
    }

    std::cout << ans << " " << ans2;
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define int long long

struct Edges_Graph {
    int x, y, weight , check;
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<Edges_Graph> graph;
    std::vector<int> predki(n + 1);
    std::vector<int> weights(n + 1, 0);

    int x, y, z;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y >> z;
        graph.push_back({x, y, z , 0});

    }

    int a, b, c;
    for (int i = m; i < m+k; ++i) {
        std::cin >> a >> b >> c;
        graph.push_back({a, b, c , 1});
    }

    std::sort(graph.begin(), graph.end(), my_sort);

    for (int i = 0; i < n + 1; ++i) {
        predki[i] = i;
    }

    int plus = 0;
    int minus = 0;
    for (auto& e : graph) {
        if (predok(e.x, predki) != predok(e.y, predki)) {
            if (e.check == 1) {
                minus -= e.weight;
            }
            pluss(e.x, e.y, predki, weights);
        } else {
            if (e.check == 0) {
                plus+=e.weight;
            }
        }
    }

    int difference = minus + plus;
    if (difference < 0) {
        std::cout << -difference;
    } else {
        std::cout << 0;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct edge {
    int from, to, weight;
};

bool my_sort(edge& a, edge& b) {
    return a.weight < b.weight;
}

int find_parent(int x, std::vector<int>& predki) {
    if (predki[x] == x) {
        return x;
    } else {
        return predki[x] = find_parent(predki[x], predki);
    }
}

void union_sets(int a, int b, std::vector<int>& predki, std::vector<int>& weights) {
    a = find_parent(a, predki);
    b = find_parent(b, predki);
    if (weights[a] < weights[b]) {
        std::swap(a, b);
    }
    predki[b] = a;
    if (weights[a] == weights[b]) {
        weights[a]++;
    }
}

void dfs(int x, vector<int>& a, vector<int>& b, vector<int>& c, const vector<vector<pair<int,int>>>& adjacency_list, const vector<vector<int>>& children, vector<bool>& visited) {
if (visited[x]) {
return;
}
visited[x] = true;
int weight = 0;

for (const int& i : children[x]) {
dfs(i, a, b, c, adjacency_list, children, visited);
for (const auto& neighbor : adjacency_list[x]) {
if (neighbor.first == i) {
weight = neighbor.second;
break;
}
}
a[x] = max(a[x], b[i] + weight - c[i]);
b[x] += c[i];
}
a[x] += b[x];
c[x] = max(a[x], b[x]);
}


void fillChildren(vector<vector<int>>& graph, int v, vector<vector<int>>& children, int from) {
for (int i : graph[v]) {
if (i != from) {
children[v].push_back(i);
fillChildren(graph , i , children , v);
}
}
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> graph(m);
    for (int i = 0; i < m; ++i) {
        cin >> graph[i].from >> graph[i].to >> graph[i].weight;
    }
    sort(graph.begin(), graph.end(), my_sort);
    vector<int> parents(n + 1);
    vector<edge> mst;
    vector<vector<pair<int, int>>> adjacency_list(n+1);
    std::vector<int> weights(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
    }
    for (auto& e : graph) {
        if (find_parent(e.from, parents) != find_parent(e.to, parents)) {
            mst.push_back(e);
            adjacency_list[e.from].push_back({e.to , e.weight});
            adjacency_list[e.to].push_back({e.from , e.weight});
            union_sets(e.to , e.from , parents ,weights);
        }
    }

    vector<vector<int>> children(n + 1);
    vector<int> a(n+1, 0);
    vector<int>b (n+1, 0);
    vector<int> c(n+1, 0);
    vector<bool> visited(n+1, false);
    vector<vector<int>> graph_mst(n+1);
    for (int i = 0; i < mst.size();++i) {
        graph_mst[mst[i].from].push_back(mst[i].to);
        graph_mst[mst[i].to].push_back(mst[i].from);
    }
    fillChildren(graph_mst , 1 , children , -1);
    dfs(1, a, b, c, adjacency_list, children, visited);
    cout << c[1];

    return 0;
}

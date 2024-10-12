#include <iostream>
#include <queue>
#include <vector>
#include <limits>


using namespace std;


void dijkstra(std::vector<std::vector<std::pair<int , int>>>& graph, int start,  std::vector<long long>& distance , std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>>& pq) {
pq.emplace(0, start);
while(!pq.empty()) {
auto u = pq.top();
pq.pop();
for (std::pair<int , int> egde : graph[u.second]) {
long long weight = egde.first;
long long v = egde.second;

if (distance[v] == -1 || distance[v] > distance[u.second] + weight) {
distance[v] = distance[u.second] + weight;
pq.emplace(distance[v], v);
}
}
}
}




int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int , int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s;
        std::vector<int> island(s);
        cin >> t;
        for (int j = 0; j < s; ++j) {
            cin >> island[j];
        }
        for (int q = 0; q < island.size(); ++q) {
            for (int w = q; w < island.size(); ++w) {
                graph[island[q]].push_back({t , island[w]});
                graph[island[w]].push_back({t, island[q]});
            }
        }
    }
    std::vector<long long> distance(n + 1, -1);
    distance[1] = 0;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> pq;
    dijkstra(graph, 1, distance, pq);
    cout << distance[k];

    return 0;
}
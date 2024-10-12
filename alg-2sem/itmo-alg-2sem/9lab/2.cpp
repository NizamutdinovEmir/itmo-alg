#include <iostream>
#include <vector>
#include <queue>



void dijkstra(std::vector<std::vector<std::pair<long long, long long>>>& graph, int start, int n , std::vector<long long>& distance , std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>>& pq) {
pq.emplace(0, start);
while(!pq.empty()) {
auto u = pq.top();
pq.pop();
for (std::pair<long long , long long> egde : graph[u.second]) {
long long v = egde.first;
long long weight = egde.second;

if (distance[v] == -1 || distance[v] > distance[u.second] + weight) {
distance[v] = distance[u.second] + weight;
pq.emplace(distance[v], v);
}
}
}
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<long long, long long>>> graph(n);
    long long x, y, weight;

    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y >> weight;
        graph[x-1].emplace_back(y-1, weight);
    }


    std::vector<long long> distance(n , -1);
    distance[0] = 0;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> pq;

    dijkstra(graph , 0 , n , distance ,pq);
    std::cout << distance[n-1];

    return 0;
}

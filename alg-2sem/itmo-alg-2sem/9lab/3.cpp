#include <iostream>
#include <vector>
#include <queue>
#define int unsigned long long

void dijkstra(std::vector<std::vector<std::pair<int , int>>>& graph, int start, std::vector<int>& distance , std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>& pq , int n , int index) {
distance.assign(n , 18446744073709551615);
distance[index] = 0;
pq.emplace(0, start);
while(!pq.empty()) {
auto u = pq.top();
pq.pop();
if (u.first > distance[u.second]) continue;
for (std::pair<int , int> edge : graph[u.second]) {
int v = edge.first;
int weight = edge.second;

if (distance[v] > distance[u.second] + weight) {
distance[v] = distance[u.second] + weight;
pq.emplace(distance[v], v);
}
}
}
}

signed main() {
    int n , m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int , int>>> graph(n);
    for (int i = 0; i<m; ++i) {
        int x , y , weight;
        std::cin >> x >> y >> weight;
        graph[x-1].push_back({y-1 , weight});
        graph[y-1].push_back({x-1 , weight});
    }
    std::vector<int> distance_answer(n , 0);
    std::vector<int> distance(n , -1);
    for (int i = 0; i < n; ++i) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        dijkstra(graph , i ,distance , pq , n , i);
        for (int j = 0; j < n; ++j) {
            distance_answer[i] += distance[j];
        }
    }
    int minim = 18446744073709551615;
    int node = -1;
    for (int i = 0; i < n; ++i) {
        if (distance_answer[i] < minim) {
            minim = distance_answer[i];
            node = i;
        }
    }
    std::cout << node + 1;
    return 0;
}

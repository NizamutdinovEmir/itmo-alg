#include <iostream>
#include <vector>
#include <queue>
#include "limits"

using namespace std;

int bfs(vector<vector<int>>& graph, int start, int finish, int n, vector<int>& parent) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[start] = 0;

    q.push(start);
    while (!q.empty()) {
        int edge = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == -1 && graph[edge][i]) {
                parent[i] = edge;
                dist[i] = dist[edge] + 1;
                q.push(i);
            }
        }
    }
    int res = 2147483647;
    int flow = n;
    while(flow!=1) {
        res = min(graph[parent[flow]][flow] , res);
        flow = parent[flow];
    }
    return res;
}

int find_flow(vector<vector<int>>& graph, int start, int finish, int n) {
    int flow = 0;
    vector<int> parent(n + 1, -1);
    int flow2;
    while ((flow2 = bfs(graph, start, finish, n, parent))) {
        flow += flow2;
        int current = finish;
        while (current != start) {
            int prev = parent[current];
            graph[current][prev] += flow2;
            graph[prev][current] -= flow2;
            current = prev;
        }
    }
    return flow;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    int ans = find_flow(graph, 1, n, n);
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<pair<int, int>> graph[100]; // (neighbor, weight)

void Dijkstra(int start, int nodes) {
    vector<int> dist(nodes + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for(int i = 1; i <= nodes; i++)
        cout << "Node " << i << ": " << dist[i] << endl;
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter each edge (u v w):\n";
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    Dijkstra(start, nodes);
    return 0;
}


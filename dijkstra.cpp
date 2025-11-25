#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100], cost[100];
int dis[100], parent[100];

void dijkstra(int source, int n)
{
    priority_queue<pair<int, int>> pq; 

    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }

    dis[source] = 0;
    pq.push({-dis[source], source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int w = cost[u][i];

            // Relaxation step
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                parent[v] = u;
                pq.push({-dis[v], v});
            }
        }
    }
}

void printPath(int src, int des)
{
    if (des == -1) return;
    if (src == des) {
        cout << src << " ";
        return;
    }
    printPath(src, parent[des]);
    cout << des << " ";
}

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Directed graph
        graph[u].push_back(v);
        cost[u].push_back(w);
    }

    int source, destination;
    cout << "Enter source node: ";
    cin >> source;

    cout << "Enter destination node: ";
    cin >> destination;

    dijkstra(source, n);

    if (dis[destination] == INT_MAX) {
        cout << "No path exists!" << endl;
        return 0;
    }

    cout << "Shortest distance from " << source << " to " << destination 
         << " = " << dis[destination] << endl;

    cout << "Path: ";
    printPath(source, destination);
    cout << endl;

    return 0;
}

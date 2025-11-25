#include<bits/stdc++.h>
using namespace std;

vector<int> graph[200], cost[200];
int dis[200], parent[200];

void bellman_ford(int n, int source)
{
    for (int i = 1; i <= n; i++) {
        dis[i] = 100000;
        parent[i] = -1;
    }

    dis[source] = 0;

    // Relax edges n-1 times
    for (int k = 0; k < n - 1; k++) {
        for (int u = 1; u <= n; u++) {
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                int w = cost[u][j];

                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                }
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
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(v);
        cost[u].push_back(w);
    }

    int source, destination;
    cout << "Enter source node: ";
    cin >> source;

    cout << "Enter destination node: ";
    cin >> destination;

    bellman_ford(n, source);

    if (dis[destination] >= 100000) {
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

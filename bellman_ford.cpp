
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

struct Edge {
    int u, v, w;
};

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<Edge> edgeList(edges);
    cout << "Enter each edge (u v w):\n";
    for(int i = 0; i < edges; i++) {
        cin >> edgeList[i].u >> edgeList[i].v >> edgeList[i].w;
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<int> dist(nodes + 1, INF);
    dist[start] = 0;

    for(int i = 1; i < nodes; i++) {
        for(auto e : edgeList) {
            if(dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for(int i = 1; i <= nodes; i++)
        cout << "Node " << i << ": " << dist[i] << endl;

    return 0;
}

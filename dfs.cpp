#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) DFS(neighbor);
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter each edge (u v):\n";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);
    cout << endl;

    return 0;
}


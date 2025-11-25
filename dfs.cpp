#include <bits/stdc++.h>
using namespace std;

vector<int> graphList[100];
bool visited[100];

void DFS_Visit(int u) {
    visited[u] = true;
    cout << u << " ";   // process node

    for (int v : graphList[u]) {
        if (!visited[v]) {
            DFS_Visit(v);
        }
    }
}

void DFS(int n) {
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Call DFS_Visit for each unvisited vertex
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS_Visit(i);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graphList[u].push_back(v);  // directed graph
        graphList[v].push_back(u);  // remove if graph is directed only
    }

    cout << "DFS Traversal: ";
    DFS(n);

    return 0;
}

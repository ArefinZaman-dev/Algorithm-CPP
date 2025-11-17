#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100]; // adjacency list
bool visited[100];      // track visited nodes

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for(int neighbor : graph[current]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
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
        graph[v].push_back(u);  // Undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    BFS(start);

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

string color[100];
int dis[100];
int pred[100];

void BFS(vector<int> graph[], int source, int n) {
    for (int i = 0; i < n; i++) {
        color[i] = "w";
        dis[i] = INT_MAX;
        pred[i] = -1;
    }

    queue<int> q;
    color[source] = "g";
    dis[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == "w") {
                color[v] = "g";
                dis[v] = dis[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
        color[u] = "b";
    }
}

void printPath(int source, int des) {
    if (des == -1) return;
    if (des == source) {
        cout << source << " ";
        return;
    }
    printPath(source, pred[des]);
    cout << des << " ";
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> graph[100];

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected
    }

    int source, des;
    cout << "Enter source: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> des;

    BFS(graph, source, n);

    if (dis[des] == INT_MAX) {
        cout << "No path found!" << endl;
        return 0;
    }

    cout << "Distance from " << source << " to " << des << " = " << dis[des] << endl;
    cout << "Path: ";
    printPath(source, des);

    return 0;
}

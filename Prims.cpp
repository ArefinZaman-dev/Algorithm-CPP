#include<bits/stdc++.h>
using namespace std;

int prims(vector<int>graph[], vector<int>cost[], int start_node)
{
    priority_queue<pair<int,int> > pq;
    bool color[10];
    for (int i = 0; i < 10; i++) color[i] = false;
    pq.push({0, start_node});
    int c = 0;
    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        if (color[node.second] == false) {
            c = c + (-node.first);
            int u = node.second;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                int w = cost[u][i];

                if (color[v] == false) {
                    pq.push({-w, v});
                }
            }
            color[u] = true;
        }
    }
    return c;
}

int main()
{
    vector<int> graph[10], cost[10];
    int n, m;
    cout << "Enter no of Nodes: ";
    cin >> n;
    cout << "Enter no of Edges: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int mst_cost = prims(graph, cost, 1);
    cout << mst_cost << endl;
    return 0;
}


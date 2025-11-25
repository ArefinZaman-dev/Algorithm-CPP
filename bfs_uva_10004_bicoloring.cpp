#include <bits/stdc++.h>
using namespace std;

vector<int> graph[205];
int color[205];   // -1 = uncolored, 0 and 1 are the two colors

bool bfs_bicolorable(int start, int n)
{
    queue<int> q;
    color[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i];

            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u]) {
                // same color on both ends of an edge -> not bicolorable
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;

    while (cin >> n && n) {
        int l;
        cin >> l;

        // clear graph and color for this test case
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            color[i] = -1;
        }

        // read edges (undirected)
        for (int i = 0; i < l; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool ok = true;

        // graph may have multiple components
        for (int i = 0; i < n && ok; i++) {
            if (color[i] == -1) {
                if (!bfs_bicolorable(i, n)) {
                    ok = false;
                }
            }
        }

        if (ok) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}


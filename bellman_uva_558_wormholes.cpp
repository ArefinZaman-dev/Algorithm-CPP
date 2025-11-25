#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
const int INF = 1000000000;

vector<int> graph[MAXN], cost[MAXN];
int dist_arr[MAXN];

bool has_negative_cycle(int n)
{
    // initialize distances
    for (int i = 0; i < n; i++) {
        dist_arr[i] = INF;
    }
    dist_arr[0] = 0; // start from our solar system (node 0)

    // relax all edges (n - 1) times
    for (int k = 0; k < n - 1; k++) {
        bool changed = false;
        for (int u = 0; u < n; u++) {
            if (dist_arr[u] == INF) continue;
            for (int i = 0; i < (int)graph[u].size(); i++) {
                int v = graph[u][i];
                int w = cost[u][i];
                if (dist_arr[u] + w < dist_arr[v]) {
                    dist_arr[v] = dist_arr[u] + w;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    // one more pass to detect negative cycle
    for (int u = 0; u < n; u++) {
        if (dist_arr[u] == INF) continue;
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i];
            int w = cost[u][i];
            if (dist_arr[u] + w < dist_arr[v]) {
                return true; // negative cycle exists
            }
        }
    }

    return false;
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        // clear previous graph
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            cost[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int x, y, t;
            cin >> x >> y >> t;
            graph[x].push_back(y);
            cost[x].push_back(t);
        }

        if (has_negative_cycle(n)) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }

    return 0;
}


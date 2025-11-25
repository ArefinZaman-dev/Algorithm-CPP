#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 5;
const long long INF = (long long)1e15;

vector<int> graph2[MAXN], cost2[MAXN];
int busy[MAXN];
long long dist2_arr[MAXN];
bool negCycle[MAXN];

void bellman_ford(int n)
{
    // initialize distances and negative-cycle marks
    for (int i = 1; i <= n; i++) {
        dist2_arr[i] = INF;
        negCycle[i] = false;
    }
    dist2_arr[1] = 0; // source is junction 1

    // relax edges up to (n - 1) times
    for (int k = 0; k < n - 1; k++) {
        bool changed = false;
        for (int u = 1; u <= n; u++) {
            if (dist2_arr[u] == INF) continue;
            for (int i = 0; i < (int)graph2[u].size(); i++) {
                int v = graph2[u][i];
                int w = cost2[u][i];
                if (dist2_arr[u] + w < dist2_arr[v]) {
                    dist2_arr[v] = dist2_arr[u] + w;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    // detect nodes that are part of or reachable from a negative cycle
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (dist2_arr[u] == INF) continue;
        for (int i = 0; i < (int)graph2[u].size(); i++) {
            int v = graph2[u][i];
            int w = cost2[u][i];
            if (dist2_arr[u] + w < dist2_arr[v]) {
                if (!negCycle[v]) {
                    negCycle[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // propagate the bad effect of negative cycles
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)graph2[u].size(); i++) {
            int v = graph2[u][i];
            if (!negCycle[v]) {
                negCycle[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    int setNo = 1;

    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> busy[i];
        }

        // clear graph
        for (int i = 1; i <= n; i++) {
            graph2[i].clear();
            cost2[i].clear();
        }

        int r;
        cin >> r;
        for (int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            int diff = busy[v] - busy[u];
            int w = diff * diff * diff; // (busy[v] - busy[u])^3
            graph2[u].push_back(v);
            cost2[u].push_back(w);
        }

        bellman_ford(n);

        int q;
        cin >> q;
        cout << "Set #" << setNo++ << endl;
        while (q--) {
            int dest;
            cin >> dest;
            if (dest < 1 || dest > n ||
                dist2_arr[dest] == INF ||
                dist2_arr[dest] < 3 ||
                negCycle[dest]) {
                cout << "?" << endl;
            } else {
                cout << dist2_arr[dest] << endl;
            }
        }
    }

    return 0;
}


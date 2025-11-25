#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;
const long long INF = (long long)1e18;

vector<int> graph[MAXN], cost[MAXN];
long long dist_arr[MAXN];
int parent_arr[MAXN];

void dijkstra(int n)
{
    for (int i = 1; i <= n; i++) {
        dist_arr[i] = INF;
        parent_arr[i] = -1;
    }

    priority_queue< pair<long long,int> > pq; // (negative distance, node)
    dist_arr[1] = 0;
    pq.push({0LL, 1});

    while (!pq.empty()) {
        long long neg_d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        long long d = -neg_d;
        if (d != dist_arr[u]) continue; // outdated entry

        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i];
            int w = cost[u][i];
            long long nd = d + (long long)w;

            if (nd < dist_arr[v]) {
                dist_arr[v] = nd;
                parent_arr[v] = u;
                pq.push({-nd, v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(b);
        cost[a].push_back(w);
        graph[b].push_back(a);
        cost[b].push_back(w);
    }

    dijkstra(n);

    if (dist_arr[n] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    int curr = n;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent_arr[curr];
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}


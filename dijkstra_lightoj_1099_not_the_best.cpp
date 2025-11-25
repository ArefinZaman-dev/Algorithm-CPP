#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 5;
const long long INF = (long long)1e18;

vector<int> graph2[MAXN], cost2[MAXN];
long long dist1_arr[MAXN], dist2_arr[MAXN];

void dijkstra_second_shortest(int n)
{
    for (int i = 1; i <= n; i++) {
        dist1_arr[i] = INF;
        dist2_arr[i] = INF;
    }

    priority_queue< pair<long long,int> > pq;
    dist1_arr[1] = 0;
    pq.push({0LL, 1});

    while (!pq.empty()) {
        long long neg_d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        long long d = -neg_d;
        if (d > dist2_arr[u]) continue;

        for (int i = 0; i < (int)graph2[u].size(); i++) {
            int v = graph2[u][i];
            int w = cost2[u][i];
            long long nd = d + (long long)w;

            if (nd < dist1_arr[v]) {
                dist2_arr[v] = dist1_arr[v];
                dist1_arr[v] = nd;
                pq.push({-nd, v});
            }
            else if (nd > dist1_arr[v] && nd < dist2_arr[v]) {
                dist2_arr[v] = nd;
                pq.push({-nd, v});
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, R;
        cin >> N >> R;

        for (int i = 1; i <= N; i++) {
            graph2[i].clear();
            cost2[i].clear();
        }

        for (int i = 0; i < R; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph2[u].push_back(v);
            cost2[u].push_back(w);
            graph2[v].push_back(u);
            cost2[v].push_back(w);
        }

        dijkstra_second_shortest(N);

        cout << "Case " << tc << ": " << dist2_arr[N] << endl;
    }

    return 0;
}


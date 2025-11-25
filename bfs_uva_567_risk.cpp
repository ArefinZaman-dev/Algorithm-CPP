#include <bits/stdc++.h>
using namespace std;

vector<int> graph[21];
int dis_risk[21];

int bfs_risk(int src, int dest)
{
    for (int i = 1; i <= 20; i++) {
        dis_risk[i] = -1;
    }

    queue<int> q;
    dis_risk[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dest) break;

        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i];
            if (dis_risk[v] == -1) {
                dis_risk[v] = dis_risk[u] + 1;
                q.push(v);
            }
        }
    }

    return dis_risk[dest];
}

int main()
{
    int x;
    int testCase = 1;

    // read until EOF
    while (cin >> x) {
        // clear graph
        for (int i = 1; i <= 20; i++) {
            graph[i].clear();
        }

        // first line corresponds to country 1
        int cnt = x;
        for (int j = 0; j < cnt; j++) {
            int v;
            cin >> v;
            graph[1].push_back(v);
            graph[v].push_back(1);
        }

        // lines for countries 2..19
        for (int i = 2; i <= 19; i++) {
            cin >> cnt;
            for (int j = 0; j < cnt; j++) {
                int v;
                cin >> v;
                graph[i].push_back(v);
                graph[v].push_back(i);
            }
        }

        int q;
        cin >> q;

        cout << "Test Set #" << testCase++ << endl;

        while (q--) {
            int a, b;
            cin >> a >> b;
            int steps = bfs_risk(a, b);
            printf("%2d to %2d: %d\n", a, b, steps);
        }

        cout << endl;
    }

    return 0;
}


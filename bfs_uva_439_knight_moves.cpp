#include <bits/stdc++.h>
using namespace std;

int dr[] = { 2,  1, -1, -2, -2, -1,  1,  2};
int dc[] = { 1,  2,  2,  1, -1, -2, -2, -1};

int dis_knight[8][8];

bool inside(int r, int c)
{
    return (r >= 0 && r < 8 && c >= 0 && c < 8);
}

int bfs_knight(int sr, int sc, int tr, int tc)
{
    // initialize distances as unvisited
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dis_knight[i][j] = -1;
        }
    }

    queue< pair<int,int> > q;
    q.push({sr, sc});
    dis_knight[sr][sc] = 0;

    while (!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();

        int ur = u.first;
        int uc = u.second;

        if (ur == tr && uc == tc) {
            // already reached destination with minimum moves
            return dis_knight[tr][tc];
        }

        for (int k = 0; k < 8; k++) {
            int vr = ur + dr[k];
            int vc = uc + dc[k];

            if (inside(vr, vc) && dis_knight[vr][vc] == -1) {
                dis_knight[vr][vc] = dis_knight[ur][uc] + 1;
                q.push({vr, vc});
            }
        }
    }

    return dis_knight[tr][tc];   // should always be reachable
}

int main()
{
    string from, to;

    // each line has two squares, until EOF
    while (cin >> from >> to) {
        int sc = from[0] - 'a';   // column 0..7
        int sr = from[1] - '1';   // row    0..7

        int tc = to[0] - 'a';
        int tr = to[1] - '1';

        int moves = bfs_knight(sr, sc, tr, tc);

        cout << "To get from " << from << " to " << to
             << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}


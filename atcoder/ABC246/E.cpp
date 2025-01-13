#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Bishop 2
//    https://atcoder.jp/contests/abc246/tasks/abc246_e



using T = tuple<int, int, int, int>;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int main() {
    int N, Ax, Ay, Bx, By;
    cin >> N >> Ax >> Ay >> Bx >> By;
    Ax--; Ay--; Bx--; By--;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int INF = INT_MAX;
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    priority_queue<T, vector<T>, greater<T>> q;
    for(int i = 0; i < 4; i++) {
        dist[Ax][Ay][i] = 1;
        q.emplace(1, Ax, Ay, i);
    }

    while(!q.empty()) {
        auto[d, x, y, t] = q.top();
        q.pop();
        if(dist[x][y][t] != d) continue;
        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            int nex = d + (k == t ? 0 : 1);
            if(i < 0 || i >= N || j < 0 || j >= N) continue;
            if(S[i][j] == '#' || dist[i][j][k] <= nex) continue;
            dist[i][j][k] = nex;
            q.emplace(nex, i, j, k);
        }
    }

    int ans = INF;
    for(int i = 0; i < 4; i++) ans = min(ans, dist[Bx][By][i]);
    cout << (ans != INF ? ans : -1) << endl;
}
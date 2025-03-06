#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Synchronized Players
//    https://atcoder.jp/contests/abc339/tasks/abc339_d



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int si = -1, sj = -1, ti = -1, tj = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'P') {
                if(si == -1) {
                    si = i;
                    sj = j;
                }
                else {
                    ti = i;
                    tj = j;
                }
            }
        }
    }

    int INF = 1e9;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector dist(N, vector(N, vector(N, vector<int>(N, INF))));
    dist[si][sj][ti][tj] = 0;
    queue<tuple<int, int, int, int>> q;
    q.emplace(si, sj, ti, tj);
    while(!q.empty()) {
        auto[x1, y1, x2, y2] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx1 = x1 + dx[k];
            int ny1 = y1 + dy[k];
            int nx2 = x2 + dx[k];
            int ny2 = y2 + dy[k];
            if(nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N || S[nx1][ny1] == '#') {
                nx1 -= dx[k];
                ny1 -= dy[k];
            }
            if(nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N || S[nx2][ny2] == '#') {
                nx2 -= dx[k];
                ny2 -= dy[k];
            }
            if(dist[nx1][ny1][nx2][ny2] != INF) continue;
            dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2] + 1;
            q.emplace(nx1, ny1, nx2, ny2);
        }
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans = min(ans, dist[i][j][i][j]);
        }
    }

    cout << (ans != INF ? ans : -1) << endl;
}
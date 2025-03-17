#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Medicines on Grid
//    https://atcoder.jp/contests/abc348/tasks/abc348_d



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    for(auto& a : A) cin >> a;

    int si = -1, sj = -1, ti = -1, tj = -1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if(A[i][j] == 'T') {
                ti = i;
                tj = j;
            }
        }
    }

    int N;
    cin >> N;
    vector<tuple<int, int, int>> P;
    for(int i = 0; i < N; i++) {
        int R, C, E;
        cin >> R >> C >> E;
        R--; C--;
        P.emplace_back(R, C, E);
    }

    P.emplace_back(si, sj, 0);
    P.emplace_back(ti, tj, 0);
    N += 2;
    int INF = 1e9;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        auto[x1, y1, E1] = P[i];
        vector<vector<int>> dist(H, vector<int>(W, INF));
        dist[x1][y1] = 0;
        queue<pair<int, int>> q;
        q.emplace(x1, y1);
        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(A[nx][ny] == '#' || dist[nx][ny] != INF) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
        for(int j = 0; j < N; j++) {
            auto[x2, y2, E2] = P[j];
            if(dist[x2][y2] <= E1) G[i].push_back(j);
        }
    }

    int s = N-2, t = N-1;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int p) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) continue;
            dfs(dfs, c);
        }
    };

    dfs(dfs, s);
    cout << (ok[t] ? "Yes" : "No") << endl;
}
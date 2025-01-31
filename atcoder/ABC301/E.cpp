#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Pac-Takahashi
//    https://atcoder.jp/contests/abc301/tasks/abc301_e



int main() {
    int H, W, T;
    cin >> H >> W >> T;

    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    int si = -1, sj = -1, ti = -1, tj = -1;
    vector<pair<int, int>> P;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 'S') {
                si = i;
                sj = j;
            } 
            if(A[i][j] == 'G') {
                ti = i;
                tj = j;
            }
            if(A[i][j] == 'o') {
                P.emplace_back(i, j);
            }
        }
    }

    P.emplace_back(si, sj);
    P.emplace_back(ti, tj);
    int N = P.size();
    int s = N - 2, t = N - 1, INF = INT_MAX / 2;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N; i++) {
        auto[x1, y1] = P[i];
        vector<vector<int>> dist(H, vector<int>(W, INF));
        dist[x1][y1] = 0;
        queue<pair<int, int>> q;
        q.emplace(x1, y1);
        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if(i < 0 || i >= H || j < 0 || j >= W) continue;
                if(A[i][j] == '#' || dist[i][j] != INF) continue;
                dist[i][j] = dist[x][y] + 1;
                q.emplace(i, j);
            }
        }

        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            auto[x2, y2] = P[j];
            if(dist[x2][y2] <= T) {
                G[i].emplace_back(j, dist[x2][y2]);
            }
        }
    }

    int N2 = 1 << N;
    vector<vector<int>> dp(N2, vector<int>(N, INF));
    dp[1 << s][s] = 0;
    for(int i = 0; i < N2; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j] == INF) continue;
            for(auto[k, cost] : G[j]) {
                int nex = i | (1 << k);
                int sum = dp[i][j] + cost;
                if(sum <= T) dp[nex][k] = min(dp[nex][k], sum);
            }
        }
    }

    int ans = -1;
    for(int i = 0; i < N2; i++) {
        if(~i >> s & 1 || ~i >> t & 1) continue;
        if(dp[i][t] <= T) ans = max(ans, (int)__popcount(i) - 2);
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Negative Traveling Salesman
//    https://atcoder.jp/contests/abc338/tasks/abc338_f



int main() {
    int N, M;
    cin >> N >> M;

    long long INF = LLONG_MAX / 2;
    vector<vector<long long>> dist(N, vector<long long>(N, INF));
    for(int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for(int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U--; V--;
        dist[U][V] = W;
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int N2 = 1 << N;
    vector<vector<long long>> dp(N2, vector<long long>(N, INF));
    for(int i = 0; i < N; i++) {
        dp[1 << i][i] = 0;
    }

    for(int i = 0; i < N2; i++) {
        for(int j = 0; j < N; j++) {
            if(~i >> j & 1) continue;
            if(dp[i][j] == INF) continue;
            for(int k = 0; k < N; k++) {
                if(i >> k & 1) continue;
                if(dist[j][k] == INF) continue;
                int nex = i | (1 << k);
                long long sum = dp[i][j] + dist[j][k];
                dp[nex][k] = min(dp[nex][k], sum);
            }
        }
    }

    long long ans = INF;
    for(int i = 0; i < N; i++) {
        ans = min(ans, dp[N2-1][i]);
    }

    if(ans != INF) cout << ans << endl;
    else cout << "No" << endl; 
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Product Development
//    https://atcoder.jp/contests/abc322/tasks/abc322_e



int main() {
    int N, K, P;
    cin >> N >> K >> P;
    
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(K));
    for(int i = 0; i < N; i++) {
        cin >> C[i];
        for(int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }

    long long INF = 1e18;
    vector dp(N+1, vector(6, vector(6, vector(6, vector(6, vector(6, INF))))));

    auto func = [&](int i, int a, int b, int c, int d, int e) {
        if(dp[i][a][b][c][d][e] == INF) return;
        dp[i+1][a][b][c][d][e] = min(dp[i+1][a][b][c][d][e], dp[i][a][b][c][d][e]);
        int na = a, nb = b, nc = c, nd = d, ne = e;
        na = min(P, a + A[i][0]); 
        if(1 < K) nb = min(P, b + A[i][1]); 
        if(2 < K) nc = min(P, c + A[i][2]); 
        if(3 < K) nd = min(P, d + A[i][3]); 
        if(4 < K) ne = min(P, e + A[i][4]); 
        long long sum = dp[i][a][b][c][d][e] + C[i];
        dp[i+1][na][nb][nc][nd][ne] = min(dp[i+1][na][nb][nc][nd][ne], sum);
    };

    dp[0][0][0][0][0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int a = 0; a <= P; a++) {
            for(int b = 0; b <= P; b++) {
                for(int c = 0; c <= P; c++) {
                    for(int d = 0; d <= P; d++) {
                        for(int e = 0; e <= P; e++) {
                            func(i, a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }

    long long ans = INF;
    if(K == 1) ans = dp[N][P][0][0][0][0];
    if(K == 2) ans = dp[N][P][P][0][0][0];
    if(K == 3) ans = dp[N][P][P][P][0][0];
    if(K == 4) ans = dp[N][P][P][P][P][0];
    if(K == 5) ans = dp[N][P][P][P][P][P];
    if(ans == INF) ans = -1;

    cout << ans << endl;
}
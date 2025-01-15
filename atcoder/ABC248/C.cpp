#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Dice Sum
//    https://atcoder.jp/contests/abc248/tasks/abc248_c



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector dp(N+1, vector(M+1, vector<mint>(K+1)));
    dp[0][0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M; j++) {
            for(int l = 0; l < K; l++) {
                for(int d = 1; d <= M; d++) {
                    if(l + d > K) break;
                    dp[i+1][d][l + d] += dp[i][j][l];
                }
            }
        }
    }

    mint ans = 0;
    for(int j = 0; j <= M; j++) {
        for(int l = 0; l <= K; l++) {
            ans += dp[N][j][l];
        }
    }

    cout << ans.val() << endl;
}
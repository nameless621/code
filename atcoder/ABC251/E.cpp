#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Takahashi and Animals
//    https://atcoder.jp/contests/abc251/tasks/abc251_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long INF = LLONG_MAX;
    vector dp(N+1, vector(2, vector<long long>(2, INF)));
    dp[0][0][0] = dp[0][1][1] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                if(dp[i][j][k] == INF) continue;
                for(int l = 0; l < 2; l++) {
                    if(k == 0 && l == 0) continue;
                    dp[i+1][j][l] = min(dp[i+1][j][l], dp[i][j][k] + A[i] * l);
                }
            }
        }
    }

    long long ans = INF;
    for(int j = 0; j < 2; j++) ans = min(ans, dp[N][j][j]);
    cout << ans << endl;
}

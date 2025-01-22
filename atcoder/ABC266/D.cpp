#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Snuke Panic (1D)
//    https://atcoder.jp/contests/abc266/tasks/abc266_c



int main() {
    int N;
    cin >> N;

    int M = 1e5+9;
    vector T(M, vector(5, 0));
    for(int i = 0; i < N; i++) {
        int idx, X, A;
        cin >> idx >> X >> A;
        T[idx][X] = A;
    }

    long long INF = -1e18;
    vector dp(M, vector(5, INF));
    dp[0][0] = 0;
    for(int i = 0; i < M-1; i++) {
        for(int j = 0; j < 5; j++) {
            if(j+1 < 5) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + T[i+1][j+1]);
            if(j-1 >= 0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + T[i+1][j-1]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + T[i+1][j]);
        }
    }

    long long ans = INF;
    for(int j = 0; j < 5; j++) {
        ans = max(ans, dp[M-1][j]);
    }

    cout << ans << endl;
}
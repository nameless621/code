#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Index × A(Not Continuous ver.) 
//    https://atcoder.jp/contests/abc267/tasks/abc267_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long INF = -1e18;
    vector<vector<long long>> dp(N+1, vector<long long>(M+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M; j++) {
            if(dp[i][j] == INF) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+1 <= M) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + A[i] * (j+1));
        }
    }

    cout << dp[N][M] << endl;
}
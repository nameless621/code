#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Flipping and Bonus
//    https://atcoder.jp/contests/abc254/tasks/abc261_d



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];

    vector<int> bonus(N+1);
    for(int i = 0; i < M; i++) {
        int C, Y;
        cin >> C >> Y;
        bonus[C] = Y;
    }

    long long INF = -1e18;
    vector dp(N+1, vector(N+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            if(dp[i][j] == INF) continue;
            dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
            if(j+1 <= N) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + X[i] + bonus[j+1]);
        }
    }

    long long ans = INF;
    for(int j = 0; j <= N; j++) {
        ans = max(ans, dp[N][j]);
    }

    cout << ans << endl;
}
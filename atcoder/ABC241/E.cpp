#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Putting Candies
//    https://atcoder.jp/contests/abc241/tasks/abc241_e



int main() {
    int N;
    long long K;
    cin >> N >> K;

    int M = 60;
    vector<vector<long long>> dp(M, vector<long long>(N));
    for(int i = 0; i < N; i++) cin >> dp[0][i];

    for(int i = 0; i < M - 1; i++) {
        for(int j = 0; j < N; j++) {
            dp[i+1][j] = dp[i][j] + dp[i][(j + dp[i][j]) % N];
        }
    }

    long long ans = 0;
    for(int i = 0; i < M; i++) {
        if(K >> i & 1) ans += dp[i][ans % N];
    }

    cout << ans << endl;
}
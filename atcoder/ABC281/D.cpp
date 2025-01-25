#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Max Multiple
//    https://atcoder.jp/contests/abc281/tasks/abc281_d



int main() {
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    long long INF = -1e18;
    vector dp(N+1, vector(K+1, vector(D, INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            for(int l = 0; l < D; l++) {
                if(dp[i][j][l] == INF) continue;
                dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);
                if(j+1 <= K) {
                    long long sum = dp[i][j][l] + a[i];
                    dp[i+1][j+1][sum % D] = max(dp[i+1][j+1][sum % D], sum);
                }
            }
        }
    }

    long long ans = dp[N][K][0];
    if(ans == INF) ans = -1;
    cout << ans << endl;
}
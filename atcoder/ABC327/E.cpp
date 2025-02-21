#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Maximize Rating 
//    https://atcoder.jp/contests/abc327/tasks/abc327_e



double dpow(double x, int n) {
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    
    vector<double> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    reverse(P.begin(), P.end());

    double INF = -1e18;
    vector<vector<double>> dp(N+1, vector<double>(N+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            if(dp[i][j] == INF) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+1 <= N) {
                double sum = dp[i][j] + P[i] * dpow(0.9, j);
                dp[i+1][j+1] = max(dp[i+1][j+1], sum);
            }
        }
    }

    vector<double> d(N+1);
    for(int i = 0; i < N; i++) {
        d[i+1] = d[i] + dpow(0.9, i);
    }

    double ans = INF;
    for(int j = 1; j <= N; j++) {
        double R = dp[N][j] / d[j] - 1200.0 / sqrt(j);
        ans = max(ans, R);
    }

    cout << fixed << setprecision(12) << ans << endl;
}
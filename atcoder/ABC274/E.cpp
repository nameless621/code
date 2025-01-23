#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Booster
//    https://atcoder.jp/contests/abc274/tasks/abc274_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<double> X(N + M + 1), Y(N + M + 1);
    for(int i = 0; i < N + M; i++) {
        cin >> X[i+1] >> Y[i+1];
    }

    int n2 = 1 << (N + M + 1);
    double INF = 1e18;
    vector dp(n2, vector(N + M + 1, INF));
    dp[1][0] = 0;
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < N + M + 1; j++) {
            if(dp[i][j] == INF) continue;

            int cnt = 0;
            for(int k = N+1; k < N + M + 1; k++) {
                if(i >> k & 1) cnt++;
            }

            for(int k = 1; k < N + M + 1; k++) {
                int nex = i | (1 << k);
                double dx = X[j] - X[k];
                double dy = Y[j] - Y[k];
                double d = sqrt(dx*dx + dy*dy);
                d *= pow(0.5, cnt);
                dp[nex][k] = min(dp[nex][k], dp[i][j] + d);
            }
        }
    }

    double ans = INF;
    for(int i = 0; i < n2; i++) {
        for(int j = 1; j < N + M + 1; j++) {
            if(dp[i][j] == INF) continue;
            bool flag = false;
            for(int k = 0; k <= N; k++) {
                if(~i >> k & 1) flag = true; 
            }
            if(flag) continue;
            int cnt = 0;
            for(int k = N+1; k < N + M + 1; k++) {
                if(i >> k & 1) cnt++;
            }
            double d = sqrt(X[j]*X[j] + Y[j]*Y[j]);
            d *= pow(0.5, cnt);
            ans = min(ans, dp[i][j] + d);
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}
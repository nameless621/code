#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Shortcuts
//    https://atcoder.jp/contests/abc315/tasks/abc315_f



int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    auto Edist = [&](int i, int j) {
        double x = X[i] - X[j];
        double y = Y[i] - Y[j];
        double dist = sqrt(x*x + y*y);
        return dist;
    };

    int M = 61;
    double INF = DBL_MAX / 2;
    vector<vector<double>> dp(N, vector<double>(M, INF));
    dp[0][0] = 0;
    for(int i = 1; i < N; i++) {
        for(int j = max(0, i-M); j < i; j++) {
            for(int k = 0; k < M; k++) {
                if(dp[j][k] == INF) continue;
                int nex = i - j - 1 + k;
                if(nex >= M) continue;
                dp[i][nex] = min(dp[i][nex], dp[j][k] + Edist(i, j));
            }
        }
    }

    double ans = INF;
    for(int j = 0; j < M; j++) {
        double res = dp[N-1][j];
        if(res == INF) continue;
        if(j > 0) res += pow(2, j-1);
        ans = min(ans, res);
    }

    cout << fixed << setprecision(12) << ans << endl;
}
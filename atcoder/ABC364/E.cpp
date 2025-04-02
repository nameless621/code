#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Maximum Glutton
//    https://atcoder.jp/contests/abc364/tasks/abc364_e



int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int INF = INT_MAX / 2;
    vector dp(N+1, vector(N+1, vector<int>(X+1, INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= X; k++) {
                if(dp[i][j][k] == INF) continue;
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if(j+1 <= N && k+A[i] <= X) {
                    dp[i+1][j+1][k+A[i]] = min(dp[i+1][j+1][j+A[i]], dp[i][j][k] + B[i]);
                }
            }
        }
    }

    int ans = -1;
    for(int j = 0; j <= N; j++) {
        for(int k = 0; k <= X; k++) {
            if(dp[N][j][k] <= Y) ans = max(ans, j);
        }
    }

    cout << min(ans+1, N) << endl;
}
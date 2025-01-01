#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Strange Lunchbox
//    https://atcoder.jp/contests/abc219/tasks/abc219_d



int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    int INF = INT_MAX / 2;
    vector dp(N + 1, vector(X + 1, vector<int>(Y + 1, INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        for(int j = 0; j <= X; j++) {
            for(int k = 0; k <= Y; k++) {
                if(dp[i][j][k] == INF) continue;
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][min(X, j+A)][min(Y, k+B)] = min(dp[i+1][min(X, j+A)][min(Y, k+B)], dp[i][j][k] + 1);
            }
        }
    }

    cout << (dp[N][X][Y] != INF ? dp[N][X][Y] : -1) << endl;
}
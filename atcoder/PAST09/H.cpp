#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    H - 最長非共通部分列
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_h



int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(S[i] != T[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    cout << dp[N][M] << endl;
}
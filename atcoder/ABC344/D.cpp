#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - String Bags
//    https://atcoder.jp/contests/abc344/tasks/abc344_d



int main() {
    string T;
    int N;
    cin >> T >> N;

    vector<int> A(N);
    vector<vector<string>> S(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        S[i].resize(A[i]);
        for(int j = 0; j < A[i]; j++) {
            cin >> S[i][j];
        }
    }

    int M = T.size(), INF = INT_MAX / 2;
    vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M+1; j++) {
            if(dp[i][j] == INF) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            for(int k = 0; k < A[i]; k++) {
                int len = S[i][k].size();
                if(j + len > M) continue;
                if(S[i][k] == T.substr(j, len)) {
                    dp[i+1][j+len] = min(dp[i+1][j+len], dp[i][j] + 1);
                }
            }
        }
    }

    cout << (dp[N][M] != INF ? dp[N][M] : -1) << endl;
}
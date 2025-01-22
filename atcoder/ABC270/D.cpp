#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Stones
//    https://atcoder.jp/contests/abc270/tasks/abc270_d



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(K);
    for(int i = 0; i < K; i++) cin >> A[i];

    vector<vector<int>> dp(2, vector<int>(N+1));
    for(int j = 1; j <= N; j++) {
        int now = 0;
        for(int i = 0; i < K; i++) {
            if(A[i] <= j) now = max(now, dp[1][j - A[i]] + A[i]);
        }
        dp[0][j] = now;
        now = INT_MAX;
        for(int i = 0; i < K; i++) {
            if(A[i] <= j) now = min(now, dp[0][j - A[i]]);
        }
        dp[1][j] = now;
    }

    cout << dp[0][N] << endl;
}
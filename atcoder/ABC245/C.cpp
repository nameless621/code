#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Choose Elements
//    https://atcoder.jp/contests/abc245/tasks/abc245_c



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    vector<vector<bool>> dp(N, vector<bool>(2));
    dp[0][0] = dp[0][1] = true;
    for(int i = 1; i < N; i++) {
        if(abs(A[i] - A[i-1]) <= K && !dp[i][0]) dp[i][0] = dp[i-1][0];
        if(abs(A[i] - B[i-1]) <= K && !dp[i][0]) dp[i][0] = dp[i-1][1];
        if(abs(B[i] - A[i-1]) <= K && !dp[i][1]) dp[i][1] = dp[i-1][0];
        if(abs(B[i] - B[i-1]) <= K && !dp[i][1]) dp[i][1] = dp[i-1][1];
    }

    if(dp[N-1][0] || dp[N-1][1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
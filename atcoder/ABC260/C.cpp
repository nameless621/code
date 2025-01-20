#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Changing Jewels
//    https://atcoder.jp/contests/abc254/tasks/abc260_c



int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector dp(N, vector<long long>(2));
    dp[0][0] = 1;
    for(int i = 0; i < N-1; i++) {
        dp[i+1][0] += dp[i][0];
        dp[i][1] += dp[i][0] * X;
        dp[i+1][0] += dp[i][1];
        dp[i+1][1] += dp[i][1] * Y;
    }

    cout << dp[N-1][1] << endl;
}
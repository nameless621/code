#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Shift vs. CapsLock
//    https://atcoder.jp/contests/abc303/tasks/abc303_d



int main() {
    int X, Y, Z;
    string S;
    cin >> X >> Y >> Z >> S;

    int N = S.size();
    long long INF = LLONG_MAX / 2;
    vector dp(N+1, vector(2, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        dp[i][0] = min(dp[i][0], dp[i][1] + Z);
        dp[i][1] = min(dp[i][1], dp[i][0] + Z);
        if(S[i] == 'a') {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + X);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + Y);
        }
        else {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + Y);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + X);
        }
    }

    cout << min(dp[N][0], dp[N][1]) << endl;
}
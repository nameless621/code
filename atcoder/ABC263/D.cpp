#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Left Right Operation
//    https://atcoder.jp/contests/abc263/tasks/abc263_d



int main() {
    int N;
    long long L, R;
    cin >> N >> L >> R;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long INF = LLONG_MAX / 2;
    vector<vector<long long>> dp(N+1, vector<long long>(3, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        dp[i+1][0] = dp[i][0] + L;
        dp[i+1][1] = min(dp[i][0] + A[i], dp[i][1] + A[i]);
        dp[i+1][2] = min({dp[i][0] + R, dp[i][1] + R, dp[i][2] + R});
    }

    cout << min({dp[N][0], dp[N][1], dp[N][2]}) << endl;
}
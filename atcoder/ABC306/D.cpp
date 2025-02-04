#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Poisonous Full-Course
//    https://atcoder.jp/contests/abc306/tasks/abc306_d



int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    long long INF = -1e18;
    vector<vector<long long>> dp(N+1, vector<long long>(2, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);

        if(X[i]) {
            dp[i+1][1] = max(dp[i+1][1], dp[i+1][0] + Y[i]);
        }
        else {
            dp[i+1][0] = max(dp[i+1][0], dp[i][0] + Y[i]);
            dp[i+1][0] = max(dp[i+1][0], dp[i][1] + Y[i]);
        }
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
}
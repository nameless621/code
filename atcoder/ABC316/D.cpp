#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - President
//    https://atcoder.jp/contests/abc317/tasks/abc317_d



int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N), Z(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    int sum = accumulate(Z.begin(), Z.end(), 0);
    sum = (sum + 1) / 2;
    
    long long INF = 1e18;
    vector<vector<long long>> dp(N+1, vector<long long>(sum+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= sum; j++) {
            if(dp[i][j] == INF) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            int need = max(0, (X[i] + Y[i] + 1) / 2 - X[i]);
            int nex = min(sum, j + Z[i]);
            dp[i+1][nex] = min(dp[i+1][nex], dp[i][j] + need);
        }
    }

    cout << dp[N][sum] << endl;
}
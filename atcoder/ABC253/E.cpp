#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Distance Sequence
//    https://atcoder.jp/contests/abc253/tasks/abc253_e



using mint = modint998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    if(K == 0) {
        cout << mint(M).pow(N).val() << endl;
        return 0;
    }

    vector<vector<mint>> dp(N, vector<mint>(M));
    for(int j = 0; j < M; j++) dp[0][j] = 1;

    for(int i = 0; i < N - 1; i++) {
        vector<mint> sum(M + 1);
        for(int j = 0; j < M; j++) {
            sum[j+1] = sum[j] + dp[i][j];
        }
        for(int j = 0; j < M; j++) {
            if(j - K >= 0) dp[i+1][j] += sum[j - K + 1];
            if(j + K <= M) dp[i+1][j] += sum[M] - sum[j + K];
        }
    }

    mint ans = 0;
    for(int j = 0; j < M; j++) {
        ans += dp[N-1][j];
    }

    cout << ans.val() << endl;
}
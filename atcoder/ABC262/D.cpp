#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - I Hate Non-integer Number
//    https://atcoder.jp/contests/abc254/tasks/abc262_d



int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    mint ans = 0;
    for(int K = 1; K <= N; K++) {
        vector dp(N+1, vector(K+1, vector<mint>(K)));
        dp[0][0][0] = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= K; j++) {
                for(int l = 0; l < K; l++) {
                    dp[i+1][j][l] += dp[i][j][l];
                    int nex = (l + a[i]) % K;
                    if(j + 1 <= K) dp[i+1][j+1][nex] += dp[i][j][l];
                }
            }
        }
        ans += dp[N][K][0];
    }

    cout << ans.val() << endl;
}
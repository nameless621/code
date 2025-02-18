#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Playlist
//    https://atcoder.jp/contests/abc323/tasks/abc323_e



int main() {
    int N, X;
    cin >> N >> X;
    
    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];

    mint P = mint(1) / N;
    vector<mint> dp(X + 1);
    dp[0] = 1;
    mint ans = 0;
    for(int i = 0; i < X + 1; i++) {
        for(int j = 0; j < N; j++) {
            if(T[j] <= i) dp[i] += dp[i - T[j]] * P;
        }
        if(i + T[0] > X) ans += dp[i] * P;
    }

    cout << ans.val() << endl;
}
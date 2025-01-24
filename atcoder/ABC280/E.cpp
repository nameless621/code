#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Critical Hit
//    https://atcoder.jp/contests/abc280/tasks/abc280_e



using mint = modint998244353;

int main() {
    int N, P;
    cin >> N >> P;

    mint p = mint(P) / 100;
    mint q = mint(1) - p;
    vector<mint> dp(N + 1);
    for(int i = 1; i <= N; i++) {
        dp[i] = 1 + dp[max(i - 2, 0)] * p + dp[i - 1] * q;
    }

    cout << dp[N].val() << endl;
}
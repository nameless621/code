#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - #(subset sum = K) with Add and Erase
//    https://atcoder.jp/contests/abc321/tasks/abc321_f



int main() {
    int Q, K;
    cin >> Q >> K;

    vector<mint> dp(K);
    dp[0] = 1;
    while(Q--) {
        char t;
        int x;
        cin >> t >> x;
        vector<mint> p(K);
        swap(dp, p);
        if(t == '+') {
            for(int i = 0; i < K; i++) {
                dp[(i + x) % K] += p[i];
            }
        }
        else {
            for(int i = 0; i < K; i++) {
                dp[i] -= p[(i - x + K) % K];
            }
        }
        cout << dp[0].val() << endl;
    }
}
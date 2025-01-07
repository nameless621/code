#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - 1111gal password
//    https://atcoder.jp/contests/abc242/tasks/abc242_c



using mint = modint998244353;

int main() {
    int N;
    cin >> N;
    
    vector<mint> dp(9, 1);
    for(int i = 0; i < N - 1; i++) {
        vector<mint> p(9, 0);
        swap(dp, p);
        for(int j = 0; j < 9; j++) {
            dp[j] += p[j];
            if(j - 1 >= 0) dp[j - 1] += p[j];
            if(j + 1 < 9) dp[j + 1] += p[j];
        }
    }

    mint ans = 0;
    for(int i = 0; i < 9; i++) {
        ans += dp[i];
    }

    cout << ans.val() << endl;
}
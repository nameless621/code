#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Distinct Adjacent
//    https://atcoder.jp/contests/abc307/tasks/abc307_e



int main(){
    int N, M;
    cin >> N >> M;

    mint dp0 = 1, dp1 = 0;
    for(int i = 1; i < N; i++) {
        mint p0 = dp1;
        mint p1 = (dp0 * (M - 1) + dp1 * (M - 2));
        dp0 = p0;
        dp1 = p1;
    }

    mint ans = dp1 * M;
    cout << ans.val() << endl;
}
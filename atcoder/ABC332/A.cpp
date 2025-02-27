#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Online Shopping
//    https://atcoder.jp/contests/abc332/tasks/abc332_a



int main() {
    int N, S, K;
    cin >> N >> S >> K;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int P, Q;
        cin >> P >> Q;
        ans +=  P * Q;
    }

    if(ans < S) ans += K;
    cout << ans << endl;
}
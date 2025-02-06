#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Order Something Else
//    https://atcoder.jp/contests/abc310/tasks/abc310_a



int main() {
    int N, P, Q;
    cin >> N >> P >> Q;

    int ans = P;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        ans = min(ans, Q + A);
    }

    cout << ans << endl;
}
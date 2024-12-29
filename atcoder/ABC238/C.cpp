#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - digitnum
//    https://atcoder.jp/contests/abc238/tasks/abc238_c



int main() {
    long long N;
    cin >> N;

    long long L = 1;
    mint ans = 0;
    while(L <= N) {
        long long R = L * 10;
        long long X = min(N + 1, R) - L;
        ans += mint(X + 1) * X / 2;
        L *= 10;
    }

    cout << ans.val() << endl;
}
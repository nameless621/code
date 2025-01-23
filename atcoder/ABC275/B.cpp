#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - ABC-DEF
//    https://atcoder.jp/contests/abc275/tasks/abc275_b



int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    mint A = a, B = b, C = c, D = d, E = e, F = f;
    mint ans = A * B * C - D * E * F;
    cout << ans.val() << endl;
}
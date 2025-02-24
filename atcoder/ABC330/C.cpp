#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Minimize Abs 1
//    https://atcoder.jp/contests/abc330/tasks/abc330_c



int main() {
    long long D;
    cin >> D;

    long long y = 1e6;
    long long ans = D;
    for(long long x = 0; x*x <= D; x++) {
        while(x*x + y*y > D) y--;
        ans = min(ans, abs(x*x + y*y - D));
    }

    cout << ans << endl;
}
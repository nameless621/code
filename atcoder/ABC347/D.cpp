#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Popcount and XOR
//    https://atcoder.jp/contests/abc347/tasks/abc347_d



int main() {
    int a, b;
    long long C;
    cin >> a >> b >> C;

    int c = __popcount(C);
    if(a + b < c || (c - a - b) & 1) {
        cout << -1 << endl;
        return 0;
    }

    long long X = 0, Y = 0;
    for(int k = 0; k < 60; k++) {
        if(~C >> k & 1) continue;
        if(a > b && a > 0) {
            X |= 1ll << k;
            a--;
        } 
        else if(b > 0) {
            Y |= 1ll << k;
            b--;
        }
    }

    for(int k = 0; k < 60; k++) {
        if(C >> k & 1) continue;
        if(a > 0 && b > 0) {
            X |= 1ll << k;
            Y |= 1ll << k;
            a--;
            b--;
        }
    }

    if(a == 0 && b == 0) cout << X << " " << Y << endl;
    else cout << -1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Integer Division Returns
//    https://atcoder.jp/contests/abc345/tasks/abc345_b



int main() {
    long long X;
    cin >> X;

    if(X >= 0) {
        cout << (X + 10 - 1) / 10 << endl;
    }
    else {
        X = -X;
        X /= 10;
        cout << -X << endl;
    }
}
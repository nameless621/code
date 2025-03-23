#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - AtCoder Line
//    https://atcoder.jp/contests/abc352/tasks/abc352_a



int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    if(X > Y) swap(X, Y);
    bool ok = false;
    if(X <= Z && Z <= Y) ok = true;
    cout << (ok ? "Yes" : "No") << endl;
}
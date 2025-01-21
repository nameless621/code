#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Growth Record
//    https://atcoder.jp/contests/abc259/tasks/abc259_a



int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    if(X <= M) cout << T << endl;
    else cout << T - X * D + M * D << endl;
}

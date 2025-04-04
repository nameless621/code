#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Election 2
//    https://atcoder.jp/contests/abc366/tasks/abc366_a



int main() {
    int N, T, A;
    cin >> N >> T >> A;

    int rem = N - T - A;

    if(T > A + rem || A > T + rem) cout << "Yes" << endl;
    else cout << "No" << endl;
}
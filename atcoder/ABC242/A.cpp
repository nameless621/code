#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - T-shirt
//    https://atcoder.jp/contests/abc242/tasks/abc242_a



int main() {
    double A, B, C, X;
    cin >> A >> B >> C >> X;
    if(X <= A) cout << 1 << endl;
    else if(X <= B) cout << fixed << setprecision(12) << (C / (B - A)) << endl;
    else cout << 0 << endl;
}
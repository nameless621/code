#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - 2UP3DOWN
//    https://atcoder.jp/contests/abc326/tasks/abc326_a



int main() {
    int X, Y;
    cin >> X >> Y;

    cout << (X-3 <= Y && Y <= X+2 ? "Yes" : "No") << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Pentagon
//    https://atcoder.jp/contests/abc333/tasks/abc333_b



int main() {
    string S, T;
    cin >> S >> T;

    int x = min(5 - abs(S[0] - S[1]), abs(S[0] - S[1]));
    int y = min(5 - abs(T[0] - T[1]), abs(T[0] - T[1]));

    cout << (x == y ? "Yes" : "No") << endl;
}
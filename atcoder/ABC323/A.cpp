#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Weak Beats
//    https://atcoder.jp/contests/abc323/tasks/abc323_a



int main() {
    string S;
    cin >> S;

    bool ok = true;
    for(int i = 0; i < (int)S.size(); i++) {
        if(i & 1 && S[i] == '1') ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
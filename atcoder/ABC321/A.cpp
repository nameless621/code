#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - 321-like Checker
//    https://atcoder.jp/contests/abc321/tasks/abc321_a



int main() {
    string S;
    cin >> S;

    bool ok = true;
    for(int i = 0; i < (int)S.size() - 1; i++) {
        if(S[i] <= S[i+1]) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
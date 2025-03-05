#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Capitalized? 
//    https://atcoder.jp/contests/abc338/tasks/abc338_a



int main() {
    string S;
    cin >> S;

    bool ok = true;
    if(islower(S[0])) ok = false;
    for(int i = 1; i < (int)S.size(); i++) {
        if(isupper(S[i])) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
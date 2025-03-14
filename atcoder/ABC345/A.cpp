#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Leftrightarrow
//    https://atcoder.jp/contests/abc345/tasks/abc345_a



int main() {
    string S;
    cin >> S;
    
    bool ok = true;
    if(S[0] != '<' || S.back() != '>') ok = false;
    for(int i = 1; i < (int)S.size()-1; i++) {
        if(S[i] != '=') ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
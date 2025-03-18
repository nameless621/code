#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Airport Code
//    https://atcoder.jp/contests/abc349/tasks/abc349_c



int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size(), j = 0;
    for(int i = 0; i < N; i++) {
        if(toupper(S[i]) == T[j]) j++;
        if(j == 3) break;
    }

    bool ok = false;
    if(j == 3) ok = true;
    if(T[2] == 'X' && j >= 2) ok = true;
    cout << (ok ? "Yes" : "No") << endl;
}
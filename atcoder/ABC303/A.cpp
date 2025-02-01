#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Similar String
//    https://atcoder.jp/contests/abc303/tasks/abc303_a



int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    bool ok = true;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            if(S[i] == '1' && T[i] == 'l') continue;
            if(S[i] == 'l' && T[i] == '1') continue;
            if(S[i] == '0' && T[i] == 'o') continue;
            if(S[i] == 'o' && T[i] == '0') continue;
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
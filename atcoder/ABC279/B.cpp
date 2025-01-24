#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - LOOKUP
//    https://atcoder.jp/contests/abc279/tasks/abc279_b



int main() {
    string S, T;
    cin >> S >> T;

    bool ok = false;
    int N = S.size(), M = T.size();
    for(int i = 0; i < N - M + 1; i++) {
        if(T == S.substr(i, M)) ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
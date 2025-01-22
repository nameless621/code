#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Prefix?
//    https://atcoder.jp/contests/abc268/tasks/abc268_b



int main() {
    string S, T;
    cin >> S >> T;
    if(S.size() > T.size()) {
        cout << "No" << endl;
        return 0;
    } 

    bool ok = false;
    if(S == T.substr(0, S.size())) ok = true;
    cout << (ok ? "Yes" : "No") << endl;
}
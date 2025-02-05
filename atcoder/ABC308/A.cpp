#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - New Scheme
//    https://atcoder.jp/contests/abc308/tasks/abc308_a



int main() {
    vector<int> S(8);
    for(int i = 0; i < 8; i++) cin >> S[i];

    bool ok = true;
    for(int i = 0; i < 8; i++) {
        if(S[i] % 25) ok = false;
        if(S[i] < 100 || 675 < S[i]) ok = false;
    }

    auto T = S;
    sort(T.begin(), T.end());
    if(S != T) ok = false;

    cout << (ok ? "Yes" : "No") << endl;
}
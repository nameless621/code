#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Glutton Takahashi
//    https://atcoder.jp/contests/abc364/tasks/abc364_a



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(auto& s : S) cin >> s;

    bool ok = true;
    for(int i = 0; i < N-2; i++) {
        if(S[i] == "sweet" && S[i] == S[i+1]) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
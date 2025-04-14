#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Word Ladder
//    https://atcoder.jp/contests/abc370/tasks/abc370_c



int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size();
    vector<string> X;
    for(int i = 0; i < N; i++) {
        if(S[i] > T[i]) {
            S[i] = T[i];
            X.push_back(S);
        }
    }

    for(int i = N-1; i >= 0; i--) {
        if(S[i] != T[i]) {
            S[i] = T[i];
            X.push_back(S);
        }
    }

    cout << X.size() << endl;
    for(string x : X) {
        cout << x << endl;
    }
}
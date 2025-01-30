#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Alternately
//    https://atcoder.jp/contests/abc296/tasks/abc296_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    bool ok = true;
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == S[i + 1]) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
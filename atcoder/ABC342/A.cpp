#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Yay!
//    https://atcoder.jp/contests/abc342/tasks/abc342_a



int main() {
    string S;
    cin >> S;

    int N = S.size();
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(S[i] == S[j]) cnt++;
        }
        if(cnt == 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Overall Winner
//    https://atcoder.jp/contests/abc301/tasks/abc301_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    int A = 0, T = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'A') A++;
        else T++;
    }

    if(A < T) cout << 'T' << endl;
    if(A > T) cout << 'A' << endl;
    if(A == T) cout << (S.back() == 'T' ? 'A' : 'T') << endl;
}
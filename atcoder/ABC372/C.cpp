#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Count ABC Again
//    https://atcoder.jp/contests/abc372/tasks/abc372_c



int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    int cnt = 0;
    for(int i = 0; i < N-2; i++) {
        if(S.substr(i, 3) == "ABC") cnt++;
    }

    while(Q--) {
        int X;
        char C;
        cin >> X >> C;
        X--;

        for(int i = max(0, X-2); i < min(N-2, X+1); i++) {
            if(S.substr(i, 3) == "ABC") cnt--;
        }
        S[X] = C;
        for(int i = max(0, X-2); i < min(N-2, X+1); i++) {
            if(S.substr(i, 3) == "ABC") cnt++;
        }

        cout << cnt << '\n';
    }
}
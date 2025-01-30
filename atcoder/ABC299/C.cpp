#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Dango
//    https://atcoder.jp/contests/abc299/tasks/abc299_c



int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0, R = 0;
    for(int L = 0; L < N; L++) {
        R = max(L, R);
        if(S[L] != '-') continue;
        while(R + 1 < N && S[R + 1] == 'o') R++;
        ans = max(ans, R - L);
    }

    int L = N - 1;
    for(R = N - 1; R >= 0; R--) {
        L = min(L, R);
        if(S[R] != '-') continue;
        while(L - 1 >= 0 && S[L - 1] == 'o') L--;
        ans = max(ans, R - L);
    }

    if(ans == 0) ans = -1;
    cout << ans << endl;
}
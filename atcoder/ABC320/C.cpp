#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Slot Strategy 2 (Easy)
//    https://atcoder.jp/contests/abc320/tasks/abc320_c



int main() {
    int M;
    string S[3];
    cin >> M >> S[0] >> S[1] >> S[2];

    int ans = 10101;
    for(int i = 0; i < 301; i++) {
        for(int j = 0; j < 301; j++) {
            if(i == j) continue;
            if(S[0][i % M] != S[1][j % M]) continue;
            for(int k = 0; k < 301; k++) {
                if(i == k || j == k) continue;
                if(S[0][i % M] != S[2][k % M]) continue;
                ans = min(ans, max({i, j, k}));
            }
        }
    }

    if(ans == 10101) ans = -1;
    cout << ans << endl;
}
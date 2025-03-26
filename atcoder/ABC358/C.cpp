#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Popcorn
//    https://atcoder.jp/contests/abc358/tasks/abc358_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for(string& s : S) cin >> s;

    int ans = N;
    for(int bit = 0; bit < (1 << N); bit++) {
        int res = 0;
        for(int i = 0; i < N; i++) {
            if(~bit >> i & 1) continue;
            for(int j = 0; j < M; j++) {
                if(S[i][j] == 'o') {
                    res |= 1 << j;
                }
            }
        }

        if(res == (1 << M)-1) ans = min(ans, __popcount(bit));
    }

    cout << ans << endl;
}
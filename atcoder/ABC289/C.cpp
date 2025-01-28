#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Coverage
//    https://atcoder.jp/contests/abc289/tasks/abc289_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> S(M);
    for(int i = 0; i < M; i++) {
        int C;
        cin >> C;
        for(int j = 0; j < C; j++) {
            int a;
            cin >> a, a--;
            S[i] |= 1 << a;
        }
    }

    int ans = 0;
    for(int bit = 1; bit < (1 << M); bit++) {
        int res = 0;
        for(int i = 0; i < M; i++) {
            if(~bit >> i & 1) continue;
            res |= S[i];
        }
        if((1 << N) == res + 1) ans++;
    }

    cout << ans << endl;
}
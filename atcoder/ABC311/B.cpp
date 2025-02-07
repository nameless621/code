#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Vacation Together
//    https://atcoder.jp/contests/abc311/tasks/abc311_b



int main() {
    int N, D;
    cin >> N >> D;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = 0, cnt = 0;
    for(int j = 0; j < D; j++) {
        bool flag = false;
        for(int i = 0; i < N; i++) {
            if(S[i][j] == 'x') flag = true;
        }
        if(flag) cnt = 0;
        else cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
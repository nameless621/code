#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Dentist Aoki
//    https://atcoder.jp/contests/abc350/tasks/abc350_b



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<bool> ok(N, true);
    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        T--;
        ok[T] = !ok[T];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(ok[i]) ans++;
    }

    cout << ans << endl;
}
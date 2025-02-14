#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Full Moon
//    https://atcoder.jp/contests/abc318/tasks/abc318_a



int main() {
    int N, M, P;
    cin >> N >> M >> P;

    int ans = 0;
    for(int i = M; i <= N; i += P) {
        ans++;
    }

    cout << ans << endl;
}
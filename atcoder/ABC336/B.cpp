#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - CTZ
//    https://atcoder.jp/contests/abc336/tasks/abc336_b



int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 0; i < 60; i++) {
        if(N >> i & 1) break;
        ans++;
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Not Too Hard
//    https://atcoder.jp/contests/abc328/tasks/abc328_a



int main() {
    int N, X;
    cin >> N >> X;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int S;
        cin >> S;
        if(S <= X) ans += S;
    }

    cout << ans << endl;
}
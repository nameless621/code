#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Counting Passes
//    https://atcoder.jp/contests/abc330/tasks/abc330_a



int main() {
    int N, L;
    cin >> N >> L;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if(A >= L) ans++;
    }

    cout << ans << endl;
}
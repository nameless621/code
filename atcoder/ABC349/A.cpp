#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Zero Sum Game
//    https://atcoder.jp/contests/abc349/tasks/abc349_a



int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 0; i < N-1; i++) {
        int A;
        cin >> A;
        ans -= A;
    }

    cout << ans << endl;
}
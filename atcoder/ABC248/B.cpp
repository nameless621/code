#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Slimes
//    https://atcoder.jp/contests/abc248/tasks/abc248_b



int main() {
    long long A, B, K;
    cin >> A >> B >> K;

    int ans = 0;
    while(A < B) {
        A *= K;
        ans++;
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Water Station
//    https://atcoder.jp/contests/abc305/tasks/abc305_a



int main() {
    int N;
    cin >> N;

    int ans = 0, d = 1e9;
    for(int i = 0; i <= 100; i += 5) {
        if(abs(i - N) < d) {
            ans = i;
            d = abs(i - N);
        }
    }

    cout << ans << endl;
}
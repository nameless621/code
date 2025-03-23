#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Exponential Plant
//    https://atcoder.jp/contests/abc354/tasks/abc354_a



int main() {
    int H;
    cin >> H;

    int cnt = 0;
    long long now = 0;
    while(1) {
        now += 1ll << cnt;
        cnt++;
        if(H < now) break;
    }

    cout << cnt << endl;
}
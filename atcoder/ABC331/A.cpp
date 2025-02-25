#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Tomorrow
//    https://atcoder.jp/contests/abc331/tasks/abc331_a



int main() {
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;

    d++;
    if(d > D) {
        d = 1;
        m++;
        if(m > M) {
            m = 1;
            y++;
        }
    }

    cout << y << " " << m << " " << d << endl;
}
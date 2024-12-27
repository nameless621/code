#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Arithmetic Number
//    https://atcoder.jp/contests/abc234/tasks/abc234_e



void f(set<long long>& S, long long now, int d) {
    if(now > 2e17) return;
    S.insert(now);
    int x = now % 10;
    if(0 <= x + d && x + d < 10) {
        now = now * 10 + (x + d);
        f(S, now, d);
    }
}

int main() {
    set<long long> S;
    for(int i = 1; i <= 9; i++) {
        for(int j = -9; j <= 9; j++) {
            f(S, i, j);
        }
    }

    long long X;
    cin >> X;
    cout << *S.lower_bound(X) << endl;
}
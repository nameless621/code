#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Shout Everyday 
//    https://atcoder.jp/contests/abc367/tasks/abc367_a



int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int now = B;
    bool ok = true;
    while(now != C) {
        if(now == A) ok = false;
        now = (now + 1) % 24;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
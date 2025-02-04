#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Base 2
//    https://atcoder.jp/contests/abc306/tasks/abc306_b



int main() {
    unsigned long long res = 0;
    
    for(int i = 0; i < 64; i++) {
        int A;
        cin >> A;
        if(A) res |= 1ull << i;
    }

    cout << res << endl;
}
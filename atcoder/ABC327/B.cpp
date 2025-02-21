#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - A^A
//    https://atcoder.jp/contests/abc327/tasks/abc327_b



long long power(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

int main() {
    long long B;
    cin >> B;

    for(int i = 1; ; i++) {
        long long res = power(i, i);
        if(res == B) {
            cout << i << endl;
            return 0;
        }
        if(res > B) break;
    }

    cout << -1 << endl;
}
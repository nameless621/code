#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Christmas Trees 
//    https://atcoder.jp/contests/abc334/tasks/abc334_b



long long f(long long x, long long m) {
    long long d = x / m;
    if(x < 0 && x % m != 0) d--;
    return d;
}

int main() {
    long long A, M, L, R;
    cin >> A >> M >> L >> R;

    L -= A;
    R -= A;
    cout << f(R, M) - f(L-1, M) << endl;    
}
#include <bits/stdc++.h>
using namespace std;


//    E - Integer Sequence Fair
//    https://atcoder.jp/contests/abc228/tasks/abc228_e



long long modpow(long long x, long long n, long long mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ((ret%mod)*(x%mod))%mod;
        x = ((x%mod)*(x%mod))%mod;
        n >>= 1;
    }
    return ret;
}


int main() {
    long long mod = 998244353;
    long long N, K, M;
    cin >> N >> K >> M;

    long long temp = modpow(K, N, mod - 1);
    long long ans = modpow(M, temp, mod);

    if(M % mod == 0) cout << 0 << endl;
    else cout << ans << endl;
}
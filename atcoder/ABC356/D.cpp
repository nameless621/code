#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Masked Popcount
//    https://atcoder.jp/contests/abc356/tasks/abc356_d



long long bitcnt(long long n, long long k) {
    long long period = 1ll << (k + 1);
    long long full_cycles = (n + 1) / period;
    long long remainder = (n + 1) % period;

    long long count = full_cycles * (1ll << k) + max(0ll, remainder - (1ll << k));
    return count;
}

int main() {
    long long N, M;
    cin >> N >> M;

    mint ans = 0;
    for(int i = 0; i < 60; i++) {
        if(M >> i & 1) ans += bitcnt(N, i);
    }

    cout << ans.val() << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Rearrange Query
//    https://atcoder.jp/contests/abc367/tasks/abc367_f



struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    uint64_t operator() (uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} rng;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<uint64_t> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    
    auto f = [&](auto& x, auto& cnt) {
        for(int i = 0; i < N; i++) {
            cnt[i+1] = cnt[i] + rng(x[i]);
        }
    };

    vector<uint64_t> cntA(N+1), cntB(N+1);
    f(A, cntA);
    f(B, cntB);

    while(Q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        l--; L--;

        bool ok = false;
        if((cntA[r] - cntA[l] == cntB[R] - cntB[L])) ok = true;

        cout << (ok ? "Yes" : "No") << '\n';
    }
}
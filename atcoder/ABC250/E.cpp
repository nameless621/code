#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Prefix Equality
//    https://atcoder.jp/contests/abc250/tasks/abc250_e



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
    int N;
    cin >> N;

    auto hash = [&]() -> vector<uint64_t> {
        vector<uint64_t> res(N+1);
        set<long long> s;
        for(int i = 0; i < N; i++) {
            long long x; cin >> x;
            if(s.count(x)) {
                res[i+1] = res[i];
                continue;
            }
            s.insert(x);
            res[i+1] = res[i] ^ rng(x);
        }
        return res;
    };

    auto A = hash();
    auto B = hash();

    int Q;
    cin >> Q;
    while(Q--) {
        int x, y;
        cin >> x >> y;
        cout << (A[x] == B[y] ? "Yes" : "No") << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Divide Interval
//    https://atcoder.jp/contests/abc349/tasks/abc349_d



int main() {
    long long L, R;
    cin >> L >> R;

    vector<pair<long long, long long>> res;
    while(L < R) {
        for(int i = 60; i >= 0; i--) {
            long long p = 1ll << i;
            if(L % p) continue;
            long long j = L / p;
            if(p * (j+1) > R) continue;
            res.emplace_back(L, p * (j+1));
            L = p * (j+1);
            break;
        }
    }

    cout << res.size() << endl;
    for(auto[x, y] : res) {
        cout << x << " " << y << endl;
    }
}
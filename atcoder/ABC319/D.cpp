#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Minimum Width
//    https://atcoder.jp/contests/abc319/tasks/abc319_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> L(N);
    for(int i = 0; i < N; i++) cin >> L[i];

    auto check = [&](long long W) {
        int cnt = 1;
        long long len = 0;
        for(int i = 0; i < N; i++) {
            if(L[i] > W) return false;
            len += L[i];
            if(len > W) {
                cnt++;
                len = L[i];
            }
            len++;
            if(len >= W && i < N - 1) {
                cnt++;
                len = 0;
            }
        }
        return cnt <= M;
    };

    long long ng = 0, ok = 1e18;
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}
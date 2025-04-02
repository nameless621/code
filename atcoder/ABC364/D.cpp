#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - K-th Nearest
//    https://atcoder.jp/contests/abc364/tasks/abc364_d



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int& a : A) cin >> a;
    sort(A.begin(), A.end());

    auto f = [&](int b, int k) {
        int ng = -1, ok = 1e9;
        while(abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            int L = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            int R = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            if(R - L >= k) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    while(Q--) {
        int b, k;
        cin >> b >> k;
        int ret = f(b, k);
        cout << ret << "\n";
    }
}
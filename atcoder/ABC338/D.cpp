#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Island Tour
//    https://atcoder.jp/contests/abc338/tasks/abc338_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> X(M);
    for(int i = 0; i < M; i++) {
        cin >> X[i];
        X[i]--;
    }

    vector<long long> d(N);
    auto f = [&](int l, int r, int x) {
        d[l] += x;
        d[r] -= x;
    };

    for(int i = 0; i < M-1; i++) {
        int l = X[i], r = X[i+1];
        if(l > r) swap(l, r);
        int a = r - l;
        int b = N - a;
        f(0, l, a);
        f(l, r, b);
        f(r, N, a);
    }

    for(int i = 0; i < N-1; i++) {
        d[i+1] += d[i];
    }

    long long ans = *min_element(d.begin(), d.end());
    cout << ans << endl;
}
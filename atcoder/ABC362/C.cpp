#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Sum = 0
//    https://atcoder.jp/contests/abc362/tasks/abc362_c



int main() {
    int N;
    cin >> N;

    vector<long long> L(N), R(N);
    long long x = 0, y = 0;
    for(int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        x += L[i];
        y += R[i];
    }

    if(0 < x || y < 0) {
        cout << "No" << endl;
        return 0;
    }

    vector<long long> ans(N);
    for(int i = 0; i < N; i++) {
        ans[i] = R[i];
    }

    for(int i = 0; i < N; i++) {
        if(y == 0) break;
        long long d = min(y, R[i] - L[i]);
        ans[i] -= d;
        y -= d;
    }

    cout << "Yes" << endl;
    for(int i = 0; i < N; i++) {
        cout << ans[i] << (i < N-1 ? " " : "\n");
    }
}
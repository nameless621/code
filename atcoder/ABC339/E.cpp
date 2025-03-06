#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Smooth Subsequence
//    https://atcoder.jp/contests/abc339/tasks/abc339_e



int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int M = 5e5 + 9;
    segtree<int, op, e> seg(M);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int l = max(0, A[i] - D);
        int r = min(M, A[i] + D + 1);
        int res = seg.prod(l, r) + 1;
        ans = max(ans, res);
        seg.set(A[i], res);
    }

    cout << ans << endl;
}
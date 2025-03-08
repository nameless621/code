#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Mancala 2
//    https://atcoder.jp/contests/abc340/tasks/abc340_e



using S = long long;
using F = long long;
const S INF = 8e18;
S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    vector<int> B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
    for(int i = 0; i < M; i++) {
        long long x = seg.get(B[i]);
        seg.set(B[i], 0);
        seg.apply(0, N, x / N);
        x %= N;
        if(B[i] + 1 < N) {
            int l = B[i] + 1;
            int r = min(N, int(B[i] + x + 1));
            seg.apply(l, r, 1);
            x -= r - l;
            if(x > 0) seg.apply(0, x, 1);
        }
        else {
            seg.apply(0, x, 1);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << seg.get(i) << (i != N-1 ? " " : "\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    I - /2 and *3
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_i



using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<S> V(2 * N);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(V);
    while(Q--) {
        int t, k;
        cin >> t >> k;
        if(t == 1) {
            int res = seg.get(k - 1);
            if(res % 2 == 0) cout << k << endl;
            else cout << 2 * N - k + 1 << endl;
        }
        else {
            seg.apply(N - k, N + k, 1);
        }
    }
}
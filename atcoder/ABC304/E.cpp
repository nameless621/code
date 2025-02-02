#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Good Graph
//    https://atcoder.jp/contests/abc304/tasks/abc304_e



int main() {
    int N, M;
    cin >> N >> M;

    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.merge(a, b);
    }

    int K;
    cin >> K;
    set<pair<int, int>> S;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        x = uf.leader(x);
        y = uf.leader(y);
        S.emplace(x, y);
        S.emplace(y, x);
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        p = uf.leader(p);
        q = uf.leader(q);
        cout << (!S.count({p, q}) ? "Yes" : "No") << endl;
    }
}
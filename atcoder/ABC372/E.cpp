#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - K-th Largest Connected Components
//    https://atcoder.jp/contests/abc372/tasks/abc372_e



int main() {
    int N, Q;
    cin >> N >> Q;

    dsu uf(N);
    vector<vector<int>> node(N);
    for(int i = 0; i < N; i++) {
        node[i].push_back(i);
    }

    while(Q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(uf.same(u, v)) continue;
            int ul = uf.leader(u), vl = uf.leader(v);
            uf.merge(u, v);
            int l1 = uf.leader(u);
            int l2 = (l1 == ul ? vl : ul);
            if(node[l1].size() < node[l2].size()) swap(l1, l2);
            node[l1].insert(node[l1].end(), node[l2].begin(), node[l2].end());
            sort(node[l1].rbegin(), node[l1].rend());
            while((int)node[l1].size() > 10) node[l1].pop_back();
        }
        else {
            int v, k;
            cin >> v >> k;
            v--;
            v = uf.leader(v);
            int ans = -1;
            if((int)node[v].size() >= k) ans = node[v][k-1] + 1;
            cout << ans << '\n';
        }
    }
}
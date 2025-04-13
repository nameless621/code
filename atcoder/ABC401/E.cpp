#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Reachable Set
//    https://atcoder.jp/contests/abc401/tasks/abc401_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    dsu d(N);
    set<int> s;
    for(int i = 0; i < N; i++) {
        s.erase(i);
        for(int j : G[i]) {
            if(j < i) {
                d.merge(i, j);
                s.erase(j);
            }
            else s.insert(j);
        }
        if(d.size(0) == i+1) cout << s.size() << endl;
        else cout << -1 << endl;
    }
}
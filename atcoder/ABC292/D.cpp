#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Unicyclic Components
//    https://atcoder.jp/contests/abc292/tasks/abc292_d



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

    vector<bool> ok(N);
    int node = 0, edge = 0;
    auto dfs = [&](auto dfs, int p) -> void {
        ok[p] = true;
        node++;
        for(int c : G[p]) {
            edge++;
            if(ok[c]) continue;
            dfs(dfs, c);
        }
    };

    bool res = true;
    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        node = 0;
        edge = 0;
        dfs(dfs, i);
        edge /= 2;
        if(node != edge) res = false;
    }

    cout << (res ? "Yes" : "No") << endl;
}
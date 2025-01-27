#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Count Simple Paths
//    https://atcoder.jp/contests/abc284/tasks/abc284_e



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

    int ans = 0;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int u) -> void {
        ok[u] = true;
        if(ans == 1e6) return;
        ans++;
        for(int v : G[u]) {
            if(ok[v]) continue;
            dfs(dfs, v);
        }
        ok[u] = false;
    };

    dfs(dfs, 0);
    cout << ans << endl;
}
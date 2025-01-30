#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Transitivity
//    https://atcoder.jp/contests/abc292/tasks/abc292_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        vector<bool> ok(N);
        auto dfs = [&](auto dfs, int p) -> void {
            ok[p] = true;
            cnt++;
            for(int c : G[p]) {
                if(ok[c]) continue;
                dfs(dfs, c);
            }
        };
        dfs(dfs, i);
        ans += cnt - (int)G[i].size() - 1;
    }

    cout << ans << endl;
}
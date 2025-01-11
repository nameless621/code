#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    F - Endless Walk
//    https://atcoder.jp/contests/abc245/tasks/abc245_f



int main() {
    int N, M;
    cin >> N >> M;

    scc_graph scc(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        scc.add_edge(U, V);
        G[V].push_back(U);
    }

    auto res = scc.scc();
    
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int p) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) continue;
            dfs(dfs, c);
        }
    };

    for(auto vec : res) {
        if((int)vec.size() < 2) continue;
        for(int num : vec) {
            dfs(dfs, num);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(ok[i]) ans++;
    }

    cout << ans << endl;
}
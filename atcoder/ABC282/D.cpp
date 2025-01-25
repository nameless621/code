#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Make Bipartite 2
//    https://atcoder.jp/contests/abc282/tasks/abc282_d



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

    bool ng = false;
    vector<int> color(N, -1);
    long long cnt[2];
    auto dfs = [&](auto dfs, int u) -> void {
        for(int v : G[u]) {
            if(color[v] != -1) {
                if(color[v] == color[u]) ng = true;
                continue;
            }
            color[v] = color[u] ^ 1;
            cnt[color[v]]++;
            dfs(dfs, v);
        }
    };

    long long ans = (long long)N * (N - 1) / 2 - M;
    int cc = 0;
    for(int i = 0; i < N; i++) {
        if(color[i] != -1) continue;
        cc++;
        color[i] = 0;
        cnt[0] = 1;
        cnt[1] = 0;
        dfs(dfs, i);
        if(ng) {
            cout << 0 << endl;
            return 0;
        }
        ans -= cnt[0] * (cnt[0] - 1) / 2;
        ans -= cnt[1] * (cnt[1] - 1) / 2;
    }

    cout << ans << endl;
}
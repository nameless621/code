#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Hidden Weights
//    https://atcoder.jp/contests/abc373/tasks/abc373_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, -w);
    } 

    long long INF = LLONG_MAX / 2;
    vector<long long> x(N, INF);

    auto dfs = [&](auto dfs, int u) -> void {
        for(auto[v, w] : G[u]) {
            if(x[v] != INF) continue;
            x[v] = x[u] + w;
            dfs(dfs, v);
        }
    };

    for(int i = 0; i < N; i++) {
        if(x[i] != INF) continue;
        x[i] = 0;
        dfs(dfs, i);
    }

    for(int i = 0; i < N; i++) {
        cout << x[i] << (i < N-1 ? " " : "\n");
    }
}
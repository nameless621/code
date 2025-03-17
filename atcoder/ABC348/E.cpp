#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Minimize Sum of Distances
//    https://atcoder.jp/contests/abc348/tasks/abc348_e



long long centroid(auto &g, auto &cost) {
    long long sum = 0;
    int x = -1, n = cost.size();
    for(int i = 0; i < n; i++) sum += cost[i];
    auto dfs = [&](auto dfs, int p, int pre) -> long long {
        long long res = cost[p];
        long long mx = 0;
        for(int c : g[p]) if(c != pre) {
            long long now = dfs(dfs, c, p);
            mx = max(mx, now);
            res += now;
        }
        mx = max(mx, sum - res);
        if(mx * 2 <= sum) x = p;
        return res;
    };
    dfs(dfs, 0, -1);
    return x;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<long long> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    
    int x = centroid(G, C);
    long long ans = 0;
    auto dfs = [&](auto dfs, int u, int pre, int d) -> void {
        ans += C[u] * d;
        for(int v : G[u]) {
            if(v == pre) continue;
            dfs(dfs, v, u, d + 1);
        }
    };

    dfs(dfs, x, -1, 0);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Remembering the Days 
//    https://atcoder.jp/contests/abc317/tasks/abc317_c



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
    }

    int ans = 0;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int u, int sum) -> void {
        ok[u] = true;
        ans = max(ans, sum);
        for(auto[v, cost] : G[u]) {
            if(ok[v]) continue;
            dfs(dfs, v, sum + cost);
        }
        ok[u] = false;
    };

    for(int i = 0; i < N; i++) {
        dfs(dfs, i, 0);
    }

    cout << ans << endl;
}
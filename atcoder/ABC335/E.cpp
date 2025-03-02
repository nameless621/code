#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Non-Decreasing Colorful Path
//    https://atcoder.jp/contests/abc335/tasks/abc335_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<pair<int, int>> Edge;
    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(A[u] == A[v]) uf.merge(u, v);
        Edge.emplace_back(u, v);
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        auto[u, v] = Edge[i];
        u = uf.leader(u);
        v = uf.leader(v);
        if(u == v) continue;
        if(A[u] > A[v]) swap(u, v);
        G[u].push_back(v);
    }

    vector<int> P;
    for(int i = 0; i < N; i++) {
        if(uf.leader(i) == i) {
            P.push_back(i);
        }
    }

    sort(P.begin(), P.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    int INF = -1e9;
    vector<int> dp(N, INF);
    dp[uf.leader(0)] = 1;
    for(int i : P) {
        for(int j : G[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int ans = dp[uf.leader(N-1)];
    if(ans < 0) ans = 0;
    cout << ans << endl;
}
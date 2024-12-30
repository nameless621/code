#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Subtree K-th Max
//    https://atcoder.jp/contests/abc239/tasks/abc239_e



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<vector<int>> res(N);
    for(int i = 0; i < N; i++) res[i].push_back(X[i]);

    vector<bool> visited(N);
    auto dfs = [&](auto dfs, int u) -> void {
        visited[u] = true;
        for(int v : G[u]) {
            if(visited[v]) continue;
            dfs(dfs, v);
            res[u].insert(res[u].end(), res[v].begin(), res[v].end());
        }
        sort(res[u].rbegin(), res[u].rend());
        while((int)res[u].size() > 20) res[u].pop_back();
    };

    dfs(dfs, 0);

    while(Q--) {
        int v, k;
        cin >> v >> k;
        v--; k--;
        cout << res[v][k] << endl;
    }
}
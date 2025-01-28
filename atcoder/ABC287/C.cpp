#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Path Graph?
//    https://atcoder.jp/contests/abc287/tasks/abc287_c



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

    for(int i = 0; i < N; i++) {
        if(G[i].size() < 1 || G[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<bool> ok(N);
    bool flag = false;
    auto dfs = [&](auto dfs, int p, int pre) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(c == pre) continue;
            if(ok[c]) {
                flag = true;
                continue;
            }
            dfs(dfs, c, p);
        }
    };

    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        dfs(dfs, i, -1);
        if(flag) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
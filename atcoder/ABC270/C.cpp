#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Simple path
//    https://atcoder.jp/contests/abc270/tasks/abc270_c



int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<int> ans;
    bool flag = true;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int u) -> void {
        ok[u] = true;
        if(flag) ans.push_back(u);
        if(u == Y) flag = false;
        for(int v : G[u]) {
            if(ok[v]) continue;
            dfs(dfs, v);
        }
        if(flag) ans.pop_back();
    };

    dfs(dfs, X);

    for(int p : ans) cout << p + 1 << " ";
    cout << endl;
}
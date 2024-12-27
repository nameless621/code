#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    G - 連結
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_g



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<set<int>> Graph(N);
    while(Q--) {
        int T, u, v;
        cin >> T >> u >> v;
        u--; v--;
        if(T == 1) {
            if(Graph[u].count(v)) {
                Graph[u].erase(v);
                Graph[v].erase(u);
            }
            else {
                Graph[u].insert(v);
                Graph[v].insert(u);
            }
        }
        if(T == 2) {
            vector<bool> seen(N);
            auto dfs = [&](auto dfs, int p) -> bool {
                seen[p] = true;
                if(p == v) return true;
                for(auto c : Graph[p]) {
                    if(seen[c]) continue;
                    if(dfs(dfs, c)) return true;
                }
                return false;
            };

            cout << (dfs(dfs, u) ? "Yes" : "No") << endl;
        }
    }
}
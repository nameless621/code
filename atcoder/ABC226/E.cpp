#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

//        E - Just one
//        https://atcoder.jp/contests/abc226/tasks/abc226_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graph(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        Graph[U].push_back(V);
        Graph[V].push_back(U);
    }

    mint ans = 1;
    vector<bool> seen(N);
    for(int i = 0; i < N; i++) {
        if(seen[i] == true) continue;

        int node = 0, edge = 0;
        auto dfs = [&](auto dfs, int U) -> void {
            seen[U] = true;
            node++;
            for(int V : Graph[U]) {
                edge++;
                if(seen[V] == true) continue;
                dfs(dfs, V);
            }
        };

        dfs(dfs, i);
        edge /= 2;
        if(edge >= 2 && edge == node) ans *= 2;
        else ans = 0;
    }

    cout << ans.val() << endl;
}
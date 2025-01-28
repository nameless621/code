#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - レ
//    https://atcoder.jp/contests/abc289/tasks/abc289_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int a;
        cin >> a, a--;
        G[a].push_back(a + 1);
    }

    vector<int> ans;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int p) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) continue;
            dfs(dfs, c);
        }
        ans.push_back(p);
    };

    for(int i = 0; i < N; i++) {
        if(!ok[i]) dfs(dfs, i);
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " ";
        if(i == N - 1) cout << endl;
    }
}
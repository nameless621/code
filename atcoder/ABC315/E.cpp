#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Prerequisites
//    https://atcoder.jp/contests/abc315/tasks/abc315_e



int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        int C;
        cin >> C;
        for(int j = 0; j < C; j++) {
            int P;
            cin >> P;
            P--;
            G[i].push_back(P);
        }
    }

    vector<int> ans;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int p) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) continue;
            dfs(dfs, c);
        }
        ans.push_back(p + 1);
    };

    dfs(dfs, 0);
    ans.pop_back();
    for(int num : ans) {
        cout << num << " ";
    }
}
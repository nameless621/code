#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Find it!
//    https://atcoder.jp/contests/abc311/tasks/abc311_c



int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A, A--;
        G[i].push_back(A);
    }

    vector<bool> ok(N);
    vector<int> ans;
    auto dfs = [&](auto dfs, int p) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) {
                if(!ans.size()) {
                    int k = p;
                    do {
                        ans.push_back(k);
                        k = G[k][0];
                    } while(k != p);
                }
                continue;
            }
            dfs(dfs, c);
        }
    };

    for(int i = 0; i < N; i++) {
        if(ok[i] || ans.size()) continue;
        dfs(dfs, i);
    }

    cout << ans.size() << endl;
    for(int num : ans) cout << num + 1 << " ";
}
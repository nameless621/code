#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Ameba
//    https://atcoder.jp/contests/abc274/tasks/abc274_c



int main() {
    int N;
    cin >> N;

    map<int, vector<int>> g;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        g[A].push_back(2*(i+1));
        g[A].push_back(2*(i+1)+1);
    }

    vector<int> ans(2*N+1, -1);
    auto dfs = [&](auto dfs, int now, int d) -> void {
        ans[now-1] = d;
        for(int nex : g[now]) {
            if(ans[nex-1] != -1) continue;
            dfs(dfs, nex, d+1);
        }
    };

    dfs(dfs, 1, 0);
    for(int i = 0; i < 2*N+1; i++) {
        cout << ans[i] << endl;
    }
}
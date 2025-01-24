#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Ladder Takahashi
//    https://atcoder.jp/contests/abc277/tasks/abc277_c



int main() {
    int N;
    cin >> N;
    
    map<int, vector<int>> G;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    set<int> ok;
    int ans = -1;
    auto dfs = [&](auto dfs, int now) -> void {
        ok.insert(now);
        ans = max(ans, now);
        for(int nex : G[now]) {
            if(ok.count(nex)) continue;
            dfs(dfs, nex);
        }
    };

    dfs(dfs, 1);
    cout << ans << endl;
}
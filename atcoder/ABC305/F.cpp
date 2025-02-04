#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Dungeon Explore
//    https://atcoder.jp/contests/abc305/tasks/abc305_f



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> ok(N);
    vector<vector<int>> G(N);

    auto read = [&](int p) {
        int k;
        cin >> k;
        for(int i = 0; i < k; i++) {
            int c;
            cin >> c;
            c--;
            if(!ok[p]) G[p].push_back(c);
        }
    };

    auto dfs = [&](auto dfs, int p) -> bool {
        if(p == N - 1) {
            string S;
            cin >> S;
            return true;
        }
        read(p);
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) continue;
            cout << c + 1 << endl;
            if(dfs(dfs, c)) return true;
            cout << p + 1 << endl;
            read(p);
        }
        return false;
    };

    dfs(dfs, 0);
}
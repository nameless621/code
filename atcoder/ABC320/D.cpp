#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Relative Position
//    https://atcoder.jp/contests/abc320/tasks/abc320_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<tuple<int, long long, long long>>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, X, Y;
        cin >> A >> B >> X >> Y;
        A--; B--;
        G[A].emplace_back(B, X, Y);
        G[B].emplace_back(A, -X, -Y);
    }

    vector<bool> ok(N);
    vector<pair<long long, long long>> pos(N);
    auto dfs = [&](auto dfs, int u, long long posX, long long posY) -> void {
        ok[u] = true;
        pos[u] = {posX, posY};
        for(auto[v, X, Y] : G[u]) {
            if(ok[v]) continue;
            dfs(dfs, v, posX + X, posY + Y);
        }
    };

    dfs(dfs, 0, 0, 0);
    for(int i = 0; i < N; i++) {
        auto[X, Y] = pos[i];
        if(ok[i]) cout << X << " " << Y << endl;
        else cout << "undecidable" << endl;
    }
}
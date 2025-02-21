#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Good Tuple Problem
//    https://atcoder.jp/contests/abc327/tasks/abc327_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);
    for(int i = 0; i < M; i++) cin >> A[i], A[i]--;
    for(int i = 0; i < M; i++) cin >> B[i], B[i]--;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<int> color(N, -1);
    bool ok = true;
    auto dfs = [&](auto dfs, int p) -> void {
        for(int c : G[p]) {
            if(color[c] != -1) {
                if(color[p] == color[c]) ok = false;
                continue;
            }
            color[c] = color[p] ^ 1;
            dfs(dfs, c);
        }
    };

    for(int i = 0; i < N; i++) {
        if(color[i] != -1) continue;
        color[i] = 0;
        dfs(dfs, i);
    }

    cout << (ok ? "Yes" : "No") << endl;
}
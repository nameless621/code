#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Tying Rope
//    https://atcoder.jp/contests/abc293/tasks/abc293_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int A, C;
        char B, D;
        cin >> A >> B >> C >> D;
        A--; C--;
        G[A].push_back(C);
        G[C].push_back(A);
    }

    bool flag = false;
    vector<bool> ok(N);
    auto dfs = [&](auto dfs, int p, int pre) -> void {
        ok[p] = true;
        for(int c : G[p]) {
            if(ok[c]) {
                if(c != pre) flag = true;
                continue;
            }
            dfs(dfs, c, p);
        }
    };

    int X = 0, Y = 0;
    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        flag = false;
        dfs(dfs, i, -1);
        if(flag) X++;
        else Y++;
    }

    cout << X << " " << Y << endl;
}
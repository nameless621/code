#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Takahashi's Anguish
//    https://atcoder.jp/contests/abc256/tasks/abc256_e



int main() {
    int N;
    cin >> N;

    scc_graph g(N);
    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        X--;
        g.add_edge(i, X);
    }

    for(int i = 0; i < N; i++) cin >> C[i];

    long long ans = 0;
    for(auto vec : g.scc()) {
        if((int)vec.size() < 2) continue;
        int res = 1e9;
        for(int idx : vec) {
            res = min(res, C[idx]);
        }
        ans += res;
    }

    cout << ans << endl;
}
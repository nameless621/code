#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Blackout 2
//    https://atcoder.jp/contests/abc264/tasks/abc264_e



int main() {
    int N, M, E;
    cin >> N >> M >> E;

    vector<int> U(E), V(E);
    for(int i = 0; i < E; i++) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
        U[i] = min(U[i], N);
        V[i] = min(V[i], N);
    }

    int Q;
    cin >> Q;
    vector<int> X(Q);
    vector<bool> ng(E);
    for(int i = 0; i < Q; i++) {
        cin >> X[i];
        X[i]--;
        ng[X[i]] = true;
    }

    dsu uf(N+1);
    for(int i = 0; i < E; i++) {
        if(ng[i]) continue;
        uf.merge(U[i], V[i]);
    }

    vector<int> ans(Q);
    for(int i = Q - 1; i >= 0; i--) {
        ans[i] = uf.size(N) - 1;
        uf.merge(U[X[i]], V[X[i]]);
    }

    for(int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}
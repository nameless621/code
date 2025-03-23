#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Clique Connect
//    https://atcoder.jp/contests/abc352/tasks/abc352_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> Edge;
    for(int i = 0; i < M; i++) {
        int K, C;
        cin >> K >> C;
        int u = -1;
        for(int j = 0; j < K; j++) {
            int v;
            cin >> v;
            v--;
            if(u == -1) u = v;
            else Edge.emplace_back(C, u, v);
        }
    }

    sort(Edge.begin(), Edge.end());
    
    dsu uf(N);
    long long ans = 0;
    for(auto[C, u, v] : Edge) {
        if(uf.same(u, v)) continue;
        uf.merge(u, v);
        ans += C;
    }

    if(uf.size(0) == N) cout << ans << endl;
    else cout << -1 << endl;
}
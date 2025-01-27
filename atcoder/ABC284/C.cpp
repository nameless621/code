#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Count Connected Components
//    https://atcoder.jp/contests/abc284/tasks/abc284_c



int main() {
    int N, M;
    cin >> N >> M;

    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.merge(u, v);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(uf.leader(i) == i) ans++;
    }

    cout << ans << endl;
}
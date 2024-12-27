#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - MST + 1
//    https://atcoder.jp/contests/abc235/tasks/abc235_e



using T = tuple<int, int, int, int>;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    priority_queue<T, vector<T>, greater<T>> PQ;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        PQ.emplace(c, a, b, -1);
    }

    for(int i = 0; i < Q; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        PQ.emplace(w, u, v, i);
    }

    vector<bool> result(Q);
    dsu UF(N);
    while(!PQ.empty()) {
        auto[cost, x, y, idx] = PQ.top();
        PQ.pop();
        if(UF.same(x, y)) continue;
        if(idx == -1) UF.merge(x, y);
        else result[idx] = true;
    }

    for(int i = 0; i < Q; i++) {
        cout << (result[i] ? "Yes" : "No") << endl;
    }
}
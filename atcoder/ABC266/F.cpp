#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    F - Well-defined Path Queries on a Namori
//    https://atcoder.jp/contests/abc266/tasks/abc266_f



int main() {
    int N;
    cin >> N;

    vector<int> deg(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    vector<bool> ok(N);
    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(deg[i] == 1) {
            ok[i] = true;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int c : G[p]) {
            if(ok[c]) continue;
            deg[c]--;
            if(deg[c] == 1) {
                ok[c] = true;
                q.push(c);
            }
        }
    }

    dsu uf(N);
    for(int i = 0; i < N; i++) {
        if(!ok[i]) continue;
        for(int j : G[i]) {
            uf.merge(i, j);
        }
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << (uf.same(x, y) ? "Yes" : "No") << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};


//    E - Isolation
//    https://atcoder.jp/contests/abc302/tasks/abc302_e



int main() {
    int N, Q;
    cin >> N >> Q;

    int cnt = N;
    vector<set<int>> G(N);
    while(Q--) {
        int T, u, v;
        cin >> T;
        if(T == 1) {
            cin >> u >> v;
            u--; v--;
            if((int)G[u].size() == 0) cnt--;
            if((int)G[v].size() == 0) cnt--;
            G[u].insert(v);
            G[v].insert(u);
        }
        if(T == 2) {
            cin >> u;
            u--;
            if((int)G[u].size() != 0) cnt++;
            for(int k : G[u]) {
                G[k].erase(u);
                if((int)G[k].size() == 0) cnt++;
            }
            G[u].clear();
        }
        cout << cnt << endl;
    }
}
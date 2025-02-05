#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Family and Insurance
//    https://atcoder.jp/contests/abc309/tasks/abc309_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int p;
        cin >> p, p--;
        G[p].push_back(i);
    }

    vector<int> d(N, -1);
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        d[x] = max(d[x], y);
    }

    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int c : G[p]) {
            if(d[c] < d[p] - 1) d[c] = d[p] - 1;
            q.push(c);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(d[i] >= 0) ans++;
    }

    cout << ans << endl;
}
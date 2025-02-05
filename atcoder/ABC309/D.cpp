#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Add One Edge
//    https://atcoder.jp/contests/abc309/tasks/abc309_d



int main() {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;

    vector<vector<int>> G(N1 + N2);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto bfs = [&](int st) {
        vector<int> dist(N1 + N2, -1);
        dist[st] = 0;
        queue<int> q;
        q.push(st);
        while(!q.empty()) {
            int p = q.front();
            q.pop();
            for(int c : G[p]) {
                if(dist[c] != -1) continue;
                dist[c] = dist[p] + 1;
                q.push(c);
            }
        }
        return *max_element(dist.begin(), dist.end());
    };

    int d1 = bfs(0);
    int d2 = bfs(N1 + N2 - 1);

    cout << d1 + d2 + 1 << endl;
}
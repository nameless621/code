#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Crystal Switches 
//    https://atcoder.jp/contests/abc277/tasks/abc277_e



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        G[u].emplace_back(v, a);
        G[v].emplace_back(u, a);
    }

    set<int> s;
    for(int i = 0; i < K; i++) {
        int p;
        cin >> p;
        s.insert(p - 1);
    }

    int INF = INT_MAX / 2;
    vector<vector<int>> dist(N, vector<int>(2, INF));
    dist[0][1] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 1);
    while(!q.empty()) {
        auto[u, T1] = q.front();
        q.pop();
        for(auto[v, T2] : G[u]) {
            if(T1 != T2 && !s.count(u)) continue;
            if(dist[v][T2] != INF) continue;
            dist[v][T2] = dist[u][T1] + 1;
            q.emplace(v, T2);
        }
    } 

    int ans = min(dist[N-1][0], dist[N-1][1]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
}
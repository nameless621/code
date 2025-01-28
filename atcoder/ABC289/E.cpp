#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Swap Places
//    https://atcoder.jp/contests/abc289/tasks/abc289_e



void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<int>> dist(N, vector<int>(N, -1));
    dist[0][N - 1] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, N - 1);
    while(!q.empty()) {
        auto[x1, x2] = q.front();
        q.pop();
        for(int y1 : G[x1]) {
            for(int y2 : G[x2]) {
                if(C[y1] == C[y2]) continue;
                if(dist[y1][y2] != -1) continue;
                dist[y1][y2] = dist[x1][x2] + 1;
                q.emplace(y1, y2);
            }
        }   
    }

    cout << dist[N - 1][0] << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}
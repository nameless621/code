#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    K - ガソリンスタンド
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_k



int main() {
    int N, M, Q, K;
    cin >> N >> M >> Q >> K;
    
    vector<int> A(K);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int INF = INT_MAX / 2;
    vector<vector<int>> dist(K, vector<int>(N, INF));
    for(int i = 0; i < K; i++) {
        dist[i][A[i]] = 0;
        queue<int> q;
        q.push(A[i]);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : G[u]) {
                if(dist[i][v] != INF) continue;
                dist[i][v] = dist[i][u] + 1;
                q.push(v);
            }
        }
    }

    while(Q--) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        int res = INF;
        for(int i = 0; i < K; i++) {
            res = min(res, dist[i][s] + dist[i][t]);
        }
        cout << res << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Small d and k
//    https://atcoder.jp/contests/abc254/tasks/abc254_e



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> dist(N, vector<int>(4));
    for(int i = 0; i < N; i++) {
        queue<pair<int, int>> q;
        q.emplace(i, 0);
        set<int> ok;
        ok.insert(i);
        while(!q.empty()) {
            auto[p, k] = q.front();
            q.pop();
            if(k > 3) continue;
            dist[i][k] += p + 1;
            for(int c : G[p]) {
                if(ok.count(c)) continue;
                ok.insert(c);
                q.emplace(c, k+1);
            }
        }
        
        for(int j = 0; j < 3; j++) {
            dist[i][j+1] += dist[i][j];
        }
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int x, k;
        cin >> x >> k;
        x--;
        cout << dist[x][k] << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Nearest Black Vertex
//    https://atcoder.jp/contests/abc299/tasks/abc299_e



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

    int K;
    cin >> K;

    if(K == 0) {
        cout << "Yes" << endl;
        cout << string(N, '1') << endl;
        return 0;
    }

    vector<pair<int, int>> P(K);
    for(int i = 0; i < K; i++) {
        cin >> P[i].first >> P[i].second;
        P[i].first--;
    }

    vector<int> col(N);
    vector<vector<int>> s(K), t(K);
    for(int i = 0; i < K; i++) {
        auto[idx, d] = P[i];
        vector<int> dist(N, -1);
        dist[idx] = 0;
        queue<int> q;
        q.push(idx);
        while(!q.empty()) {
            int p = q.front(); q.pop();
            if(dist[p] == d) {
                col[p] = 1;
                t[i].push_back(p);
                continue;
            }
            else s[i].push_back(p);
            for(int c : G[p]) {
                if(dist[c] != -1) continue;
                dist[c] = dist[p] + 1;
                q.push(c);
            }
        }
    }

    for(int i = 0; i < K; i++) {
        for(int j : s[i]) col[j] = 0;
    }

    bool ok = true;
    for(int i = 0; i < K; i++) {
        bool flag = false;
        for(int j : t[i]) {
            if(col[j]) flag = true;
        }
        if(!flag) ok = false;
    }

    if(ok) {
        cout << "Yes" << endl;
        for(int i = 0; i < N; i++) {
            cout << col[i];
        }
        cout << endl;
    }
    else {
        cout << "No" << endl;
    }
}
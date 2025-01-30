#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Teleporter and Closed off
//    https://atcoder.jp/contests/abc291/tasks/abc291_f



vector<int> bfs(int N, int st, vector<vector<int>> G) {
    vector<int> dist(N, -1);
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
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<vector<int>> G1(N);
    vector<vector<int>> G2(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(S[i][j] == '0') continue;
            G1[i].push_back(i + j + 1);
            G2[i + j + 1].push_back(i);
        }
    }

    auto s0 = bfs(N, 0, G1);
    auto sN = bfs(N, N-1, G2);

    for(int i = 1; i < N - 1; i++) {
        int res = -1;
        for(int j = max(0, i - M); j < i; j++) {
            if(s0[j] == -1) continue;
            for(int k : G1[j]) {
                if(sN[k] == -1 || k <= i) continue;
                int dist = s0[j] + sN[k] + 1;
                res = (res == -1 ? dist : min(res, dist));
            }
        }
        cout << res << " ";
    }
    cout << endl;
}
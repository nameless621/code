#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};


//    F - Merge Set
//    https://atcoder.jp/contests/abc302/tasks/abc302_f



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(M + N);
    vector<vector<int>> S(N);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        S[i].resize(A);
        for(int j = 0; j < A; j++) {
            cin >> S[i][j];
            S[i][j]--;
            G[S[i][j]].push_back(M + i);
            G[M + i].push_back(S[i][j]);
        }
    }

    vector<int> dist(M + N, -1);
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (int)S[i].size(); j++) {
            if(S[i][j] == 0) {
                q.emplace(M + i, 0);
                dist[M + i] = 0;
                break;
            }
        }
    }

    while(!q.empty()) {
        auto[p, t] = q.front();
        q.pop();
        for(int c : G[p]) {
            if(dist[c] != -1) continue;
            dist[c] = dist[p] + t;
            q.emplace(c, (t ^ 1));
        }
    }

    cout << dist[M-1] << endl;
}
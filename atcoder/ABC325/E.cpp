#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Our clients, please wait a moment
//    https://atcoder.jp/contests/abc325/tasks/abc325_e



using T = tuple<long long, int, int>;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<vector<pair<int, long long>>> G(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int D;
            cin >> D;
            if(i == j) continue;
            G[i].emplace_back(j, D);
            G[j].emplace_back(i, D);
        }
    }

    long long INF = LLONG_MAX / 2;
    vector<vector<long long>> dist(N, vector<long long>(2, INF));
    dist[0][0] = 0;
    priority_queue<T, vector<T>, greater<T>> q;
    q.emplace(0, 0, 0);
    while(!q.empty()) {
        auto[d, i, t] = q.top();
        q.pop();
        if(dist[i][t] != d) continue;
        for(auto[j, cost] : G[i]) {
            if(t == 0) {
                long long sum = d + cost * A;
                if(dist[j][t] > sum) {
                    dist[j][t] = sum;
                    q.emplace(sum, j, t);
                }
            }
            long long sum = d + cost * B + C;
            int nt = (t == 0 ? 1 : 1);
            if(dist[j][nt] > sum) {
                dist[j][nt] = sum;
                q.emplace(sum, j, nt);
            }
        }
    }

    cout << min(dist[N-1][0], dist[N-1][1]) << endl;
}
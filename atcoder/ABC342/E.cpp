#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Last Train
//    https://atcoder.jp/contests/abc342/tasks/abc342_e



using ll = long long;
using T = tuple<ll, ll, ll, ll, int>;
using P = pair<ll, int>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<T>> G(N);
    for(int i = 0; i < M; i++) {
        int l, d, k, c, A, B;
        cin >> l >> d >> k >> c >> A >> B;
        A--; B--;
        G[B].emplace_back(l, d, k, c, A);
    }

    long long INF = 9e18;
    vector<long long> dist(N, -INF);
    dist[N-1] = INF;
    priority_queue<P> q;
    q.emplace(INF, N-1);
    while(!q.empty()) {
        auto[sum, u] = q.top();
        q.pop();
        if(dist[u] != sum) continue;
        for(auto[l, d, k, c, v] : G[u]) {
            long long t = sum - c;
            if(l > t) continue;
            long long nk = (t - l) / d;
            nk = min(nk, k-1);
            long long nex = l + d * nk;
            if(dist[v] >= nex) continue;
            dist[v] = nex;
            q.emplace(nex, v);
        }
    }

    for(int i = 0; i < N-1; i++) {
        if(dist[i] != -INF) cout << dist[i] << endl;
        else cout << "Unreachable" << endl;
    }
}
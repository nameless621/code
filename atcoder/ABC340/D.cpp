#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Super Takahashi Bros.
//    https://atcoder.jp/contests/abc340/tasks/abc340_d



using P = pair<long long, int>;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N-1; i++) {
        int A, B, X;
        cin >> A >> B >> X;
        X--;
        G[i].emplace_back(i+1, A);
        G[i].emplace_back(X, B);
    }

    long long INF = 1e18;
    vector<long long> dist(N, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, 0);
    while(!q.empty()) {
        auto[d, p] = q.top();
        q.pop();
        if(dist[p] != d) continue;
        for(auto[c, cost] : G[p]) {
            long long sum = d + cost;
            if(dist[c] <= sum) continue;
            dist[c] = sum;
            q.emplace(sum, c);
        }
    }

    cout << dist[N-1] << endl;
}
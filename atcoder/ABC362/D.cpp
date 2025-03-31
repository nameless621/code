#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Shortest Path 3 
//    https://atcoder.jp/contests/abc362/tasks/abc362_d



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for(int& a : A) cin >> a;

    using P = pair<long long, long long>;
    vector<vector<P>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, B;
        cin >> U >> V >> B;
        U--; V--;
        G[U].emplace_back(V, B);
        G[V].emplace_back(U, B);
    }

    long long INF = LLONG_MAX / 2;
    vector<long long> dist(N, INF);
    dist[0] = A[0];
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(A[0], 0);
    while(!pq.empty()) {
        auto[d, p] = pq.top();
        pq.pop();
        if(dist[p] != d) continue;
        for(auto[c, cost] : G[p]) {
            long long sum = d + cost + A[c];
            if(dist[c] <= sum) continue;
            dist[c] = sum;
            pq.emplace(sum, c);
        }
    }

    for(int i = 1; i < N; i++) {
        cout << dist[i] << (i < N-1 ? " " : "\n");
    }
}
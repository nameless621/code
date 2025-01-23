#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Subsequence Path
//    https://atcoder.jp/contests/abc271/tasks/abc271_e



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<tuple<int, int, int>> R;
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        R.emplace_back(A, B, C);
    }

    vector<int> E(K);
    for(int i = 0; i < K; i++) {
        cin >> E[i];
        E[i]--;
    }

    long long INF = LLONG_MAX / 2;
    vector<long long> dist(N, INF);
    dist[0] = 0;
    for(int i = 0; i < K; i++) {
        auto[A, B, C] = R[E[i]];
        if(dist[A] == INF) continue;
        dist[B] = min(dist[B], dist[A] + C);
    }

    cout << (dist[N-1] != INF ? dist[N-1] : -1) << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Road Reduction
//    https://atcoder.jp/contests/abc252/tasks/abc252_e



using T = tuple<long long, long long, int>;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<T>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        G[A].emplace_back(B, C, i + 1);
        G[B].emplace_back(A, C, i + 1);
    }

    vector<int> ans;
    long long INF = LLONG_MAX;
    vector<long long> dist(N, INF);
    dist[0] = 0;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 0, -1);
    while(!pq.empty()) {
        auto[d, A, i] = pq.top();
        pq.pop();
        if(dist[A] != d) continue;
        ans.push_back(i);
        for(auto[B, C, idx] : G[A]) {
            long long sum = d + C;
            if(dist[B] <= sum) continue;
            dist[B] = sum;
            pq.emplace(sum, B, idx);
        }
    }

    for(int i = 1; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

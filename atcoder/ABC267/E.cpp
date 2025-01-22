#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Erasing Vertices 2 
//    https://atcoder.jp/contests/abc267/tasks/abc267_e



using P = pair<long long, int>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    priority_queue<P, vector<P>, greater<P>> q;
    vector<long long> sum(N);
    for(int i = 0; i < N; i++) {
        for(int j : G[i]) sum[i] += A[j];
        q.emplace(sum[i], i);
    }

    long long ans = 0;
    vector<bool> ok(N);
    while(!q.empty()) {
        auto[cost, i] = q.top();
        q.pop();
        if(ok[i]) continue;
        ans = max(ans, cost);
        ok[i] = true;
        for(int j : G[i]) {
            if(ok[j]) continue;
            sum[j] -= A[i];
            q.emplace(sum[j], j);
        }
    }

    cout << ans << endl;
}
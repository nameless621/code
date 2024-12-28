#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Skiing
//    https://atcoder.jp/contests/abc237/tasks/abc237_e



using P = pair<long long, long long>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    long long INF = 1e18;
    vector<long long> res(N, INF);
    res[0] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, 0);
    while(!q.empty()) {
        auto[dist, x] = q.top();
        q.pop();
        if(res[x] != dist) continue;
        for(int y : G[x]) {
            long long sum = dist + max(0, H[y] - H[x]);
            if(res[y] <= sum) continue;
            res[y] = sum;
            q.emplace(sum, y);
        }
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, H[0] - H[i] - res[i]);
    }

    cout << ans << endl;
}
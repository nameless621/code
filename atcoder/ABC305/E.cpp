#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Art Gallery on Graph 
//    https://atcoder.jp/contests/abc305/tasks/abc305_e



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ok(N, -1);
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < K; i++) {
        int p, h;
        cin >> p >> h;
        p--;
        ok[p] = h;
        q.emplace(h, p);
    }

    while(!q.empty()) {
        auto[h, p] = q.top();
        q.pop();
        if(ok[p] != h) continue;
        for(int c : G[p]) {
            if(ok[c] >= h - 1) continue;
            ok[c] = h - 1;
            q.emplace(h - 1, c);
        }
    }

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(ok[i] != -1) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for(int num : ans) cout << num << " ";
    cout << endl;
}
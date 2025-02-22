#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Modulo MST
//    https://atcoder.jp/contests/abc328/tasks/abc328_e



vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    auto dfs = [&](auto dfs, int now) -> void {
        if((int)temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for(int i = now; i < n; i++) {
            temp.push_back(i);
            dfs(dfs, i+1);
            temp.pop_back();
        }
    };
    dfs(dfs, 0);
    return res;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<tuple<int, int, long long>> Edge;
    for(int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        Edge.emplace_back(u, v, w);
    }

    auto res = combinations(M, N-1);
    long long ans = K;
    for(auto vec : res) {
        dsu d(N);
        long long sum = 0;
        for(int idx : vec) {
            auto[u, v, w] = Edge[idx];
            d.merge(u, v);
            sum = (sum + w) % K;
        }
        if(d.size(0) == N) ans = min(ans, sum);
    }

    cout << ans << endl;
}
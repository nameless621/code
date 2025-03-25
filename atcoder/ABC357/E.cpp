#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Reachability in Functional Graph
//    https://atcoder.jp/contests/abc357/tasks/abc357_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N), deg(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i], A[i]--;
        G[A[i]].push_back(i);
        deg[A[i]]++;
    }

    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(!deg[i]) q.push(i);
    }

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        deg[A[p]]--;
        if(!deg[A[p]]) q.push(A[p]);
    }

    vector<int> res(N, -1);
    for(int i = 0; i < N; i++) {
        if(deg[i] && res[i] == -1) {
            int now = i, cnt = 0;
            do {
                cnt++;
                now = A[now];
            } while(now != i);
            do {
                res[now] = cnt;
                now = A[now];
            } while(now != i);
        }
    }

    auto dfs = [&](auto dfs, int p) -> void {
        for(int c : G[p]) {
            if(res[c] != -1) continue;
            res[c] = res[p] + 1;
            dfs(dfs, c);
        }
    };

    for(int i = 0; i < N; i++) {
        if(res[i] == -1) continue;
        dfs(dfs, i);
    }

    long long ans = accumulate(res.begin(), res.end(), 0ll);
    cout << ans << endl;
}
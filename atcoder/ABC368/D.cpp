#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Minimum Steiner Tree
//    https://atcoder.jp/contests/abc368/tasks/abc368_d



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> deg(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
        deg[A]++;
        deg[B]++;
    }

    vector<bool> OK(N, true);
    for(int i = 0; i < K; i++) {
        int V;
        cin >> V;
        V--;
        OK[V] = false;
    }

    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(deg[i] == 1 && OK[i]) {
            q.push(i);
        }
    }

    int ans = N;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans--;
        for(int v : G[u]) {
            deg[v]--;
            if(deg[v] == 1 && OK[v]) {
                q.push(v);
            }
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Tree and Hamilton Path 2
//    https://atcoder.jp/contests/abc361/tasks/abc361_e



vector<long long> BFS(auto& G, int st) {
    int N = G.size();
    vector<long long> ret(N, -1);
    ret[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int u = q.top();
        p.pop();
        for(auto[v, cost] : G[u]) {
            if(ret[v] != -1) continue;
            ret[v] = ret[u] + cost;
            q.push(v);
        }
    }

    return ret;
}

int main() {
    int N;
    cin >> N;

    long long sum = 0;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N-1; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        sum += C * 2;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
    }

    auto res1 = BFS(G, 0);
    int x = max_element(res1.begin(), res1.end()) - res1.begin();
    auto res2 = BFS(G, x);
    cout << sum - *max_element(res2.begin(), res2.end()) << endl;
}
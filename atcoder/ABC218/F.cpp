#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Blocked Roads
//    https://atcoder.jp/contests/abc218/tasks/abc218_f



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> s(M), t(M);
    map<pair<int, int>, int> e;
    vector<multiset<int>> G(N);
    vector<multiset<int>> H(N);
    for(int i = 0; i < M; i++) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
        G[s[i]].insert(t[i]);
        H[t[i]].insert(s[i]);
        e[{s[i], t[i]}] = i;
    }

    vector<int> dist(N, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int c : G[p]) {
            if(dist[c] != -1) continue;
            dist[c] = dist[p] + 1;
            q.push(c);
        }
    }

    if(dist[N-1] == -1) {
        for(int i = 0; i < M; i++) {
            cout << -1 << endl;
        }
        return 0;
    }

    set<int> used;
    int now = N-1;
    while(now != 0) {
        used.insert(now);
        for(int nex : H[now]) {
            if(dist[nex]+1 != dist[now]) continue;
            used.insert(e[{nex, now}]);
            now = nex;
            break;
        }
    }

    auto bfs = [&]() {
        vector<int> res(N, -1);
        res[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int p = q.front();
            q.pop();
            for(int c : G[p]) {
                if(res[c] != -1) continue;
                res[c] = res[p] + 1;
                q.push(c);
            }
        }
        return res[N-1];
    };

    for(int i = 0; i < M; i++) {
        if(used.count(i)) {
            G[s[i]].erase(G[s[i]].find(t[i]));
            int res = bfs();
            cout << res << endl;
            G[s[i]].insert(t[i]);
        }
        else {
            cout << dist[N-1] << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    J - 終わりなき旅
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_j



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> deg(N);
    vector<vector<int>> Graph(N);
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        Graph[x].push_back(y);
        deg[y]++;
    }

    queue<int> Q;
    for(int i = 0; i < N; i++) {
        if(deg[i] == 0) {
            Q.push(i);
        }
    }

    while(!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for(int c : Graph[p]) {
            deg[c]--;
            if(deg[c] == 0) {
                Q.push(c);
            }
        }
    }

    bool ok = false;
    for(int i = 0; i < N; i++) {
        if(deg[i] > 0) ok = true;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
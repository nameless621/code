#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Find Permutation
//    https://atcoder.jp/contests/abc291/tasks/abc291_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> deg(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        G[X].push_back(Y);
        deg[Y]++;
    }

    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(!deg[i]) q.push(i);
    }

    if((int)q.size() > 1) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> ans(N);
    int num = 1;
    while(!q.empty()) {
        int X = q.front();
        q.pop();
        ans[X] = num;
        num++;
        for(int Y : G[X]) {
            deg[Y]--;
            if(!deg[Y]) q.push(Y);
        }
        if((int)q.size() > 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Virus
//    https://atcoder.jp/contests/abc304/tasks/abc304_c



int main() {
    int N, D;
    cin >> N >> D;

    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<bool> ok(N);
    ok[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for(int j = 0; j < N; j++) {
            if(ok[j]) continue;
            int x = X[i] - X[j];
            int y = Y[i] - Y[j];
            if(x*x + y*y > D*D) continue;
            ok[j] = true;
            q.push(j);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << (ok[i] ? "Yes" : "No") << endl;
    }
}
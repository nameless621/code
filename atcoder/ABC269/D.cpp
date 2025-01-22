#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Do use hexagon grid
//    https://atcoder.jp/contests/abc269/tasks/abc269_d



int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int dx[] = {-1, -1, 0, 0, 1, 1};
    int dy[] = {-1, 0, -1, 1, 0, 1};
    dsu uf(N);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = 0; k < 6; k++) {
                int nx = X[i] + dx[k];
                int ny = Y[i] + dy[k];
                if(nx == X[j] && ny == Y[j]) {
                    uf.merge(i, j);
                }
            }
        }
    }

    vector<bool> ok(N);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(ok[uf.leader(i)]) continue;
        ok[uf.leader(i)] = true;
        ans++;
    }

    cout << ans << endl;
}
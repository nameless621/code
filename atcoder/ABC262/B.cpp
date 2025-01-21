#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Triangle (Easier)
//    https://atcoder.jp/contests/abc254/tasks/abc262_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(N));
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        G[U][V] = G[V][U] = true;
    }

    int ans = 0;
    for(int a = 0; a < N; a++) {
        for(int b = a + 1; b < N; b++) {
            for(int c = b + 1; c < N; c++) {
                if(G[a][b] && G[b][c] && G[c][a]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}